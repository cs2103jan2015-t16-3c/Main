#include "CommandUnmark.h"

CommandUnmark::CommandUnmark(int index, vector<Task>* currentDisplay, string currentDisplayIndicator) {
	_index = index;
	_currentDisplay = currentDisplay;
	_taskID = EMPTY_NUMBER;
	_currentDisplayIndicator = currentDisplayIndicator;
}

CommandUnmark::CommandUnmark(vector<Task>* currentDisplay, int taskID) {
	_taskID = taskID;
	_currentDisplay = currentDisplay;
}

/*CommandUnmark::~CommandUnmark(void)
{
}
*/
void CommandUnmark::execute() {
	if (_taskID == EMPTY_NUMBER) {
		if (isIndexValid()) {
			_taskID = _currentDisplay->at(_index-1).getTaskID();
		} else {
			_errorType = ERROR_TYPE_6;
			_executionStatus = STATUS_UNSUCCESSFUL;
			return;
		}
	}
	TaskManager::getInstance()->unmarkTask(_taskID);
	TaskManager::getInstance()->getTaskDetails(_taskID, _taskName, _startDate, _startTime, _endDate, _endTime, _isComplete);
	_executionStatus = STATUS_SUCCESSFUL;

}
/*
void CommandUnmark::updateDisplay(vector<Task>* currentDisplay) {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask("02042015");
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline("02042015");
	_mergedDisplay = _deadlineVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _timedTaskVector->begin(), _timedTaskVector->end());
	//merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	currentDisplay = _mergedDisplay;
}
*/
vector<string>* CommandUnmark::updateFeedback() {
	_feedback = new vector<string>;
	_feedback->push_back (COMMAND_UNMARK);
	_feedback->push_back (_executionStatus);
	if (_executionStatus == STATUS_SUCCESSFUL) {
		insertTaskDetails();
	} else {
		_feedback->push_back (_errorType);
	}
	return _feedback;
}

Command* CommandUnmark::getInverseCommand() {
	//get info;
	CommandMark* invUnmark = new CommandMark ( _currentDisplay, _index);
	return invUnmark;
}