//@author A0114148M
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
	_executionStatus = STATUS_SUCCESSFUL;
}

vector<string>* CommandSave::updateFeedback() {
	_feedback = new vector<string>;
	_feedback->push_back (COMMAND_SAVE);
	_feedback->push_back (_executionStatus);
	_feedback->push_back (_fileName);
	return _feedback;
}