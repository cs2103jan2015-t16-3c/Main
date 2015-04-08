#include "CommandMark.h"

CommandMark::CommandMark(int index, vector<Task>* currentDisplay) {
	_index = index;
	_currentDisplay = currentDisplay;
	_taskID = EMPTY_NUMBER;
}

CommandMark::CommandMark(vector<Task>* currentDisplay, int taskID) {
	_taskID = taskID;
	_currentDisplay = currentDisplay;
}

/*CommandMark::~CommandMark(void)
{
}
*/
void CommandMark::execute() {
	if (_taskID == EMPTY_NUMBER) {
		_taskID = _currentDisplay->at(_index-1).getTaskID();
	}
	TaskManager::getInstance()->markTask(_taskID);
	_taskName = TaskManager::getInstance()->getTaskName(_taskID);
}

/*void CommandMark::updateDisplay(vector<Task>* currentDisplay) {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask("today");
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline("today");
	_mergedDisplay = _deadlineVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _timedTaskVector->begin(), _timedTaskVector->end());
	//merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	currentDisplay = _mergedDisplay;
}*/

void CommandMark::updateFeedback(vector<string>* feedbackVector) {
	_feedback = new vector<string>; 
	_feedback->push_back (COMMAND_MARK);
	_feedback->push_back (_taskName);
	feedbackVector = _feedback;
}

Command* CommandMark::getInverseCommand() {
	//get info;
	CommandUnmark* invMark = new CommandUnmark( _currentDisplay, _taskID);
	return invMark;
}