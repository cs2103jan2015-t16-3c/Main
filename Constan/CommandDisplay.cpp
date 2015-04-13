//@author A0116661J
#include "CommandDisplay.h"

CommandDisplay::CommandDisplay(string displayType, vector<Task>* currentDisplay, string currentDisplayIndicator) {
	_currentDisplayIndicator = currentDisplayIndicator;
	 _currentDisplay = currentDisplay;
	_displayType = displayType;
}

CommandDisplay::~CommandDisplay() {
}

void CommandDisplay::execute() {
}

bool CommandDisplay::isNumberFound(string input) {
	for (unsigned int i =0; i < input.size(); i++) {
		if (isdigit(input.at(i))) {
			return true;
		}
	}
	return false;
}

void CommandDisplay::toStringLower(string& input) {
	for (unsigned int i = 0; i < input.size(); i++) {
		input[i] = tolower(input[i]);
	}
}

vector<Task>* CommandDisplay::updateDisplay() {
	if (_displayType != NULL_STRING) {
		_executionStatus = STATUS_SUCCESSFUL;
		return generateDisplay();
	} else {
		_executionStatus = STATUS_UNSUCCESSFUL;
		_errorType = ERROR_TYPE_7;
		return _currentDisplay;
	}
} 

vector<Task>* CommandDisplay::generateDisplay() {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask(_displayType);
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline(_displayType);
	_floatingTaskVector  = TaskManager::getInstance()->retrieveFloatingTask(DISPLAY_ALL);
	_mergedDisplay = _timedTaskVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _deadlineVector->begin(), _deadlineVector->end());
	_mergedDisplay->insert (_mergedDisplay->end(), _floatingTaskVector->begin(), _floatingTaskVector->end());
	return _mergedDisplay;
}

string CommandDisplay::updateDisplayIndicator() {
	if (_displayType != NULL_STRING) {
		_executionStatus = STATUS_SUCCESSFUL;
	} else {
		_executionStatus = STATUS_UNSUCCESSFUL;
	}
	if (_executionStatus == STATUS_SUCCESSFUL) {
		_currentDisplayIndicator = _displayType;
	} 
	return  _currentDisplayIndicator;
}

vector<string>* CommandDisplay::updateFeedback() {
	_feedback = new vector<string>;
	_feedback->push_back (COMMAND_DISPLAY);
	_feedback->push_back (_executionStatus);
	if (_executionStatus == STATUS_SUCCESSFUL) {
		_feedback->push_back (_displayType);
	} else {
		_feedback->push_back (_errorType);
	}
	return _feedback;
}

Command* CommandDisplay::getInverseCommand() {
	return NULL;
}