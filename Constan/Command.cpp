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
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask("06042015");
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline("06042015");
	_mergedDisplay = _deadlineVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _timedTaskVector->begin(), _timedTaskVector->end());
	//merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	return _mergedDisplay;
}

vector<string>* Command::updateFeedback(){
	return _feedback;
}