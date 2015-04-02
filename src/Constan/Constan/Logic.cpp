#include "Logic.h"

Logic::~Logic(void){

}

Logic::Logic(): parser (_currentDisplay) {
}

void Logic::processCommand(string input) {
	Command cmd = parser.parse(input);
	cmd.execute();
	cmd.updateDisplay(_currentDisplay);
	cmd.updateFeedback(_feedback);
}

void Logic::getDisplay(vector<string>* currentDisplay) {
	currentDisplay = parser.unparse(_currentDisplay);
}


vector<string>  Logic::getFeedback() {
	return *_feedback;
}



/*
string Logic::getTimedTask(vector<Task>* timedTask, string timeIndicator) {
	timedTask = TaskManager::getInstance()->retrieveTimedTask(timeIndicator);
}

	void getTimedTask(vector<Task>* timedTask, string timeIndicator);
	void getDeadlineTask(vector<Task>* timedTask, string timeIndicator);
	void getFloatingTask(vector<Task>* timedTask, string timeIndicator);
	*/