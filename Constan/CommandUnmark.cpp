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

CommandUnmark::~CommandUnmark() {
}

void CommandUnmark::execute() {
	if (_taskID == EMPTY_NUMBER) {
		getTaskID();
	}
	TaskManager::getInstance()->unmarkTask(_taskID);
	TaskManager::getInstance()->getTaskDetails(_taskID, _taskName, _startDate, _startTime, _endDate, _endTime, _isComplete);
	_executionStatus = STATUS_SUCCESSFUL;

}

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
	CommandMark* invUnmark = new CommandMark ( _currentDisplay, _taskID);
	return invUnmark;
}