$(function() {
	$('#form_register').submit(function() {
		verifyFields();
	});
});

function verifyFields() {
	// Disable inputs
	$("#form_register").prop("disabled", true);

	if(!verifyTopicName($("#name").val())) {
		alert("Topic name needs to be longer than 4 characters and less than 35.");
		return finishAttempt();
	}

	if(!verifyText($("#text").val())) {
		alert("Text needs to be longer than 5 characters and less than 1000.");
		return finishAttempt();
	}

	return true;
}

function finishAttempt() {
	$("#form_register").prop("disabled", false);
	return false;
}

function verifyTopicName(topicName) {
	if(topicName.length < 4 || topicName.length > 35)
		return false;
	return true;
}

function verifyText(text) {
	if(text.length < 5 || text.length > 1000)
		return false;
	return true;
}