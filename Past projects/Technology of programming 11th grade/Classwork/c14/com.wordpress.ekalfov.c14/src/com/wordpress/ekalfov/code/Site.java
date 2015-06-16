package com.wordpress.ekalfov.code;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;

public class Site {
	String url;
	Page pages[];
	
	
	 
	public String getUrl() {
		return url;
	}

	public void setUrl(String url) {
		this.url = url;
	}

	public void getPages(){
		try {
			 
			URL google = new URL(url);
			int pageCounter = 0;
			URLConnection yc = google.openConnection();
			BufferedReader in = new BufferedReader(new InputStreamReader(yc
					.getInputStream()));
			String inputLine;
			while ((inputLine = in.readLine()) != null) {
				if(inputLine.toLowerCase().contains("a href".toLowerCase())){
					pageCounter++;
				}
			}
			in.close();
			System.out.println("The number of pages is " + pageCounter);
		} catch (Exception e) {
			e.printStackTrace();
		}		
	}

	public void getSertificate(){
		if(url.toLowerCase().contains("http://".toLowerCase())){
			System.out.println("The sertificate is http://");
		}else if(url.toLowerCase().contains("https://".toLowerCase())){
			System.out.println("The sertificate is https://");
		}else{
			System.out.println("Not a valid sertificate or you are drunk!");
		}
	}
	
}
