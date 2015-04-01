#include "CommandUndo.h"
#include <algorithm>

CommandUndo::CommandUndo(stack<Command>* inverseCommandStack) {
	_inverseCommandStack = inverseCommandStack;
}

void CommandUndo::execute() {
	recentCommand = _inverseCommandStack->top();
	_inverseCommandStack->pop();
	recentCommand.execute();
}

void CommandUndo::updateDisplay(vector<Task>* currentDisplay) {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask("29 March 2015");
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline("29 March 2015");
	_mergedDisplay = _deadlineVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _timedTaskVector->begin(), _timedTaskVector->end());
	//merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	currentDisplay = _mergedDisplay;
}

void CommandUndo::updateFeedback(vector<string>* feedbackVector) {
	_feedback = new vector<string>;
	_feedback->push_back ("undo");
	feedbackVector = _feedback;
	
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