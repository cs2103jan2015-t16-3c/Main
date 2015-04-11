#include "Logic.h"

Logic::~Logic(void){
}

Logic::Logic(): parser (&inverseCommandStack) {
}

void Logic::processCommand(string input) {
	Command* cmd = parser.parse(input);
	cmd->execute();
	Command* invCommand = cmd->getInverseCommand();
	if (invCommand != NULL) {
		inverseCommandStack.push(invCommand);
	}
	_currentDisplay = cmd->updateDisplay();
	_feedbackLogic = cmd->updateFeedback();
	_deadlineVector = cmd->updateDeadline();
	_todayDate = cmd->updateTodayDate();
	parser.updateDisplay(_currentDisplay);
	parser.updateInverseCommandStack(&inverseCommandStack);
}

/*
vector<string>* Logic::getDisplay() {
	return parser.unparse(_currentDisplay);
}
*/


vector<string>* Logic::getFeedback() {
	return _feedbackLogic;
}

vector<Task>* Logic::getDisplayVector() {
	return _currentDisplay;
}

vector<Task>* Logic::getDeadlineVector() {
	return _deadlineVector;
}

string Logic::getTodayDate() {
	return _todayDate;
}

/*
string Logic::getTimedTask(vector<Task>* timedTask, string timeIndicator) {
	timedTask = TaskManager::getInstance()->retrieveTimedTask(timeIndicator);
}

	void getTimedTask(vector<Task>* timedTask, string timeIndicator);
	void getDeadlineTask(vector<Task>* timedTask, string timeIndicator);
	void getFloatingTask(vector<Task>* timedTask, string timeIndicator);
	*/