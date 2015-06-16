package com.wordpress.ekalfov.code;


import java.io.BufferedReader;

import java.io.InputStreamReader;
import java.net.URL;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Page {
	String url;
	Link[] lik = new Link[5000];
void linkScan(String strTemp){
		int i = 0;
		Pattern linkPattern = Pattern.compile("\\(?\\b(http://|([a-z]).{3}[.])[-A-Za-z0-9+&@#/%?=~_()|!:,.;]*[-A-Za-z0-9+&@#/%=~_()|]",  Pattern.CASE_INSENSITIVE|Pattern.DOTALL);
		 Matcher pageMatcher = linkPattern.matcher(strTemp);
		 for(int j = 0 ;j < 5000;j++){
			 lik[j] = new Link();
		 }
		 while(pageMatcher.find()){
			  lik[i].setValue(pageMatcher.group());
			  i++;
		 }
		 int u = 0;
		 while(lik[u].getValue() != null){
			 System.out.println(lik[u].getValue());
			 u++;
		 }
}
	void setUrl(String url){
		this.url = url;
	}

void content(){
	String strTemp = "";
	 try {
		 	URL my_url = new URL(url);
            BufferedReader br = new BufferedReader(new InputStreamReader(my_url.openStream()));
            
	        while(null != (strTemp = br.readLine())){
	        	
	        	System.out.println(strTemp);
	        }
	        
        } catch (Exception ex) {
            ex.printStackTrace();
        }
	
}


}