#include "CommandUndo.h"
#include <algorithm>

CommandUndo::CommandUndo(stack<Command*>* inverseCommandStack, string currentDisplayIndicator) {
	_inverseCommandStack = inverseCommandStack;
	_currentDisplayIndicator = currentDisplayIndicator;
}

void CommandUndo::execute() {
	if (_inverseCommandStack->size()>0) {
		recentCommand = _inverseCommandStack->top();
		_inverseCommandStack->pop();
		recentCommand->execute();
	}
	_executionStatus = STATUS_SUCCESSFUL;
}

vector<string>* CommandUndo::updateFeedback() {
	_feedback = new vector<string>;
	_feedback->push_back (COMMAND_UNDO);
	_feedback->push_back (_executionStatus);
	_feedback->push_back (EMPTY_STRING);
	return _feedback;
}

Command* CommandUndo::getInverseCommand() {
	return NULL;
}

/*CommandUndo::~CommandUndo(void) {
}
*/