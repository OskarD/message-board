$(function() {
	$('#form_register').submit(function() {
		verifyRegisterFields();
	});
});

function verifyRegisterFields() {
	// Disable inputs
	$("#form_register").prop("disabled", true);

	var username = $("#username").val();
	var email = $("#email").val();
	var password = $("#password").val();

	if(!verifyUsername(username)) {
		alert("Your username must be at least 3 characters long and not longer than 30.");
		return finishAttempt();
	}
	if(!verifyEmail(email)) {
		alert("Your email must be at least 5 characters long and not longer than 50.");
		return finishAttempt();
	}
	if(!verifyPassword(password)) {
		alert("Your password must be at least 4 characters long and not longer than 30.");
		return finishAttempt();
	}

	if(!verifyPasswordMatch(password, $("#repeated_password").val())) {
		alert("Your passwords did not match.");
		return finishAttempt();
	}

	attemptRegister(username, password, email);

	return finishAttempt();
}

function finishAttempt() {
	$("#form_register").prop("disabled", false);
	return false;
}

function verifyUsername(username) {
	if(username.length < 3 || username.length > 30)
		return false;
	return true;
}

function verifyEmail(email) {
	if(email.length < 6 || email.length > 50)
		return false;
	return true;
}

function verifyPassword(password) {
	if(password.length < 4 || password.length > 30)
		return false;
	return true;
}

function verifyPasswordMatch(password1, password2) {
	if(password1 != password2)
		return false;
	return true;
}

function attemptRegister(username, password, email) {
	password = md5(password);

	$.ajax({
		url: "register_user.php",
		type: "POST",
		dataType: "json",
		cache: false,
		async: false,
		data: { username: username, password: password, email: email },
		success: function(data) {
			switch(data.success_result) {
				case 'name_exists':
					alert("This username is already taken. Please try a different one.");
					break;
				case 'email_exists':
					alert("This e-mail is already registered.");
					break;
				case 'registered':
					alert("Your account has been registered!");
					break;
				default:
					alert("Something went wrong. This shouldn't happen.");
					break;
			}
		},
		error: function(textStatus, errorThrown) {
			alert("Ajax: " + textStatus.responseText + errorThrown);
		}
	});
}