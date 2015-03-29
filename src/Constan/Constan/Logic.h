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
	string _feedback;
public:
	Logic();
	~Logic(void);
	void processCommand(string input);
	void getDisplay(vector<Task>* currentDisplay);
//	string getFeedback();
};

Logic::Logic() {
	Parser parser;
}

void Logic::processCommand(string input) {
	Command cmd = parser.parseCommand(input);
	cmd.execute();
	cmd.updateDisplay(_currentDisplay);
	_feedback = cmd.updateFeedback();
}

void Logic::getDisplay(vector<Task>* currentDisplay) {
	currentDisplay = _currentDisplay;
}

string Logic::getFeedback() {
	return _feedback;
}



/*
string Logic::getTimedTask(vector<Task>* timedTask, string timeIndicator) {
	timedTask = TaskManager::getInstance()->retrieveTimedTask(timeIndicator);
}

	void getTimedTask(vector<Task>* timedTask, string timeIndicator);
	void getDeadlineTask(vector<Task>* timedTask, string timeIndicator);
	void getFloatingTask(vector<Task>* timedTask, string timeIndicator);
	*/