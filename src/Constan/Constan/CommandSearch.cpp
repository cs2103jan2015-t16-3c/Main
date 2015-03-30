#include "CommandSearch.h"


CommandSearch::CommandSearch(string keyWord){
	_keyword = keyWord;
}


CommandSearch::~CommandSearch(void)
{
}

void CommandSearch::execute(){

}

void CommandSearch::updateDisplay(vector<Task>* currentDisplay) {
}

void CommandSearch::updateFeedback(vector<string>* feedbackVector) {
	_feedback = new vector<string>;
	//_feedback->push_back (string);
	_feedback->push_back ("");
	feedbackVector = _feedback;
}