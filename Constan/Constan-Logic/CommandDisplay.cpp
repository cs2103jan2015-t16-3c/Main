#include "CommandDisplay.h"


CommandDisplay::CommandDisplay(string displayType) {
	_displayType = displayType;
}


CommandDisplay::~CommandDisplay(void) {
}

void CommandDisplay::execute() {

}

vector<Task>* CommandDisplay::updateDisplay() {
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
	_feedback->push_back ("display");
	_feedback->push_back (_displayType);
	return _feedback;
}

Command* CommandDisplay::getInverseCommand() {
	return NULL;
}