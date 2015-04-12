#include "Command.h"


Command::Command(void)
{
}


Command::~Command(void)
{
}

void Command::execute(){
}

Command* Command::getInverseCommand() {
	return NULL;
}

vector<Task>* Command::updateDisplay(){
	//return _currentDisplay;
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask(_currentDisplayIndicator);
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline(_currentDisplayIndicator);
	_mergedDisplay = _timedTaskVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _deadlineVector->begin(), _deadlineVector->end());
	//merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
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
//	_mergedDisplay = _deadlineVector;
//	_deadlineVector = TaskManager::getInstance()->retrieveDeadline(DISPLAY_TOMORROW);
//	_mergedDisplay->insert (_mergedDisplay->end(), _deadlineVector->begin(), _deadlineVector->end());
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