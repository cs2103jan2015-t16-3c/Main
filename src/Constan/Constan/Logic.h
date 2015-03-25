#pragma once
#include <string>
#include <vector>
#include "Task.h"
#include "Command.h"
#include "Parser.h"

using namespace std;

class Logic {
public:
	Logic();
	~Logic(void);
	void processCommand(string input);
	void getTimedTask(vector<Task>* timedTask, string timeIndicator);
	void getDeadlineTask(vector<Task>* timedTask, string timeIndicator);
	void getFloatingTask(vector<Task>* timedTask, string timeIndicator);
	string getDisplayType();
};

Logic::Logic() {
	Parser parser;
}

void Logic::processCommand(string input) {
	Command cmd = parser.parseCommand(input);
	cmd.execute();
}

string Logic::getTimedTask(vector<Task>* timedTask, string timeIndicator) {
	timedTask = TaskManager::getInstance()->retrieveTimedTask(timeIndicator);
}

vector<Task>* TaskManager::retrieveTimedTask(string timeIndicator) {
	vector<Task>* newVector = new vector<Task>;
	for (int i = 0; i < .size(); i++) {
		if (vector[i].getStartDate() == timeIndicator) {
			newVector->push_back(vector[i])
		}
	return address
}