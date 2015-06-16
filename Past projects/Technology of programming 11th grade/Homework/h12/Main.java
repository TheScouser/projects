package org.elsys.example1.code;

import java.util.Random;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		AirPlane plane = new AirPlane();
		int group;
		while(plane.free_seats() != 0){
			group = (int) new Random().nextInt(3) + 1;
			for(int i = 0; i < group; i++) {
				if(group == 1){
					Human a = new Human();	
					plane.add(group, a);
				}else {
					if(group == 2) {
						Human a = new Human();
						Human b = new Human();
						plane.add(group, a, b);
					}else{
						Human a = new Human();
						Human b = new Human();
						Human c = new Human();
						plane.add(group, a, b, c);
					}
				}
			}
		}
		
		System.out.println("Number of males - " + plane.getMales());
		System.out.println("Number of females - " + plane.getFemales());
		plane.clear();
		Human h = new Human();
		h.setName("REtard");
		h.setGender("Man");
		plane.add(1,h);
		plane.remove(h);
		System.out.println("Number of males - " + plane.getMales());
		System.out.println("Number of females - " + plane.getFemales());
	}
	

}
