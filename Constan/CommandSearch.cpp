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
//	if (_mergedDisplay -> size() == 0) {
//		_executionStatus = STATUS_UNSUCCESSFUL;
//	} else {
//		_executionStatus = STATUS_SUCCESSFUL;
//	}
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

/*string CommandSearch::updateDisplayIndicator() {
	if (_type == "timed") {
		return _startDate;
	} else if (_type == "deadline") {
		return _endDate;
	} else {
		return DISPLAY_ALL;
	}
}*/