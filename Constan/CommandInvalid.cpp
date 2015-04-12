#include "CommandInvalid.h"


CommandInvalid::CommandInvalid(string report, string currentDisplayIndicator) {
_report = report;
_executionStatus = STATUS_UNSUCCESSFUL;
}


CommandInvalid::~CommandInvalid(void)
{
}

void CommandInvalid::execute() {
}
	
vector<string>* CommandInvalid::updateFeedback() {
	_feedback = new vector<string>;
	_feedback->push_back (COMMAND_INVALID);
	_feedback->push_back (_executionStatus);
	_feedback->push_back (_report);
	return _feedback;
}