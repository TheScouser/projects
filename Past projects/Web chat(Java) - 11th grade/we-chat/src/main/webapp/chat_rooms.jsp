
<!DOCTYPE html>
<!--[if lt IE 7]>      <html class="no-js lt-ie9 lt-ie8 lt-ie7"> <![endif]-->
<!--[if IE 7]>         <html class="no-js lt-ie9 lt-ie8"> <![endif]-->
<!--[if IE 8]>         <html class="no-js lt-ie9"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js"> <!--<![endif]-->
	<head>
		<meta charset="utf-8">
		<meta http-equiv="X-UA-Compatible" content="IE=edge">
		<title></title>
		<meta name="description" content="">
		<meta name="viewport" content="width=device-width, initial-scale=1">

		<!-- Place favicon.ico and apple-touch-icon.png in the root directory -->

		<link rel="stylesheet" href="css/normalize.css">
		<link rel="stylesheet" href="css/grid.css">
		<link rel="stylesheet" href="css/xavStyles.css">
		<link rel="stylesheet" href="css/main.css">
		<script src="js/vendor/modernizr-2.6.2.min.js"></script>
	</head>
	<body>
		<!--[if lt IE 7]>
			<p class="browsehappy">You are using an <strong>outdated</strong> browser. Please <a href="http://browsehappy.com/">upgrade your browser</a> to improve your experience.</p>
		<![endif]-->

		<!-- WeChat Home Page Slider 
		  ================================= -->
		<header id="site-header" class="clearfix titlebar">
			<div class="container">
				<h1 class="site-logo pull-left"><a href="#">WeChat</a></h1>
				<nav class="primary-navigation pull-right">
					<ul>
						<li><a href="#">Home</a></li>
						<li><a href="#">Contact us</a></li>
						<li><a href="create_chat_room.jsp">Create chat room</a></li>
						<li><a href="#">Members</a></li>
						<li><a href="#">About</a></li>
					</ul>
				</nav>
			</div><!-- /container -->

			<div class="site-titlebar">
				<div class="container">
					<a href="#" class="user-image"><img src="img/user-profile-image.png" alt="User Profile Image"></a>
					<h3 class="loggedin-user">Logged in as 
						<%	
							String uname = (String) session.getAttribute("userid");
							out.println(uname); 
						%>
					</h3>
					<a href="create_chat_room.jsp" class="create-chatroom btn green medium pull-right">Create chatroom</a>
				</div>
			</div><!-- /site-titlebar -->

			<div class="page-head clearfix">
				<div class="container">
					<h1>Active chatrooms</h1>
					<div class="searchform chatroom-search pull-right">
						<label for="searchform">Search Rooms</label><input type="text" id="searchform">
					</div><!-- /searchform -->
				</div><!-- /container -->
			</div><!-- /page-head -->
		</header>
		
		<!-- Main Content 
		  ================================= -->
		<div id="site-content" role="main">
			<div class="container">
				<table class='chatrooms'>
					<tr class='heading-row'>
						<th class='number'>No.</th>
						<th class='name'>Chat room name</th>
						<th class='host'>Room host</th>
						
						<th class='active'></th>
						
						${chatrooms}
					
				</table>
			
			<div class="grid_8 incoming-events">
			<h1>Incoming events</h1>
			<table class='events'>
				<tr class='heading-row'>
					<th class='date'>Date</th>
					<th class='name'>Chat room name</th>
					<th class='host'>Room host</th>
				</tr>
				<tr class=''>
					<th>31th Dec - 14:40</th>
					<th><a href="#">The awesome chat room</a></th>
					<th><a href="#">XavorTM</a></th>
				</tr>
				<tr class=''>
					<th>14th Jan - 13:30</th>
					<th><a href="#">Deviantart chatroom</a></th>
					<th><a href="#">Deviantart-Official</a></th>
				</tr>
			</table>
				
			</div><!-- /incoming-events -->

			<div class="grid_4 about-area">
			<h1>Get help</h1>
			<p>If you need any help don’t heistate to ask. There is always someone in the #help channel! Or contact the support staff:</p>
			</div><!-- /about-area -->
			</div><!-- /container -->


		</div><!-- /site-content -->

		<!-- Footer area
		  ================================= -->
		<footer id="site-footer">
			<div class="container">
				<p>Developed by Alex Dimitrov and <span class="pony fag"></span> Dimitar Borisov</p>
			</div>
		</footer>

		<!-- Scripts initialization -->
		<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js">
		<script>window.jQuery || document.write('<script src="js/vendor/jquery-1.10.2.min.js"><\/script>')</script>
		<script src="js/plugins.js"></script>
		<script src="js/main.js"></script>
	</body>	
</html>
