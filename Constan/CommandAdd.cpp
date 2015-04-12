#include "CommandAdd.h"
#include <algorithm>

CommandAdd::CommandAdd(string taskName, string startDate, string startTime, string endDate, string endTime, int taskID, vector<Task>* currentDisplay, string currentDisplayIndicator) {
	_taskName = taskName;
	_startDate = startDate;
	_startTime = startTime;
	_endDate = endDate;
	_endTime = endTime;
	_taskID = taskID;
	_currentDisplay = currentDisplay;
//	_newTask = new Task(_taskName, _startDate, _startTime, _endDate, _endTime, _type);
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
//	_newTask = new Task(_taskName, _startDate, _startTime, _endDate, _endTime, _type);
}

void CommandAdd::execute() {
	if (isAddValid()) {
		TaskManager::getInstance()->addTask(_taskName, _startDate, _startTime, _endDate, _endTime, _taskID);
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
	if ((_startDate != NULL_STRING || _startTime != NULL_STRING) && _endDate == NULL_STRING && _endTime == NULL_STRING) {
		_errorType = ERROR_TYPE_2;
		return false;
	}
	if (_startDate != NULL_STRING && _startTime == NULL_STRING) {
		_startTime == "0000";
	} else if (_startDate == NULL_STRING && _startTime != NULL_STRING) {
		_errorType = ERROR_TYPE_3;
		return false;
	}
	if (_endDate != NULL_STRING && _endTime == NULL_STRING) {
		_endTime == "2359";
	} else if (_endDate == NULL_STRING && _endTime != NULL_STRING) {
		if (_startDate != NULL_STRING) {
			_endDate = _startDate;
		} else {
			_errorType = ERROR_TYPE_4;
			return false;
		}
	}
	if (_startDate != NULL_STRING && _startTime == NULL_STRING && !isStartAndEndTimeValid()) {
		_errorType = ERROR_TYPE_5;
		return false;
	}
	return true;
}
bool CommandAdd::isStartAndEndTimeValid() {
	if (stoi(_startDate.substr(5,4)) > stoi(_endDate.substr(5,4))) {
		return false;
	} else if (stoi(_startDate.substr(2,2)) > stoi(_endDate.substr(2,2))) {
		return false;
	} else if (stoi(_startDate.substr(0,2)) > stoi(_endDate.substr(0,2))) {
		return false;
	} else if (stoi(_startTime) > stoi(_endTime)) {
		return false;
	} else {
		return true;
	}

}

/*vector<Task>* CommandAdd::updateDisplay() {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask("02042015");
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline("02042015");
	_mergedDisplay = _deadlineVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _timedTaskVector->begin(), _timedTaskVector->end());
	//merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	return _mergedDisplay;
}*/

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
		if (_type == "timed") {
			_currentDisplayIndicator = _startDate;
		} else if (_type == "deadline") {
			_currentDisplayIndicator = _endDate;
		} else {
			_currentDisplayIndicator = DISPLAY_ALL;
		}
	}
	return _currentDisplayIndicator;
}

//vector<Task> CommandAdd::getTaskToDisplay() {
//	vector<Task>* newTaskVector = new vector<Task>;
//	newTaskVector->push(*_newTask);
//	return *newTaskVector;
//}
//Command CommandAdd::getInverseCommand() {
	//find location;
	//int index = location;
//	CommandDelete invAdd(_index);
//	return invAdd;
//}

//CommandAdd::~CommandAdd(void) {
//}