// Училище: ТУЕС ( http://www.elsys-bg.org/ )
// Клас: 11 Б
// Номер: 16
// Име:  Едуард Федев Калфов

/*Задача: "Да се създаде програма, която да запълва празните места в самолет,
        като х да е в интервала 1<=х<=3 (пътниците). Всяка група пътници не треябва да са
        разделени от пътеката, или реда. Пример : 100 000 (да), 122 000 (да) ,133 300 (не), 223 330 (не), 221 333 (да)." */

import java.util.Random;

public class AirPlane{
		private int[][] seats = new int[6][27];

		public void add(int rvalue){
			boolean check = false;							//pubic void add(human h)
															//public void remove(human h )
															//public void clear()
															//public int getCapacity()
															//private string gender;
															//public int getMales()
															//public int getFemales()
			for (int j=0;j<27 ;j++ ) {
				for (int i = 0;i < 6 ;i++) {
					if (rvalue==1){
						if (seats[i][j] == 0 ) {
							seats[i][j] = 1;
							check = true;
							break;
						}
					}
					else if (i==6) {
						break;
					}
				
					if (rvalue==2){
						if (i+1==6) {
							continue;
						}

						else if ((seats[i][j] == 0) &&  (seats[i+1][j] == 0) && (i!=2)) {
							seats[i][j] = 2;
							seats[i+1][j] = 2;
							check = true;
							break;
						}
				}
					
				

				if (rvalue==3){
					if (i+2>=6) {
						continue;
					}
					else if ((seats[i][j] == 0) &&  (seats[i+1][j] == 0) && (seats[i+2][j] == 0) && (i!=1) && (i!=2) ) {
						seats[i][j] = 3;
						seats[i+1][j] = 3;
						seats[i+2][j] = 3;
						check = true;
						break;
					}
				}
									

			}
			if(check == true) break;
		}
		}	
		public int free_seats(){
			int count=0;
			for (int j=0;j<27 ;j++ ) {
				for (int i = 0;i < 6 ;i++) {
					if (seats[i][j]==0) {
						count += 1;	
					}

				}
			
			}
			return count;
		}
		public void printSeats(){
	 		for (int i = 0;i < 27 ;i++) {
				for (int j = 0;j < 6 ;j++ ) {
	 	 			System.out.print(seats[j][i]);
	 	 			if(j==2) System.out.print(" ");
	 	 		}
	 	 	System.out.println("");
	 	 	} 
		}
	 public static void main(String[] args) {
	 	
	 	//PRINTING Seats
	 	AirPlane plane = new AirPlane();
	 	plane.printSeats();
	 	 //GENRATING NUMBERS
	 	int total = 0;
	 	int i =0;
	 	System.out.println(plane.free_seats());
		for (;plane.free_seats() > 0 ;i++ ) {
			
			int rvalue = new Random().nextInt(3)+1;
			if(plane.free_seats()<=162){
				plane.add(rvalue);
				
			}
		}
			
			System.out.println("######");
			plane.printSeats();	
			System.out.println(plane.free_seats());
			
			
		
			
			
	}




}