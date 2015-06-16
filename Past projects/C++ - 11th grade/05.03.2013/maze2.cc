#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

enum Direction {
	NONE = 0,
	UP = 1,
	LEFT = 1<<1,
	DOWN = 1<<2,
	RIGHT = 1<<3
};

class Cell {
	unsigned char walls_;
	int row_;
	int col_;
	bool visited_;
public:
	Cell(unsigned char walls = 
		static_cast<unsigned char>(UP|LEFT|DOWN|RIGHT))
	: walls_(walls),
	  row_(-1),
	  col_(-1),
	  visited_(false)
	{}
	
	void clear(){
	walls_ = 	static_cast<unsigned char>(UP|LEFT|DOWN|RIGHT);
	visited_=false;
	}

	void clear_visited(){
		visited_=false;
	}


	bool isVisited() const{
		return visited_;
	}

	Cell& setVisited() {
		visited_= true;
		return *this;
	}

	Cell& setWall(Direction dir) {
		
		walls_ = dir | walls_;
		
		return *this;
	}

	Cell& unsetWall(Direction dir){
		walls_= ~ dir & walls_;
		return *this;
	}

	
	bool hasWall(Direction dir) const{
		
		return (walls_ & dir) != 0; 
	}
	
	Cell& setCoords(int row, int col){
		row_ = row;
		col_ = col;
		return *this;
	}
	
	int getRow() const{
		return row_;
	}
	
	int getCol() const{
		return col_;
	}
};

class BoardError{};

class Board{
	Cell *cells_;
	int nrows_;
	int ncols_;
	
	bool checkBoardCoords(int row, int col) const{
		if(row>=0 && row < nrows_ && col >= 0 && col < ncols_){
			return true;
		}
		return false;
	}
	
public:
	Board(int nrows, int ncols)
	: cells_(new Cell [nrows*ncols]),
	  nrows_(nrows),
	  ncols_(ncols)
	  {
		  for(int i = 0; i<nrows_;i++){
			  for(int j = 0; j<ncols_; j++){
				  getCell(i,j).setCoords(i,j);
			  }
		  }
	 }
	  
	 ~Board(){
	 	delete[] cells_;
	 }

	Cell& getCell(int row, int col){
	  if(!checkBoardCoords(row,col)){
		  throw BoardError();
	  }
	  int cell_index = row*ncols_ + col;
	  return cells_[cell_index];
	}

	const Cell& getCell(int row, int col) const{
	  if(!checkBoardCoords(row,col)){
		  throw BoardError();
	  }
	  int cell_index = row*ncols_ + col;
	  return cells_[cell_index];
	}


private:
	const static Direction DIRECTIONS[];



public:

	bool hasUnvisitedNeighbour(Cell& cell) {
		for (int i = 0; i < 4; i++)
		{
			Direction dir = DIRECTIONS[i];
			if(hasNeighbour(cell,dir)){
				if(!getNeighbour(cell,dir).isVisited()){
					return true;
				}

			}
		}

		return false;
	}

	bool hasUnvisitedNeighbourWithNoWall(Cell& cell){
		for (int i = 0; i < 4; i++){
			Direction dir = DIRECTIONS[i];
			if(hasNeighbour(cell,dir)){
					
	 
					// if(dir==UP){
					// 	if(!getNeighbour(cell,dir).isVisited() && !getNeighbour(cell,dir).hasWall(DOWN) ){
					// 	return true;
					// }
					// }
					
					// if(dir==DOWN){
					// 	if(!getNeighbour(cell,dir).isVisited() && !getNeighbour(cell,dir).hasWall(UP) ){
					// 	return true;
					// }
					// }
					
					// if(dir==LEFT){
					// 	if(!getNeighbour(cell,dir).isVisited() && !getNeighbour(cell,dir).hasWall(RIGHT) ){
					// 	return true;
					// }
					// }
					
					// if(dir==RIGHT){
					// 	if(!getNeighbour(cell,dir).isVisited() && !getNeighbour(cell,dir).hasWall(LEFT) ){
					// 	return true;
					// }
					// }
			}
		}

		return false;
	}
	




