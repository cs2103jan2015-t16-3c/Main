#include "CommandSearch.h"

CommandSearch::CommandSearch(string keyword) {
	_keyword = keyword;
}


CommandSearch::~CommandSearch(void) {

}

void CommandSearch::execute() {

}

vector<Task>* CommandSearch::updateDisplay() {
	_mergedDisplay = TaskManager::getInstance()->searchForString(_keyword);
	if (_mergedDisplay -> size() == 0) {
		_executionStatus = STATUS_UNSUCCESSFUL;
	} else {
		_executionStatus = STATUS_SUCCESSFUL;
	}
	return _mergedDisplay;
}

vector<string>* CommandSearch::updateFeedback() {
	_feedback = new vector<string>; 
	_feedback->push_back (COMMAND_SEARCH);
	_feedback->push_back (_keyword);
	_feedback->push_back (_executionStatus);
	return _feedback;
}

Command* CommandSearch::getInverseCommand() {
	return NULL;
}