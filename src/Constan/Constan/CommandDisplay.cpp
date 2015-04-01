#include "CommandDisplay.h"


CommandDisplay::CommandDisplay(string displayType) {
	_displayType = displayType;
}


CommandDisplay::~CommandDisplay(void) {
}

void CommandDisplay::execute() {

}

void CommandDisplay::updateDisplay(vector<Task>* currentDisplay) {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask(_displayType);
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline(_displayType);
	_floatingTaskVector  = TaskManager::getInstance()->retrieveFloatingTask(_displayType);
	_mergedDisplay = _deadlineVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _timedTaskVector->begin(), _timedTaskVector->end());
	//merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	currentDisplay = _mergedDisplay;
} 

void CommandDisplay::updateFeedback(vector<string>* feedbackVector) {
	_feedback = new vector<string>;
	_feedback->push_back ("display");
	_feedback->push_back (_displayType);
	feedbackVector = _feedback;
}