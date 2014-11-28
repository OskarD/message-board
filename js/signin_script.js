$(function() {
	$('#form_sign_in').submit(function() {
		return verifySignInFields();
	});
});

function verifySignInFields() {
	// Disable inputs
	$("#form_register").prop("disabled", true);

	var username = $("#username").val();
	var password = $("#password").val();

	if(!verifyUsername(username)) {
		alert("Invalid username. Please try again.");
		return finishAttempt();
	}
	
	if(!verifyPassword(password)) {
		alert("Your password must be at least 4 characters long and not longer than 30.");
		return finishAttempt();
	}

	if(!attemptSignIn(username, password)) {
		alert("Username and password did not match.");
		return finishAttempt();
	}

	finishAttempt();

	return true;
}

function verifyUsername(username) {
	if(username.length < 3 || username.length > 30)
		return false;
	return true;
}

function verifyPassword(password) {
	if(password.length < 4 || password.length > 30)
		return false;
	return true;
}

function attemptSignIn(username, password) {
	password = md5(password);

	return $.ajax({
		url: "verify_signin.php",
		type: "POST",
		dataType: "json",
		cache: false,
		async: false,
		data: { username: username, password: password },
		success: function(data) {
			if(data['success_state'] == true) {
				alert("You have been logged in!");
				return false;
			}
			else {
				alert("Login failed. Please check your credentials and try again.");
				return false;
			}
		},
		error: function(textStatus, errorThrown) {
			alert("Ajax: " + textStatus.responseText + errorThrown);
			return false;
		}
	});

	return true;
}

function finishAttempt() {
	$("#form_register").prop("disabled", false);
	return false;
}