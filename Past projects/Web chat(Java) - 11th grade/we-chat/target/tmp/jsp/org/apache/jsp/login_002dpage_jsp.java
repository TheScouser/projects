package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class login_002dpage_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      response.setContentType("text/html;charset=UTF-8");
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
      out.write("<html>\r\n");
      out.write("    <head>\r\n");
      out.write("        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\r\n");
      out.write("        <title>JSP Example</title>\r\n");
      out.write("    </head>\r\n");
      out.write("    <body>\r\n");
      out.write("        <form method=\"post\" action=\"login.jsp\">\r\n");
      out.write("            <center>\r\n");
      out.write("            <table border=\"1\" width=\"30%\" cellpadding=\"3\">\r\n");
      out.write("                <thead>\r\n");
      out.write("                    <tr>\r\n");
      out.write("                        <th colspan=\"2\">Login Here</th>\r\n");
      out.write("                    </tr>\r\n");
      out.write("                </thead>\r\n");
      out.write("                <tbody>\r\n");
      out.write("                    <tr>\r\n");
      out.write("                        <td>User Name</td>\r\n");
      out.write("                        <td><input type=\"text\" name=\"uname\" value=\"\" /></td>\r\n");
      out.write("                    </tr>\r\n");
      out.write("                    <tr>\r\n");
      out.write("                        <td>Password</td>\r\n");
      out.write("                        <td><input type=\"password\" name=\"pass\" value=\"\" /></td>\r\n");
      out.write("                    </tr>\r\n");
      out.write("                    <tr>\r\n");
      out.write("                        <td><input type=\"submit\" value=\"Login\" /></td>\r\n");
      out.write("                        <td><input type=\"reset\" value=\"Reset\" /></td>\r\n");
      out.write("                    </tr>\r\n");
      out.write("                    <tr>\r\n");
      out.write("                        <td colspan=\"2\">Yet Not Registered!! <a href=\"reg-page.jsp\">Register Here</a></td>\r\n");
      out.write("                    </tr>\r\n");
      out.write("                </tbody>\r\n");
      out.write("            </table>\r\n");
      out.write("            </center>\r\n");
      out.write("        </form>\r\n");
      out.write("    </body>\r\n");
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
