//@author A0116661J
#include "CommandSearch.h"

CommandSearch::CommandSearch(string keyword, string currentDisplayIndicator) {
	_keyword = keyword;
	_currentDisplayIndicator = currentDisplayIndicator;
}


CommandSearch::~CommandSearch(void) {
}

void CommandSearch::execute() {
}

vector<Task>* CommandSearch::updateDisplay() {
	_mergedDisplay = TaskManager::getInstance()->searchForString(_keyword);
	_numberOfResults = _mergedDisplay->size();
	_executionStatus = STATUS_SUCCESSFUL;
	return _mergedDisplay;
}

vector<string>* CommandSearch::updateFeedback() {
	_feedback = new vector<string>; 
	_feedback->push_back (COMMAND_SEARCH);
	_feedback->push_back (_executionStatus);
	_feedback->push_back (to_string(_numberOfResults) + " task(s) found.");
	return _feedback;
}

Command* CommandSearch::getInverseCommand() {
	return NULL;
}