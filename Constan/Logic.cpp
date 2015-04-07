#include "Logic.h"

Logic::~Logic(void){
}

Logic::Logic(): parser (&inverseCommandStack) {
}

void Logic::processCommand(string input) {
	Command* cmd = /*new CommandAdd ("a", "a", "a", "a", "a", "floating", 1, _currentDisplay);*/ parser.parse(input);
	cmd->execute();
	Command* invCommand = cmd->getInverseCommand();
	if (invCommand != NULL) {
		inverseCommandStack.push(*invCommand);
	}
	_currentDisplay = cmd->updateDisplay();
	_feedbackLogic = cmd->updateFeedback();
	parser.updateDisplay(_currentDisplay);
}

vector<string>* Logic::getDisplay() {
	return parser.unparse(_currentDisplay);
}


vector<string>* Logic::getFeedback() {
	return _feedbackLogic;
}



/*
string Logic::getTimedTask(vector<Task>* timedTask, string timeIndicator) {
	timedTask = TaskManager::getInstance()->retrieveTimedTask(timeIndicator);
}

	void getTimedTask(vector<Task>* timedTask, string timeIndicator);
	void getDeadlineTask(vector<Task>* timedTask, string timeIndicator);
	void getFloatingTask(vector<Task>* timedTask, string timeIndicator);
	*/