	Direction getRandomUnvisitedNeighbourWithNoWall(Cell& cell){
		if(!hasUnvisitedNeighbourWithNoWall(cell)){
			return NONE;
		} else{
			while(true){
				int randIndex = rand()%4;
				Direction randDir = DIRECTIONS[randIndex];
				if(hasNeighbourWithNoWall(cell,randDir)){
					if(!getNeighbour(cell,randDir).isVisited()){
						return randDir;
					}
				}
			}
		}

	}
	

	Direction getRandomUnvisitedNeighbour(Cell& cell){
		if(!hasUnvisitedNeighbour(cell)){
			return NONE;
		} else{
			while(true){
				int randIndex = rand()%4;
				Direction randDir = DIRECTIONS[randIndex];
				if(hasNeighbour(cell,randDir)){
					if(!getNeighbour(cell,randDir).isVisited()){
						return randDir;
					}
				}
			}
		}
	}

	
	Cell& drill(Cell& cell,Direction dir){
		cell.unsetWall(dir);
		Cell& next = getNeighbour(cell,dir);
		switch(dir){
			case UP:
			next.unsetWall(DOWN);
			break;

			case DOWN:
			next.unsetWall(UP);
			break;

			case LEFT:
			next.unsetWall(RIGHT);
			break;

			case RIGHT:
			next.unsetWall(LEFT);
			break;

			default:
			throw BoardError();
		}
		return next;
	}

	void generate(Cell& start){
		start.setVisited();
	while(true)	
	{
		Direction dir = getRandomUnvisitedNeighbour(start);
		if(dir == NONE){
			return;
		}

		Cell& next = drill(start,dir);
		generate(next);
	}
	
	}

	bool hasNeighbour(const Cell& cell, Direction dir) const{
		if(cell.getRow() == 0 && (dir&UP)) return false;
		if(cell.getRow() == (nrows_-1) && (dir&DOWN)) return false;
		if(cell.getCol() == 0 && (dir&LEFT)) return false;
		if(cell.getCol() == (ncols_-1) && (dir&RIGHT)) return false;
		return true;		
	}

	bool hasNeighbourWithNoWall(const Cell& cell, Direction dir) const{
		if(cell.getRow() == 0 && (dir&UP) && cell.hasWall(DOWN)) return false;
		if(cell.getRow() == (nrows_-1) && (dir&DOWN) && cell.hasWall(UP)) return false;
		if(cell.getCol() == 0 && (dir&LEFT) && cell.hasWall(RIGHT)) return false;
		if(cell.getCol() == (ncols_-1) && (dir&RIGHT) && cell.hasWall(LEFT)) return false;
		return true;		
	}
	
	Cell& getNeighbour(const Cell& cell, Direction dir){
		int row = cell.getRow();
		int col = cell.getCol();

		if((dir&UP)) row-=1;
		if((dir&DOWN)) row+=1;
		if((dir&LEFT)) col-=1;
		if((dir&RIGHT)) col+=1;
		
		return getCell(row,col);
	}
	
	const static int DRAW_PS = 25;
	
