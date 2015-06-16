// Училище: ТУЕС ( http://www.elsys-bg.org/ )
// Клас: 11 Б
// Номер: 16
// Име:  Едуард Федев Калфов

/*Задача: "Да се създаде програма, която да изкарва на екрана стойността на системните свойства по
зададени от командния ред имена на свойствата. Програмата трябва да приема и
невалидни имена. Ако последния подаден аргумент от командния ред е up то стойностите
показани в изхода трябва да са сортиран във възходящ ред. Ако последната стойност е
down изходът трябва да е сортиран в низходящ ред. Стойността по подразбиране, ако не е
посочено up или down, е up" */

import java.util.Arrays;
import java.util.Collections;

public class Homework5{
	public static void main(String[] args){
		String[] arr=new String[args.length];

		
			for(int i = 0; i < args.length; i++){
				if(System.getProperty (args[i])==null) {
					arr[i]="Invalid";
					continue;
				}
				arr[i] = System.getProperty(args[i]);
			}
		
		if(args[(args.length)-1].equals("down")){
			Arrays.sort(arr,Collections.reverseOrder());
		}
		else{
			Arrays.sort(arr); 
		}
			for (int i=0;i<arr.length;i++){
				if(arr[i].equals("Invalid")){
					continue;
				}
				System.out.println(" " + arr[i]);
		}
	}


}