package com.wordpress.ekalfov.code;

import java.io.*;

import java.net.URL;
import java.util.Scanner;

public class Link {
	String value;
	
	String getValue(){
		return value;
	}
	void setValue(String value){
		this.value = value;
	}
	
	void download(){
		String strTemp = "";
		String HTMLPage = "";
		 try {
			 Scanner userInput = new Scanner(System.in);
		    	String webSiteUrl;
		    	webSiteUrl = userInput.next();
		    	
			 	FileWriter fstream = new FileWriter("out.html");
			 	BufferedWriter out = new BufferedWriter(fstream);
	            URL my_url = new URL(webSiteUrl);
	            BufferedReader br = new BufferedReader(new InputStreamReader(my_url.openStream()));
	            userInput.close();
		        while(null != (strTemp = br.readLine())){
		        	out.write(strTemp);
		        	HTMLPage += strTemp;
		        }
		        out.close();
	        } catch (Exception ex) {
	            ex.printStackTrace();
	        }
		Page page = new Page();
		page.linkScan(HTMLPage);
	}
	
	
	}
	

	

