import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class ChatRoomController extends HttpServlet {

	@Override
	protected void doPost(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {

		String name = (String) request.getParameter("name");
		String description = (String) request.getParameter("description");

		try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager
					.getConnection("jdbc:mysql://localhost/wechat?"
							+ "user=root&password=");
			HttpSession session = request.getSession();

			Statement st = con.createStatement();
			String uname = (String) session.getAttribute("userid");

			ResultSet rs;

			rs = st.executeQuery("select id from users where '" + uname
					+ "' = users.username ");
			rs.next();
			String userid = rs.getString(1);
			System.out.println(userid);
			st = con.createStatement();
			st.execute("insert into chatroom(name,creator_id) values ('" + name
					+ "'," + userid + " )");

			response.sendRedirect("chat_rooms.jsp");
		} catch (Exception ex) {
			System.out.println(ex);
		}
	}

	protected void doGet(HttpServletRequest request,
			HttpServletResponse response) {
		
		String table_chatroom = "";
		try {
			Class.forName("com.mysql.jdbc.Driver");

			Connection con = DriverManager
					.getConnection("jdbc:mysql://localhost/wechat?"
							+ "user=root&password=");

			Statement st = con.createStatement();
			ResultSet rs;
			int i = 1;
			st = con.createStatement();
			rs = st.executeQuery("select * from chatroom inner join users on users.id = chatroom.creator_id  ;");
			while (rs.next()) {
				
				String name = rs.getString(2);
				String username = rs.getString(8);
				table_chatroom += " </tr> <tr class=''> <th> " + i++ +" </th> <th><a href=\" \\chat \">" + name + " </a></th> <th><a href=\"#\"> "+ username + " </a></th> </tr>" ;
			}
						
			request.setAttribute("chatrooms", table_chatroom);
		    request.getRequestDispatcher("chat_rooms.jsp").forward(request, response);
			

		} catch (Exception ex) {
			System.out.println(ex);
		}

	}
}
