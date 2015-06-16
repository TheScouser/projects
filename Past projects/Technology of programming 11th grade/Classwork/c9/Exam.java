// Училище: ТУЕС ( http://www.elsys-bg.org/ )
// Клас: 11 Б
// Номер: 16
// Име:  Едуард Федев Калфов

//Задача: Програма,която чете .csv файлове и сумира дадена колона. 


import java.io.*;

public class Exam{
	public static void main(String[] args) {
		String fileName = null;
		if (args.length > 0){
			fileName = args[0];
		}
		else {
			System.out.println("Wrong filename!");
			return;
		}
		try{
			BufferedReader reader = new BufferedReader(new FileReader(fileName));
			String line;
			int sum = 0;
			while((line = reader.readLine())!= null){
				System.out.println(line.split(",")[1]);
				sum += Integer.parseInt(line.split(",")[1]);
			}
			System.out.println(sum);
		 }catch(Exception e){}
	}




}