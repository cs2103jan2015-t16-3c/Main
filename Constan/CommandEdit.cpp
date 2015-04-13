//@author A0114148M
#include "CommandEdit.h"

CommandEdit::CommandEdit(int index, string taskName, string startDate, string startTime, string endDate, string endTime, vector<Task>* currentDisplay, string currentDisplayIndicator) {
	_index = index;
	_taskName = taskName;
	_startDate = startDate;
	_startTime = startTime;
	_endDate = endDate;
	_endTime = endTime;
	_currentDisplay = currentDisplay;
	_currentDisplayIndicator = currentDisplayIndicator;
}

CommandEdit::~CommandEdit() {
}

bool CommandEdit::isIndexValid() {
	return _index > 0 && _index <= _currentDisplay->size();
}

void CommandEdit::execute() {
	if (isIndexValid()) {
		_taskID = _currentDisplay->at(_index-1).getTaskID();
		TaskManager::getInstance()->getTaskDetails(_taskID, _prevTaskName, _prevStartDate, _prevStartTime, _prevEndDate, _prevEndTime, _isPrevComplete);
		processEdit();
	} else {
		_errorType = ERROR_TYPE_6;
		_executionStatus = STATUS_UNSUCCESSFUL;
	}
}

void CommandEdit::processEdit() {
	if (isEditValid()) {
		TaskManager::getInstance()->editTask(_taskID, _taskName, _startDate, _startTime, _endDate, _endTime);
		TaskManager::getInstance()->getTaskDetails(_taskID, _taskName, _startDate, _startTime, _endDate, _endTime, _isComplete);
		_type = TaskManager::getInstance()->getTaskType(_taskID);
		_executionStatus = STATUS_SUCCESSFUL;
	 } else {
		_errorType = ERROR_TYPE_5;
		_executionStatus = STATUS_UNSUCCESSFUL;
	 }
}

bool CommandEdit::isEditValid() {
	if (_startDate == NULL_STRING) {
		_startDate = _prevStartDate;
	}
	if (_startTime == NULL_STRING) {
		 _startTime = _prevStartTime;
	}
	if (_endDate == NULL_STRING) {
		_endDate = _prevEndDate;
	}
	if (_endTime == NULL_STRING) {
		_endTime = _prevEndTime;
	}
	if (isStartAndEndTimeValid()){
		return true;
	} else {
		return false;
	}
}

bool CommandEdit::isStartAndEndTimeValid() {
	string modifiedStartingTime = _startDate.substr(4,4) + _startDate.substr(2,2) + _startDate.substr(0,2) + _startTime;
	string modifiedEndingTime = _endDate.substr(4,4) + _endDate.substr(2,2) + _endDate.substr(0,2) + _endTime;
	if (stoll(modifiedStartingTime) < stoll(modifiedEndingTime)) {
		return true;
	} else {
		return false;
	}
}

vector<string>* CommandEdit::updateFeedback() {
	_feedback = new vector<string>;
	_feedback->push_back (COMMAND_EDIT);
	_feedback->push_back (_executionStatus);
	if (_executionStatus == STATUS_SUCCESSFUL) {
		insertTaskDetails();
	} else {
		_feedback->push_back (_errorType);
	}
	return _feedback;
}


Command* CommandEdit::getInverseCommand() {
	CommandInverseEdit* invEdit = new CommandInverseEdit (_taskID, _prevTaskName, _prevStartDate, _prevStartTime, _prevEndDate, _prevEndTime, _isPrevComplete);
	return invEdit;
}