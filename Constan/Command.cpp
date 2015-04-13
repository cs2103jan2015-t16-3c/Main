#include "Command.h"

Command::Command() {
}

Command::~Command() {
}

void Command::execute(){
}

Command* Command::getInverseCommand() {
	return NULL;
}

vector<Task>* Command::updateDisplay(){
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask(_currentDisplayIndicator);
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline(_currentDisplayIndicator);
	_floatingTaskVector  = TaskManager::getInstance()->retrieveFloatingTask(DISPLAY_ALL);
	_mergedDisplay = _timedTaskVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _deadlineVector->begin(), _deadlineVector->end());
	_mergedDisplay->insert (_mergedDisplay->end(), _floatingTaskVector->begin(), _floatingTaskVector->end());
	return _mergedDisplay;
}

vector<string>* Command::updateFeedback(){
	return _feedback;
}

string Command::updateDisplayIndicator() {
	return _currentDisplayIndicator;
}

vector<Task>* Command::updateDeadline() {
	_deadlineVector = TaskManager::getInstance()->retrieveDeadline(DISPLAY_ALL);
	return _deadlineVector;
}

string Command::updateTodayDate() {
	return TaskManager::getInstance()->retrieveTodayDate();
}

void Command::insertTaskDetails() {
	_feedback->push_back(_taskName);
	_feedback->push_back(_startDate);
	_feedback->push_back(_startTime);
	_feedback->push_back(_endDate);
	_feedback->push_back(_endTime);
}

bool Command::isIndexValid() {
	return _index > 0 && _index <= _currentDisplay->size();
}

void Command::getTaskID() {
	if (isIndexValid()) {
			_taskID = _currentDisplay->at(_index-1).getTaskID();
	} else {
		_errorType = ERROR_TYPE_6;
		_executionStatus = STATUS_UNSUCCESSFUL;
		return;
	}
}