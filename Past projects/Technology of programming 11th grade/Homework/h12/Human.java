package org.elsys.example1.code;
import java.util.*;
public class Human {
	String[] names = {"Georgi","Ivan","Dragan","Borislava","Daniela","Ivanina"};
	String[] genders = {"Man","Woman"};
	
	private int rName = new Random().nextInt(6);
	
{
	if(rName<3){ 
		setGender("Man");
		
	}
	else {
		setGender("Woman");
	}
}	
	private String name = names[rName];
	private String gender;
	
	public void setGender(String gender){
		this.gender = gender;
	}
	public void setName(String name){
		this.name = name;
	}
	
	public String getName(){
		return name;
	}
	public String getGender(){
		return gender;
	}

	
}
