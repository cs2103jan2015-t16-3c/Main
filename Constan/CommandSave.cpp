#include "CommandSave.h"


CommandSave::CommandSave(string fileName, vector<Task>* currentDisplay,  string currentDisplayIndicator) {
	_fileName = fileName;
	_currentDisplay = currentDisplay;
	_currentDisplayIndicator = currentDisplayIndicator;
}


CommandSave::~CommandSave() {
}

void CommandSave::execute() {
	TaskManager::getInstance()->setFileName(_fileName);
}

vector<string>* CommandSave::updateFeedback() {
	_feedback = new vector<string>;
	_feedback->push_back (COMMAND_SAVE);
	_feedback->push_back (_executionStatus);
	if (_executionStatus == STATUS_SUCCESSFUL) {
		insertTaskDetails();
	} else {
		_feedback->push_back (_errorType);
	}
	return _feedback;
}