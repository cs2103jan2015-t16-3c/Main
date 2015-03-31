#include "CommandSearch.h"


CommandSearch::CommandSearch(string keyword){
	_keyword = keyword;
}


CommandSearch::~CommandSearch(void) {

}

void CommandSearch::execute(){

}

void CommandSearch::updateDisplay(vector<Task>* currentDisplay) {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask(_keyword);
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline(_keyword);
	_mergedDisplay = new vector<Task>;
	merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	currentDisplay = _mergedDisplay;
}

void CommandSearch::updateFeedback(vector<string>* feedbackVector) {
}