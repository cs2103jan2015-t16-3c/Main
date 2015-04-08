#include "CommandEdit.h"


CommandEdit::CommandEdit(int index, string taskName, string startDate, string startTime, string endDate, string endTime, vector<Task>* currentDisplay) {
	_index = index;
	_taskName = taskName;
	_startDate = startDate;
	_startTime = startTime;
	_endDate = endDate;
	_endTime = endTime;
	_currentDisplay = currentDisplay;
}

CommandEdit::~CommandEdit(void) {
}

void CommandEdit::execute() {
	_taskID = _currentDisplay->at(_index-1).getTaskID();
//	_taskName = _currentDisplay->at(_index-1).getTaskName();
	TaskManager::getInstance()->getTaskDetails(_taskID, _prevTaskName, _prevStartDate, _prevStartTime, _prevEndDate, _prevEndTime, _isPrevComplete);
	TaskManager::getInstance()->editTask(_taskID, _taskName, _startDate, _startTime, _endDate, _endTime);
	_taskName = TaskManager::getInstance()->getTaskName(_taskID);
}

vector<string>* CommandEdit::updateFeedback() {
	_feedback = new vector<string>; 
	_feedback->push_back (COMMAND_EDIT);
	_feedback->push_back (_taskName);
	return _feedback;	
}

Command* CommandEdit::getInverseCommand() {
	CommandInverseEdit* invEdit = new CommandInverseEdit (_taskID, _prevTaskName, _prevStartDate, _prevStartTime, _prevEndDate, _prevEndTime, _isPrevComplete);
	return invEdit;
}

/*vector<Task>* CommandEdit::updateDisplay() {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask("02042015");
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline("02042015");
	_mergedDisplay = _deadlineVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _timedTaskVector->begin(), _timedTaskVector->end());
	//merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	return _mergedDisplay;
}*/