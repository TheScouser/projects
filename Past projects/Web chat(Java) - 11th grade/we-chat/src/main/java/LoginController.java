import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;


public class LoginController extends HttpServlet{

	
	private static final long serialVersionUID = 1L;

	@Override
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		
		String userid = request.getParameter("uname");
		String pwd = request.getParameter("pass");

		try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager
					.getConnection("jdbc:mysql://localhost/wechat?"
							+ "user=root&password=");

			Statement st = con.createStatement();
			ResultSet rs;
			rs = st.executeQuery("select * from users where username='"
					+ userid + "' and pass='" + pwd + "'");
			if (rs.next()) {
				HttpSession session = request.getSession();
				
				session.setAttribute("userid", userid);
				//out.println("welcome " + userid);
				//out.println("<a href='logout.jsp'>Log out</a>");
				System.out.println(userid + " logged in!");
				response.sendRedirect("/chatroomRegister.do");
			} else {
				System.out.println("Invalid password <a href='index.jsp'>try again</a>");
			}
		} catch (Exception ex) {
			System.out.println("There was an error with the server");
		}
		
	}

}
