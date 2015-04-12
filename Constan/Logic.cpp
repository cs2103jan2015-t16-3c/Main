#include "Logic.h"

Logic::~Logic(void){
}

Logic::Logic(): parser (&inverseCommandStack) {
	_currentDisplayIndicator = DISPLAY_TODAY;
}

void Logic::processCommand(string input) {
	parser.updateCurrentDisplayIndicator(_currentDisplayIndicator);
	Command* cmd = parser.parse(input);
	cmd->execute();
	Command* invCommand = cmd->getInverseCommand();
	if (invCommand != NULL) {
		inverseCommandStack.push(invCommand);
	}
	_currentDisplayIndicator = cmd->updateDisplayIndicator();
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

string Logic::getCurrentDisplayIndicator() {
	return _currentDisplayIndicator;

}

vector<Task>* Logic::getDeadlineVector() {
	return _deadlineVector;
}

string Logic::getTodayDate() {
	return _todayDate;
}