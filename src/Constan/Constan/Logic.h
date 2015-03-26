#pragma once
#include <string>
#include <vector>
#include "Task.h"
#include "Command.h"
#include "Parser.h"

using namespace std;

class Logic {
private:
	vector<Task>* _currentDisplay;
public:
	Logic();
	~Logic(void);
	void processCommand(string input);
	void getTimedTask(vector<Task>* timedTask, string timeIndicator);
	void getDeadlineTask(vector<Task>* timedTask, string timeIndicator);
	void getFloatingTask(vector<Task>* timedTask, string timeIndicator);
	void getDisplay(vector<Task>* currentDisplay);
};

Logic::Logic() {
	Parser parser;
}

void Logic::getDisplay(vector<Task>* currentDisplay) {
	currentDisplay = _currentDisplay;
}

void Logic::processCommand(string input) {
	Command cmd = parser.parseCommand(input);
	cmd.execute();
	cmd.setDisplay(_currentDisplay);
}

string Logic::getTimedTask(vector<Task>* timedTask, string timeIndicator) {
	timedTask = TaskManager::getInstance()->retrieveTimedTask(timeIndicator);
}
