package org.elsys.example1.code;

// Училище: ТУЕС ( http://www.elsys-bg.org/ )
// Клас: 11 Б
// Номер: 16
// Име:  Едуард Федев Калфов

/*Задача: "Да се създаде програма, която да запълва празните места в самолет,
 като х да е в интервала 1<=х<=3 (пътниците). Всяка група пътници не треябва да са
 разделени от пътеката, или реда. Пример : 100 000 (да), 122 000 (да) ,133 300 (не), 223 330 (не), 221 333 (да)." */



public class AirPlane {
	private Human[][] seats = new Human[6][27];
	private boolean check;
	

	public void add(int rvalue,Human a) {
		check = false;
		for (int j = 0; j < 27; j++) {
			for (int i = 0; i < 6; i++) {
				if (rvalue == 1 && check == false ) {
					if (seats[i][j] == null) {
						seats[i][j] = a;
						check = true;
						break;
					}
				} else if (i == 6) {
					break;
				}
			}
		}
	}
	public void add(int rvalue,Human a,Human b){
	check = false;
	for (int j = 0; j < 27; j++) {
		for (int i = 0; i < 6; i++) {	
	
		if (rvalue == 2) {
					if (i + 1 == 6) {
						continue;
					}

					else if ((seats[i][j] == null) && (seats[i + 1][j] == null)
							&& (i != 2) && check == false) {
						seats[i][j] = a;
						seats[i + 1][j] = b;
						check = true;
						break;
					}
				}
		}
	}
	}
				
	public void add(int rvalue,Human a,Human b,Human c){
		check = false;
		for (int j = 0; j < 27; j++) {
			for (int i = 0; i < 6; i++) {
		if (rvalue == 3) {
					if (i + 2 >= 6) {
						continue;
					} else if ((seats[i][j] == null) && (seats[i + 1][j] == null)
							&& (seats[i + 2][j] == null) && (i != 1) && (i != 2) && check == false) {
						seats[i][j] = a;
						seats[i + 1][j] = b;
						seats[i + 2][j] = c;
						check = true;
						break;
					}
				}

			}
			if (check == true)
				break;
		}
	}

	public int free_seats() {
		int count = 0;
		for (int j = 0; j < 27; j++) {
			for (int i = 0; i < 6; i++) {
				if (seats[i][j] == null) {
					count += 1;
				}

			}

		}
		return count;
	}

	public void printSeats() {
		for (int i = 0; i < 27; i++) {
			for (int j = 0; j < 6; j++) {
				System.out.print(seats[j][i].getName());
				if (j == 2)
					System.out.print(" ");
			}
			System.out.println("");
		}
	}



	public int getMales(){
		int males = 0;
		for (Human[] i:seats) {
			for (Human j:i) {
				if(j != null){
				if(j.getGender() == "Man"){
					males++;
				}
				}
			
			}
			
		}
		return males;
	}
	
	public int getFemales(){
		int females = 0;
		for (Human[] i:seats) {
			for (Human j:i) {
				if(j != null){
				if(j.getGender() == "Woman"){
					females++;
				}
				}
			
			}
			
		}
		return females;
	}
	
	public void remove(Human a){
		boolean removed = false;
		for (int i = 0; i < 27; i++) {
			for (int j = 0; j < 6; j++) {
				if(seats[j][i] != null ){
					if(seats[j][i].getName() == a.getName() && removed == false ){
						seats[j][i] = null;
						removed = true;
					}
				}
			}
			
		}
		if (removed == false){
			System.out.println("Shit!This is Jason Bourne");
		}
	}
	
	public void clear(){
		for (int i = 0; i < 27; i++) {
			for (int j = 0; j < 6; j++) {
				if(seats[j][i] != null ){
					
						seats[j][i] = null;
						
					}
				}
			}
			
	}
}
