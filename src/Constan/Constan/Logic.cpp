#include "Logic.h"

Logic::~Logic(void)
{
}

Logic::Logic() {

}

void Logic::processCommand(string input) {
	Command cmd = parser.parse(input);
	cmd.execute();
	cmd.updateDisplay(_currentDisplay);
	_feedback = cmd.updateFeedback();
}

void Logic::getDisplay(vector<Task>* currentDisplay) {
	currentDisplay = _currentDisplay;
}

/*
string Logic::getFeedback() {
	return _feedback;
}
*/


/*
string Logic::getTimedTask(vector<Task>* timedTask, string timeIndicator) {
	timedTask = TaskManager::getInstance()->retrieveTimedTask(timeIndicator);
}

	void getTimedTask(vector<Task>* timedTask, string timeIndicator);
	void getDeadlineTask(vector<Task>* timedTask, string timeIndicator);
	void getFloatingTask(vector<Task>* timedTask, string timeIndicator);
	*/