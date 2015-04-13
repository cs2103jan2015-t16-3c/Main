//@author A0114148M
#include "CommandDelete.h"

CommandDelete::CommandDelete(int index, vector<Task>* currentDisplay, string currentDisplayIndicator) {
	_index = index;
	_currentDisplay = currentDisplay;
	_taskID = EMPTY_NUMBER;
	_currentDisplayIndicator = currentDisplayIndicator;
}

CommandDelete::CommandDelete(vector<Task>* currentDisplay, int taskID) {

	assert(_taskID != EMPTY_NUMBER);

	_taskID = taskID;
	_currentDisplay = currentDisplay;
}

CommandDelete::~CommandDelete() {
}

void CommandDelete::execute() {
	if (_taskID == EMPTY_NUMBER) {
		if (isIndexValid()) {
			getTaskDetails();
		} else {
			_errorType = ERROR_TYPE_6;
			_executionStatus = STATUS_UNSUCCESSFUL;
			return;
		}
	}
	TaskManager::getInstance()->deleteTask(_taskID);
	_executionStatus = STATUS_SUCCESSFUL;
}

void CommandDelete::getTaskDetails() {
	_taskID = _currentDisplay->at(_index-1).getTaskID();
	_taskName = _currentDisplay->at(_index-1).getTaskName();
	_startDate = _currentDisplay->at(_index-1).getStartDate();
	_startTime = _currentDisplay->at(_index-1).getStartTime();
	_endDate = _currentDisplay->at(_index-1).getEndDate();
	_endTime = _currentDisplay->at(_index-1).getEndTime();
}

vector<string>* CommandDelete::updateFeedback() {
	_feedback = new vector<string>;
	_feedback->push_back (COMMAND_DELETE);
	_feedback->push_back (_executionStatus);
	if (_executionStatus == STATUS_SUCCESSFUL) {
		insertTaskDetails();
	} else {
		_feedback->push_back (_errorType);
	}
	return _feedback;
}

void CommandDelete::insertTaskDetails() {
	_feedback->push_back(_taskName);
	_feedback->push_back(_startDate);
	_feedback->push_back(_startTime);
	_feedback->push_back(_endDate);
	_feedback->push_back(_endTime);
}

Command* CommandDelete::getInverseCommand() {
	CommandAdd* invDelete = new CommandAdd (_taskName, _startDate, _startTime, _endDate, _endTime, _taskID, _currentDisplay);
	return invDelete;
}