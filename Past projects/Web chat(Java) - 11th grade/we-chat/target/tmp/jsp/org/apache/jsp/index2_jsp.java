package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class index2_jsp extends org.apache.jasper.runtime.HttpJspBase
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

      out.write("<script src=\"javascript/atmosphere.js\"></script>\r\n");
      out.write("<script src=\"http://spyboost.github.io/angular-atmosphere/service/angular-atmosphere-service.js\"></script>\r\n");
      out.write("<html>\r\n");
      out.write("<head>\r\n");
      out.write("  <meta charset=\"utf-8\">\r\n");
      out.write("  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\r\n");
      out.write("  <title>Atmosphere Chat AngularJS</title>\r\n");
      out.write("  <link rel=\"stylesheet\" href=\"http://netdna.bootstrapcdn.com/bootstrap/3.0.0/css/bootstrap.min.css\"/>\r\n");
      out.write("  <link rel=\"stylesheet\" href=\"css/chat.css\" />\r\n");
      out.write("  <script src=\"//ajax.googleapis.com/ajax/libs/jquery/2.0.3/jquery.min.js\"></script>\r\n");
      out.write("  <script src=\"//netdna.bootstrapcdn.com/bootstrap/3.0.0/js/bootstrap.min.js\"></script>\r\n");
      out.write("  \r\n");
      out.write("  <script src=\"//ajax.googleapis.com/ajax/libs/angularjs/1.0.7/angular.min.js\"></script>\r\n");
      out.write("  <script src=\"//spyboost.github.io/angular-atmosphere/service/angular-atmosphere-service.js\"></script>\r\n");
      out.write("  <script src=\"javascript/application.js\"></script>\r\n");
      out.write("</head>\r\n");
      out.write("<body data-ng-app=\"angular.atmosphere.chat\" data-ng-controller=\"ChatController\">\r\n");
      out.write("<div id=\"header\">\r\n");
      out.write("  <h3 data-ng-bind=\"model.header\" data-ng-init=\"model.header='Atmosphere Chat. Default transport is WebSocket, fallback is long-polling'\"></h3>\r\n");
      out.write("</div>\r\n");
      out.write("<p data-ng-show=\"!model.connected\">Connecting...</p>\r\n");
      out.write("<p>{{model.content}}</p>\r\n");
      out.write("<div class=\"container\">\r\n");
      out.write("  <div class=\"row\">\r\n");
      out.write("    <div class=\"panel panel-default\">\r\n");
      out.write("      <div class=\"panel-heading\">\r\n");
      out.write("        <h3 class=\"panel-title\">Chat room</h3>\r\n");
      out.write("      </div>\r\n");
      out.write("      <div class=\"panel-body\">\r\n");
      out.write("        <div class=\"messages\">\r\n");
      out.write("          <p data-ng-repeat=\"message in model.messages\">\r\n");
      out.write("            <span class=\"time\">{{message.date | date:'shortDate'}} {{message.date|date:'shortTime'}}</span>\r\n");
      out.write("            <span class=\"author\">{{message.author}}</span> :\r\n");
      out.write("            <span class=\"text\">{{message.text}}</span>\r\n");
      out.write("          </p>\r\n");
      out.write("        </div>\r\n");
      out.write("      </div>\r\n");
      out.write("    </div>\r\n");
      out.write("  </div>\r\n");
      out.write("  <span data-ng-show=\"!model.name\">Enter your name:</span>\r\n");
      out.write("  <div data-ng-show=\"model.logged\">\r\n");
      out.write("    <span><b>{{model.name}}</b> says:</span>\r\n");
      out.write("  </div>\r\n");
      out.write("  <form role=\"form\" class=\"form-horizontal\">\r\n");
      out.write("    <div class=\"form-group\">\r\n");
      out.write("      <div class=\"col-lg-9\">\r\n");
      out.write("        <input type=\"text\" class=\"form-control\" id=\"input\" data-ng-disabled=\"!model.connected\" x-webkit-speech/>\r\n");
      out.write("      </div>\r\n");
      out.write("    </div>\r\n");
      out.write("  </form>\r\n");
      out.write("</div>\r\n");
      out.write("</body>\r\n");
      out.write("</html>");
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
