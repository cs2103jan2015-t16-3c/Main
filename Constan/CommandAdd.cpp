#include "CommandAdd.h"
#include <algorithm>

CommandAdd::CommandAdd(string taskName, string startDate, string startTime, string endDate, string endTime, vector<Task>* currentDisplay, string currentDisplayIndicator) {
	_taskName = taskName;
	_startDate = startDate;
	_startTime = startTime;
	_endDate = endDate;
	_endTime = endTime;
	_currentDisplay = currentDisplay;
	_currentDisplayIndicator = currentDisplayIndicator;
}

CommandAdd::CommandAdd(string taskName, string startDate, string startTime, string endDate, string endTime, int taskID, vector<Task>* currentDisplay) {
	_taskName = taskName;
	_startDate = startDate;
	_startTime = startTime;
	_endDate = endDate;
	_endTime = endTime;
	_taskID = taskID;
	_currentDisplay = currentDisplay;
}

CommandAdd::~CommandAdd(void) {
}

void CommandAdd::execute() {
	if (isAddValid()) {
		_taskID = TaskManager::getInstance()->addTask(_taskName, _startDate, _startTime, _endDate, _endTime);
		_executionStatus = STATUS_SUCCESSFUL;
		_type = TaskManager::getInstance()->getTaskType(_taskID);
	} else {
		_executionStatus = STATUS_UNSUCCESSFUL;
	}
}

bool CommandAdd::isAddValid() {
	if (_taskName == NULL_STRING) {
		_errorType = ERROR_TYPE_1;
		return false;
	}

	//returns false when a task has a start date or time without end date and end time
	if ((_startDate != NULL_STRING || _startTime != NULL_STRING) && _endDate == NULL_STRING && _endTime == NULL_STRING) {
		_errorType = ERROR_TYPE_2;
		return false;
	}

	//returns false when a task has a start time without a start date
	if (_startDate != NULL_STRING && _startTime == NULL_STRING) {
		_startTime == BEGINNING_OF_THE_DAY;
	} else if (_startDate == NULL_STRING && _startTime != NULL_STRING) {
		_errorType = ERROR_TYPE_3;
		return false;
	}

	//returns false whe a task has a end date without a start date or end date 
	if (_endDate != NULL_STRING && _endTime == NULL_STRING) {
		_endTime == END_OF_THE_DAY;
	} else if (_endDate == NULL_STRING && _endTime != NULL_STRING) {
		if (_startDate != NULL_STRING) {
			_endDate = _startDate;
		} else {
			_errorType = ERROR_TYPE_4;
			return false;
		}
	}

	//returns false if the start date and time of a task is later than its end date and time
	if (_startDate != NULL_STRING && _startTime != NULL_STRING && !isStartAndEndTimeValid()) {
		_errorType = ERROR_TYPE_5;
		return false;
	}

	return true;
}
bool CommandAdd::isStartAndEndTimeValid() {
	string modifiedStartingTime = _startDate.substr(4,4) + _startDate.substr(2,2) + _startDate.substr(0,2) + _startTime;
	string modifiedEndingTime = _endDate.substr(4,4) + _endDate.substr(2,2) + _endDate.substr(0,2) + _endTime;
	if (stoll(modifiedStartingTime) < stoll(modifiedEndingTime)) {
		return true;
	} else {
		return false;
	}
}

vector<string>* CommandAdd::updateFeedback() {
	_feedback = new vector<string>;
	_feedback->push_back (COMMAND_ADD);
	_feedback->push_back (_executionStatus);
	if (_executionStatus == STATUS_SUCCESSFUL) {
		insertTaskDetails();
	} else {
		_feedback->push_back (_errorType);
	}
	return _feedback;
}

void CommandAdd::insertTaskDetails() {
	_feedback->push_back(_taskName);
	_feedback->push_back(_startDate);
	_feedback->push_back(_startTime);
	_feedback->push_back(_endDate);
	_feedback->push_back(_endTime);
}

Command* CommandAdd::getInverseCommand() {
	CommandDelete* invAdd = new CommandDelete ( _currentDisplay, _taskID);
	return invAdd;
}

string CommandAdd::updateDisplayIndicator() {
	if (_executionStatus == STATUS_SUCCESSFUL) {
		if (_type == TASK_TYPE_TIMED) {
			_currentDisplayIndicator = _startDate;
		} else if (_type == TASK_TYPE_DEADLINE) {
			_currentDisplayIndicator = _endDate;
		} else {
			_currentDisplayIndicator = DISPLAY_ALL;
		}
	}
	return _currentDisplayIndicator;
}