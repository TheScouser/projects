package com.wordpress.ekalfov.code;




public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Site webSite = new Site();
    	Page webPage = new Page();
    	Link webLink = new Link();
    	webSite.setUrl("http://www.google.bg");
    	webLink.download(); 
    	webPage.setUrl("http://www.google.bg");
    	webPage.content();
    	webSite.getPages();
	}

}
