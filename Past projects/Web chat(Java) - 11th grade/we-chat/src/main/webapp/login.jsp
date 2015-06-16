
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
						<li><a href="#">Create chat room</a></li>
						<li><a href="#">Members</a></li>
						<li><a href="#">About</a></li>
					</ul>
				</nav>
			</div><!-- /container -->

			<div class="site-titlebar">
				<div class="container">
					<h3 class="create-user">Not logged in</h3>
				</div>
			</div><!-- /site-titlebar -->

		</header>
		
		<!-- Main Content 
		  ================================= -->
		<div id="site-content" role="main">
			<div class="container">
			<form class='register-form pull-left' action="login.do" method="post">
				<h1>Create New Account</h1>
				<br>
				<p>Some awesome message for the users about the registration proccess.</p>
				<p>
					<label for="username">Username</label>
					<input type="text" name="uname" placeholder="Your username">
				</p>
				<p>
					<label for="pass">Password</label>
					<input type="password" name="pass" placeholder="Your password">
				</p>
				<input  class="btn register green medium" type="submit" value="Login">
				
			</form>
			<img class='pull-right' src="img/map.png" alt="">

			</div>
		</div><!-- /site-content -->

		<!-- Footer area
		  ================================= -->
		<footer id="site-footer">
			<div class="container">
				<p>Developed by Alex Dimitrov and Dimitar Borisov</p>
			</div>
		</footer>

		<!-- Scripts initialization -->
		<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js">
		<script>window.jQuery || document.write('<script src="js/vendor/jquery-1.10.2.min.js"><\/script>')</script>
		<script src="js/plugins.js"></script>
		<script src="js/main.js"></script>
	</body>	
</html>
