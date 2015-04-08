#include "CommandUnmark.h"

CommandUnmark::CommandUnmark(int index, vector<Task>* currentDisplay) {
	_index = index;
	_currentDisplay = currentDisplay;
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
		_taskID = _currentDisplay->at(_index-1).getTaskID();
	}
	TaskManager::getInstance()->unmarkTask(_taskID);
    _taskName = TaskManager::getInstance()->getTaskName(_taskID);
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
void CommandUnmark::updateFeedback(vector<string>* feedbackVector) {
	_feedback = new vector<string>; 
	_feedback->push_back (COMMAND_UNMARK);
	_feedback->push_back (_taskName);
	feedbackVector = _feedback;
}

Command* CommandUnmark::getInverseCommand() {
	//get info;
	CommandMark* invUnmark = new CommandMark ( _currentDisplay, _index);
	return invUnmark;
}