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
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask(DISPLAY_TODAY);
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline(DISPLAY_TODAY);
	_mergedDisplay = _timedTaskVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _deadlineVector->begin(), _deadlineVector->end());
	//merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	return _mergedDisplay;
}

vector<string>* Command::updateFeedback(){
	return _feedback;
}

vector<Task>* Command::updateDeadline() {
	_deadlineVector = TaskManager::getInstance()->retrieveDeadline(DISPLAY_TODAY);
	_mergedDisplay = _deadlineVector;
	_deadlineVector = TaskManager::getInstance()->retrieveDeadline(DISPLAY_TOMORROW);
	_mergedDisplay->insert (_mergedDisplay->end(), _deadlineVector->begin(), _deadlineVector->end());
	return _mergedDisplay;
}

string Command::updateTodayDate() {
	return TaskManager::getInstance()->retrieveTodayDate();
}