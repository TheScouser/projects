package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class register_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static final JspFactory _jspxFactory = JspFactory.getDefaultFactory();

  private static java.util.List<String> _jspx_dependants;

  private org.glassfish.jsp.api.ResourceInjector _jspx_resourceInjector;

  public java.util.List<String> getDependants() {
    return _jspx_dependants;
  }

  public void _jspService(HttpServletRequest request, HttpServletResponse response)
        throws java.io.IOException, ServletException {

    PageContext pageContext = null;
    HttpSession session = null;
    ServletContext application = null;
    ServletConfig config = null;
    JspWriter out = null;
    Object page = this;
    JspWriter _jspx_out = null;
    PageContext _jspx_page_context = null;

    try {
      response.setContentType("text/html");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;
      _jspx_resourceInjector = (org.glassfish.jsp.api.ResourceInjector) application.getAttribute("com.sun.appserv.jsp.resource.injector");

      out.write("\r\n");
      out.write("<!DOCTYPE html>\r\n");
      out.write("<!--[if lt IE 7]>      <html class=\"no-js lt-ie9 lt-ie8 lt-ie7\"> <![endif]-->\r\n");
      out.write("<!--[if IE 7]>         <html class=\"no-js lt-ie9 lt-ie8\"> <![endif]-->\r\n");
      out.write("<!--[if IE 8]>         <html class=\"no-js lt-ie9\"> <![endif]-->\r\n");
      out.write("<!--[if gt IE 8]><!--> <html class=\"no-js\"> <!--<![endif]-->\r\n");
      out.write("\t<head>\r\n");
      out.write("\t\t<meta charset=\"utf-8\">\r\n");
      out.write("\t\t<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\r\n");
      out.write("\t\t<title></title>\r\n");
      out.write("\t\t<meta name=\"description\" content=\"\">\r\n");
      out.write("\t\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\r\n");
      out.write("\r\n");
      out.write("\t\t<!-- Place favicon.ico and apple-touch-icon.png in the root directory -->\r\n");
      out.write("\r\n");
      out.write("\t\t<link rel=\"stylesheet\" href=\"css/normalize.css\">\r\n");
      out.write("\t\t<link rel=\"stylesheet\" href=\"css/grid.css\">\r\n");
      out.write("\t\t<link rel=\"stylesheet\" href=\"css/xavStyles.css\">\r\n");
      out.write("\t\t<link rel=\"stylesheet\" href=\"css/main.css\">\r\n");
      out.write("\t\t<script src=\"js/vendor/modernizr-2.6.2.min.js\"></script>\r\n");
      out.write("\t</head>\r\n");
      out.write("\t<body>\r\n");
      out.write("\t\t<!--[if lt IE 7]>\r\n");
      out.write("\t\t\t<p class=\"browsehappy\">You are using an <strong>outdated</strong> browser. Please <a href=\"http://browsehappy.com/\">upgrade your browser</a> to improve your experience.</p>\r\n");
      out.write("\t\t<![endif]-->\r\n");
      out.write("\r\n");
      out.write("\t\t<!-- WeChat Home Page Slider \r\n");
      out.write("\t\t  ================================= -->\r\n");
      out.write("\t\t<header id=\"site-header\" class=\"clearfix titlebar\">\r\n");
      out.write("\t\t\t<div class=\"container\">\r\n");
      out.write("\t\t\t\t<h1 class=\"site-logo pull-left\"><a href=\"#\">WeChat</a></h1>\r\n");
      out.write("\t\t\t\t<nav class=\"primary-navigation pull-right\">\r\n");
      out.write("\t\t\t\t\t<ul>\r\n");
      out.write("\t\t\t\t\t\t<li><a href=\"#\">Home</a></li>\r\n");
      out.write("\t\t\t\t\t\t<li><a href=\"#\">Contact us</a></li>\r\n");
      out.write("\t\t\t\t\t\t<li><a href=\"#\">Create chat room</a></li>\r\n");
      out.write("\t\t\t\t\t\t<li><a href=\"#\">Members</a></li>\r\n");
      out.write("\t\t\t\t\t\t<li><a href=\"#\">About</a></li>\r\n");
      out.write("\t\t\t\t\t</ul>\r\n");
      out.write("\t\t\t\t</nav>\r\n");
      out.write("\t\t\t</div><!-- /container -->\r\n");
      out.write("\r\n");
      out.write("\t\t\t<div class=\"site-titlebar\">\r\n");
      out.write("\t\t\t\t<div class=\"container\">\r\n");
      out.write("\t\t\t\t\t<h3 class=\"create-user\">Not logged in</h3>\r\n");
      out.write("\t\t\t\t</div>\r\n");
      out.write("\t\t\t</div><!-- /site-titlebar -->\r\n");
      out.write("\r\n");
      out.write("\t\t</header>\r\n");
      out.write("\t\t\r\n");
      out.write("\t\t<!-- Main Content \r\n");
      out.write("\t\t  ================================= -->\r\n");
      out.write("\t\t<div id=\"site-content\" role=\"main\">\r\n");
      out.write("\t\t\t<div class=\"container\">\r\n");
      out.write("\t\t\t<form class='register-form pull-left' action=\"registration.do\" method=\"post\">\r\n");
      out.write("\t\t\t\t<h1>Create New Account</h1>\r\n");
      out.write("\t\t\t\t<br>\r\n");
      out.write("\t\t\t\t<p>Some awesome message for the users about the registration proccess.</p>\r\n");
      out.write("\t\t\t\t\r\n");
      out.write("\t\t\t\t<p>\r\n");
      out.write("\t\t\t\t\t<label for=\"fname\">First name</label>\r\n");
      out.write("\t\t\t\t\t<input name=\"fname\" type=\"text\" placeholder=\"Your first name\">\r\n");
      out.write("\t\t\t\t\t");
      out.write((java.lang.String) org.apache.jasper.runtime.PageContextImpl.evaluateExpression("${invalid_username}", java.lang.String.class, (PageContext)_jspx_page_context, null));
      out.write("\r\n");
      out.write("\t\t\t\t\t\r\n");
      out.write("\t\t\t\t</p>\r\n");
      out.write("\t\t\t\t\r\n");
      out.write("\t\t\t\t<p>\r\n");
      out.write("\t\t\t\t\t<label for=\"lname\">Last name</label>\r\n");
      out.write("\t\t\t\t\t<input name=\"lname\" type=\"text\" placeholder=\"Your last name\">\r\n");
      out.write("\t\t\t\t</p>\r\n");
      out.write("\t\t\t\t\r\n");
      out.write("\t\t\t\t<p>\r\n");
      out.write("\t\t\t\t\t<label for=\"uname\">Username</label>\r\n");
      out.write("\t\t\t\t\t<input name=\"uname\" type=\"text\" placeholder=\"Your username\">\r\n");
      out.write("\t\t\t\t</p>\r\n");
      out.write("\t\t\t\t<p>\r\n");
      out.write("\t\t\t\t\t<label for=\"pass\">Password</label>\r\n");
      out.write("\t\t\t\t\t<input name=\"pass\" type=\"password\" placeholder=\"Your password\">\r\n");
      out.write("\t\t\t\t</p>\r\n");
      out.write("\t\t\t\t<p>\r\n");
      out.write("\t\t\t\t\t<label for=\"email\">Email</label>\r\n");
      out.write("\t\t\t\t\t<input name=\"email\" type=\"text\" placeholder=\"Your username\">\r\n");
      out.write("\t\t\t\t\t<label for=\"email\">");
      out.write((java.lang.String) org.apache.jasper.runtime.PageContextImpl.evaluateExpression("${invalid_mail}", java.lang.String.class, (PageContext)_jspx_page_context, null));
      out.write("</label>\r\n");
      out.write("\t\t\t\t\t\r\n");
      out.write("\t\t\t\t</p>\r\n");
      out.write("\t\t\t\t<input  class=\"btn register green medium\" type=\"submit\" value=\"Register\">\r\n");
      out.write("\t\t\t\r\n");
      out.write("\t\t\t</form>\r\n");
      out.write("\t\t\t<img class='pull-right' src=\"img/map.png\" alt=\"\">\r\n");
      out.write("\r\n");
      out.write("\t\t\t</div>\r\n");
      out.write("\t\t</div><!-- /site-content -->\r\n");
      out.write("\r\n");
      out.write("\t\t<!-- Footer area\r\n");
      out.write("\t\t  ================================= -->\r\n");
      out.write("\t\t<footer id=\"site-footer\">\r\n");
      out.write("\t\t\t<div class=\"container\">\r\n");
      out.write("\t\t\t\t<p>Developed by Alex Dimitrov and Dimitar Borisov</p>\r\n");
      out.write("\t\t\t</div>\r\n");
      out.write("\t\t</footer>\r\n");
      out.write("\r\n");
      out.write("\t\t<!-- Scripts initialization -->\r\n");
      out.write("\t\t<script src=\"http://ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js\">\r\n");
      out.write("\t\t<script>window.jQuery || document.write('<script src=\"js/vendor/jquery-1.10.2.min.js\"><\\/script>')</script>\r\n");
      out.write("\t\t<script src=\"js/plugins.js\"></script>\r\n");
      out.write("\t\t<script src=\"js/main.js\"></script>\r\n");
      out.write("\t</body>\t\r\n");
      out.write("</html>\r\n");
    } catch (Throwable t) {
      if (!(t instanceof SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          out.clearBuffer();
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
