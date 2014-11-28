<?php
	require_once 'lib/pages/class.RegisterPage.inc';

	$page = new RegisterPage("Register In");
	print $page->getHead("<script src='js/md5.js'></script>
						<script src='js/register_script.js'></script>", true);
?>
<body>
	<?php
		print $page->getHeader();
	?>

	<div class='register_view'>
		<h2>Register</h2>
		<form id='form_register' method="post">
			Username<br />
			<input type='text' id='username' name='username' required /><br />
			E-mail<br />
			<input type='email' id='email' name='email' required /><br />
			Password<br />
			<input type='password' id='password' name='password' required /><br />
			Repeat password<br />
			<input type='password' id='repeated_password' name='repeated_password' required /><br />
			<button type="submit" id='submit' name='submit'>Register</button>
		</form>
	</div>

	<div class='result'></div>

	<?php
		print $page->getFooter();
	?>
</body>
<?php
	print $page->getTail();
?>