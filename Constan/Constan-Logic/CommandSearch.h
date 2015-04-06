#pragma once
#ifndef COMMANDSEARCH_H_
#define COMMANDSEARCH_H_

#include "Command.h"
#include "Task.h"
#include "TaskManager.h"

using namespace std;

class CommandSearch:
	public Command {

private:
	string _isFound;
	string _keyword;

public:
	CommandSearch(string keyword);
	~CommandSearch(void);

	void execute();
	vector<Task>* updateDisplay();
	vector<string>* updateFeedback();
	Command* getInverseCommand();
};

#endif