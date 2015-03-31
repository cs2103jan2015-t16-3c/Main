#include "CommandEdit.h"


CommandEdit::CommandEdit(void) {
}


CommandEdit::~CommandEdit(void) {
}

void CommandEdit::execute() {
	_taskId = _currentDisplay->at(_index-1).getTaskId();
	_taskName = _currentDisplay->at(_index-1).getTaskName();
	TaskManager::getInstance()->editTask(_taskId);
}

void CommandEdit::updateDisplay(vector<Task>* currentDisplay) {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask("29 March 2015");
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline("29 March 2015");
	_mergedDisplay = new vector<Task>;
	merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	currentDisplay = _mergedDisplay;
}

void CommandEdit::updateFeedback(vector<string>* feedbackVector) {
	_feedback = new vector<string>; 
	_feedback->push_back ("edit");
	_feedback->push_back (_taskName);
	feedbackVector = _feedback;
	
}
