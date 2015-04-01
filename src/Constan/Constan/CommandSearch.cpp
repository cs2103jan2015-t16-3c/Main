#include "CommandSearch.h"

CommandSearch::CommandSearch(string keyword) {
	_keyword = keyword;
}


CommandSearch::~CommandSearch(void) {

}

void CommandSearch::execute() {

}

void CommandSearch::updateDisplay(vector<Task>* currentDisplay) {
	_mergedDisplay = TaskManager::getInstance() -> searchForString(_keyword);
	if (_mergedDisplay -> size() == 0) {
		_isFound = false;
	} else {
		_isFound = true;
	}
}

void CommandSearch::updateFeedback(vector<string>* feedbackVector) {
	_feedback = new vector<string>; 
	_feedback->push_back ("search");
	_feedback->push_back (_keyword);
	_feedback->push_back (_isFound);
	feedbackVector = _feedback;
}