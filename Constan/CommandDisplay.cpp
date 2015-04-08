#include "CommandDisplay.h"


CommandDisplay::CommandDisplay(string displayType, vector<Task>* currentDisplay) {
	if (displayType == DISPLAY_TODAY){
		_displayType = DISPLAY_TODAY;
	} else if (displayType == DISPLAY_TOMORROW) {
		_displayType = DISPLAY_TOMORROW;
	} else if (displayType == DISPLAY_ALL) {
		_displayType = DISPLAY_ALL;
	} else {
		_displayType = DISPLAY_INVALID;
	}
	_currentDisplay = currentDisplay;
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
		return _currentDisplay;
		_executionStatus = STATUS_UNSUCCESSFUL;
	}

} 

vector<Task>* CommandDisplay::generateDisplay() {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask(_displayType);
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline(_displayType);
	_floatingTaskVector  = TaskManager::getInstance()->retrieveFloatingTask(_displayType);
	_mergedDisplay = _deadlineVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _timedTaskVector->begin(), _timedTaskVector->end());
	//merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	return _mergedDisplay;
}

vector<string>* CommandDisplay::updateFeedback() {
	_feedback = new vector<string>;
	_feedback->push_back (COMMAND_DISPLAY);
	_feedback->push_back (_displayType);
	_feedback->push_back (_executionStatus);
	return _feedback;
}

Command* CommandDisplay::getInverseCommand() {
	return NULL;
}