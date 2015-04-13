#include "Logic.h"

Logic::Logic(): parser (&inverseCommandStack) {
	_currentDisplayIndicator = DISPLAY_TODAY;
}

Logic::~Logic(){
}

void Logic::processCommand(string input) {
	parser.updateCurrentDisplayIndicator(_currentDisplayIndicator);

	Command* cmd = parser.parse(input);
	cmd->execute();
	Command* invCommand = cmd->getInverseCommand();
	if (invCommand != NULL) {
		inverseCommandStack.push(invCommand);
	}
	updateLogicAttributes(cmd);

	parser.updateDisplay(_currentDisplay);
	parser.updateInverseCommandStack(&inverseCommandStack);
}


void Logic::updateLogicAttributes(Command* cmd) {
	_currentDisplayIndicator = cmd->updateDisplayIndicator();
	_currentDisplay = cmd->updateDisplay();
	_feedback = cmd->updateFeedback();
	_deadlineVector = cmd->updateDeadline();
	_todayDate = cmd->updateTodayDate();
}

vector<string>* Logic::getFeedback() {
	return _feedback;
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

string Logic::getCurrentDisplayIndicator() {
	return _currentDisplayIndicator;
}