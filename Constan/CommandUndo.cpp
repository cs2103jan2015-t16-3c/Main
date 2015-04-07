#include "CommandUndo.h"
#include <algorithm>

CommandUndo::CommandUndo(stack<Command>* inverseCommandStack) {
	_inverseCommandStack = inverseCommandStack;
}

void CommandUndo::execute() {
	if (_inverseCommandStack->size()>0) {
		recentCommand = _inverseCommandStack->top();
		_inverseCommandStack->pop();
		recentCommand.execute();
	}
}

/*vector<Task>* CommandUndo::updateDisplay() {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask("02042015");
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline("02042015");
	_mergedDisplay = _deadlineVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _timedTaskVector->begin(), _timedTaskVector->end());
	//merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	return _mergedDisplay;
}*/

vector<string>* CommandUndo::updateFeedback() {
	_feedback = new vector<string>;
	_feedback->push_back ("undo");
	return _feedback;
}

Command* CommandUndo::getInverseCommand() {
	return NULL;
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

//Command CommandDelete::getInverseCommand() {
//}

//Command CommandEdit::getInverseCommand() {
//}

//Command Command