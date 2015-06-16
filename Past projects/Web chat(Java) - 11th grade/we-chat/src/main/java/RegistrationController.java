import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class RegistrationController extends HttpServlet {


	private static final long serialVersionUID = 1L;
	private boolean cantRegisterName = false;
	@Override
	protected void doPost(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {

		String user = request.getParameter("uname");
		String pwd = request.getParameter("pass");
		String fname = request.getParameter("fname");
		String lname = request.getParameter("lname");
		String email = request.getParameter("email");
		ResultSet rs = null;
		try {
			Class.forName("com.mysql.jdbc.Driver");

			Connection con = DriverManager
					.getConnection("jdbc:mysql://localhost/wechat?"
							+ "user=root&password=");

			Statement st = con.createStatement();
			rs = st.executeQuery("select username from users");
			while(rs.next()){
				String name = rs.getString(1);
				if (name.equals(user)){
					System.out.println("Username already in use.");
					
					request.setAttribute("invalid_username", "Username already in use");
				    request.getRequestDispatcher("register.jsp").forward(request, response);
				    response.sendRedirect("register.jsp");
					
				}
			}
			
			
			
			st = con.createStatement();
			rs = st.executeQuery("select email from users");
			while(rs.next()){
				String mail = rs.getString(1);
				if (mail.equals(email)){
					System.out.println("E-mail already in use.");
					request.setAttribute("invalid_mail", "E-mail already in use");
				    request.getRequestDispatcher("register.jsp").forward(request, response);
				    response.sendRedirect("register.jsp");
				}
			}
			
			
			 st = con.createStatement();
			boolean i = st
					.execute("insert into users(first_name, last_name, email, username, pass, regdate) values ('"
							+ fname
							+ "','"
							+ lname
							+ "','"
							+ email
							+ "','"
							+ user + "','" + pwd + "', NOW())");
			if (!i) {
				HttpSession session = request.getSession();
				session.setAttribute("userid", user);
				
				response.sendRedirect("chat_rooms.jsp");
				System.out.println("Registration Successfull! "
						+ email);
			} else {
				//RequestDispatcher rd = getServletContext().getRequestDispatcher("/reg-page.jsp");
	            // PrintWriter out= response.getWriter();
	            //out.println("<font color=red>Something went wrong.</font>");
	            //rd.include(request, response);
			}

		} catch (ClassNotFoundException | SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
