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
		_isFound = "false";
	} else {
		_isFound = "true";
	}
	return _mergedDisplay;
}

vector<string>* CommandSearch::updateFeedback() {
	_feedback = new vector<string>; 
	_feedback->push_back ("search");
	_feedback->push_back (_keyword);
	_feedback->push_back (_isFound);
	return _feedback;
}

Command* CommandSearch::getInverseCommand() {
	return NULL;
}