package org.elsys.BallsContainer.code;

import java.util.ArrayList;


public class BallContainer {
	int capacity = 10;
	private ArrayList<Ball> myBalls = new ArrayList<Ball>(capacity);
	
	public void add(Ball myBall){
		if(myBalls.size() != capacity) {
			if(!myBalls.contains(myBall)){
				myBalls.add(myBall);
			} else {
				System.out.println("This ball is already in the box");
			}
		} else {
			System.out.println("The box is full");
		}
	}
	
	public void remove(Ball myBall){
		if(!myBalls.isEmpty()){
		myBalls.remove(myBalls.indexOf(myBall));
		}
		else{
			System.out.println("The box is empty");
		}
	}

	public int getCapacity(){
		return capacity;
	}
	
	public int size() {
		return capacity -  myBalls.size();
	}
	
	public void clear(){
		myBalls.clear();
	}
	
	public void contains(Ball myBall){
		if(myBalls.contains(myBall) == true){
			System.out.println("The box contains this ball!");
		}
		else{
			System.out.println("The box does not contain this ball!");
		}
	}

	public void print() {
		for(Ball p:myBalls) {
			System.out.println(p.getName());
		}
	}
}