	void draw_ps(ostream& out){
		out << "newpath" << endl;
		for(int i = 0;i<nrows_;i++){
			for(int j=0; j<ncols_;j++){
				Cell c = getCell(i,j);
				
				int x = j*DRAW_PS+2*DRAW_PS;
				int y = (nrows_-i)*DRAW_PS+3*DRAW_PS;
				
				out << x << " " << y << " moveto" << endl;
				out << DRAW_PS << " 0 ";
				if(c.hasWall(UP)){
					out << "rlineto" << endl;
				} else {
					out << "rmoveto" << endl;
				}
				
				out << "0 " << -DRAW_PS << " ";
				if(c.hasWall(RIGHT)){
					out << "rlineto" << endl;
				} else {
					out << "rmoveto" << endl;
				}
				
				out << -DRAW_PS << " 0 ";
				if(c.hasWall(DOWN)) {
					out << "rlineto" << endl;
				} else {
					out << "rmoveto" << endl;
				}
				
				out << "0 " << DRAW_PS << " ";
				if(c.hasWall(LEFT)) {
					out << "rlineto" << endl;
				} else {
					out << "rmoveto" << endl;
				}
			}
		}
		//Metod drill koito probiva steni(probivat se dve steni!!!)
		
		out << "stroke" << endl;
	}
	//save funkciq koqto zapazva labirinta
	//load funkciq koqto zarejda sushtiq labirint i moje da se izpolzva

	void mark_ps(ostream& out, const Cell& cell){
		int x = cell.getCol()*DRAW_PS + 2*DRAW_PS;
		int y = cell.getRow()*DRAW_PS + 3*DRAW_PS;

		out << x+ DRAW_PS/2 << " " << y+DRAW_PS/2 << " " << "5 " << "0 " << "360 " << "arc " << "closepath"<<endl;



		out << "stroke" << endl;

	}

	void close_ps(ostream& out) {
		out << "showpage" << endl;
	}

	
	void find_path(Cell& start,Cell& end){

		 start.setVisited();
		 while(true){
		
		Direction dir = getRandomUnvisitedNeighbourWithNoWall(start);
		if(dir == NONE){
			return;
		}

		 Cell& next = getNeighbour(start,dir);
		 
		  if((next.getRow() != end.getRow())  &&  (next.getCol() != end.getCol() ) ){
		  	find_path(next,end);		
		  }
		  else{
		  	mark_ps(cout,next);
		  }
	}
}


void save(Board *b){
	 ofstream myFile ("data",  ios::out | ios::binary);
	 myFile.write ((char*)b, sizeof (Board));

	 myFile.close();
}

void load(Board *b){

	ifstream myFile ("data", ios::in | ios::binary);
	// myFile.seekg (0);
    myFile.read ((char*)b, sizeof (Board) * 10);

    myFile.close();
}


void clear_visited_all(){
		 for(int i = 0; i<nrows_;i++){
			  for(int j = 0; j<ncols_; j++){
				  getCell(i,j).clear_visited();
			  }
		  }
	}


	
};

const Direction Board::DIRECTIONS[] = {UP,DOWN,LEFT,RIGHT};


int main() {
	/*Cell c;
	c.setWall(UP);
	c.setWall(DOWN);
	
	cout << c.hasWall(UP) << endl;
	cout << c.hasWall(LEFT) << endl;
	
	Board b(5,10);
	const Cell& c1 = b.getCell(0,0); 
	cout << b.hasNeighbour(c1,UP) << endl;
	cout << b.hasNeighbour(c1,RIGHT) << endl;
	
	Cell cn=b.getNeighbour(c1,RIGHT);
	cout << cn.getRow() << " " << cn.getCol() << endl;
	
	//b.getNeighbour(c1,UP); */
	Board *bs = new Board(20,20);
	
	Board b(20,20);
	Board *bs2 = new Board(20,20);
	
	  Cell& start = b.getCell(0,4);
	  Cell& end = b.getCell(15,15);
	  b.generate(start);
	//  //Cell& nc = b.drill(c,UP);
	//  // Cell& nc1 = b.drill(nc,RIGHT);

	// // b.draw_ps(cout);
	// // //b.mark_ps(cout,start);
	 b.save(bs);
	//  b.clear_visited_all();
	//    b.find_path(start,end);
	 bs2->load(bs);
	bs2->draw_ps(cout);
	  bs2->close_ps(cout);
	
	return 0;
}

//Da namerim put
//Da namerim nai-kratiq put ot tochka A do tochka B