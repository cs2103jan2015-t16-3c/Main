#include "CommandDisplay.h"


CommandDisplay::CommandDisplay(string displayType) {
	if(isNumberFound(displayType)){
		_displayType = displayType;
	} else {
		toStringLower(displayType);
		if (displayType == DISPLAY_TODAY){
			_displayType = DISPLAY_TODAY;
		} else if (displayType == DISPLAY_TOMORROW) {
			_displayType = DISPLAY_TOMORROW;
		} else if (displayType == DISPLAY_ALL) {
			_displayType = DISPLAY_ALL;
		} else {
			_displayType = DISPLAY_INVALID;
		}
	}
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


CommandDisplay::~CommandDisplay(void) {
}

void CommandDisplay::execute() {
}

vector<Task>* CommandDisplay::updateDisplay() {
	if (_displayType != DISPLAY_INVALID) {
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
	_floatingTaskVector  = TaskManager::getInstance()->retrieveFloatingTask(_displayType);
	_mergedDisplay = _timedTaskVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _deadlineVector->begin(), _deadlineVector->end());
	_mergedDisplay->insert (_mergedDisplay->end(), _floatingTaskVector->begin(), _floatingTaskVector->end());
	return _mergedDisplay;
}

string CommandDisplay::updateDisplayIndicator() {
	if (_displayType != DISPLAY_INVALID) {
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