#include "CommandEdit.h"


CommandEdit::CommandEdit(int index, string taskName, string startDate, string startTime, string endDate, string endTime) {
	_index = index;
	_taskName = taskName;
	_startDate = startDate;
	_startTime = startTime;
	_endDate = endDate;
	_endTime = endTime;
}

CommandEdit::~CommandEdit(void) {
}

void CommandEdit::execute() {
	_taskID = _currentDisplay->at(_index-1).getTaskID();
//	_taskName = _currentDisplay->at(_index-1).getTaskName();
	TaskManager::getInstance()->editTask(_taskID, _taskName, _startDate, _startTime, _endDate, _endTime);
	_taskName = TaskManager::getInstance()->getTaskName(_taskID);
}

void CommandEdit::updateDisplay(vector<Task>* currentDisplay) {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask("29 March 2015");
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline("29 March 2015");
	_mergedDisplay = _deadlineVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _timedTaskVector->begin(), _timedTaskVector->end());
	//merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	currentDisplay = _mergedDisplay;
}

void CommandEdit::updateFeedback(vector<string>* feedbackVector) {
	_feedback = new vector<string>; 
	_feedback->push_back ("edit");
	_feedback->push_back (_taskName);
	feedbackVector = _feedback;	
}

Command CommandEdit::getInverseCommand() {
}