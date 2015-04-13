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
	string _keyword;
	int _numberOfResults;

public:
	CommandSearch(string keyword, string currentDisplayIndicator);
	~CommandSearch(void);

	void execute();
	vector<Task>* updateDisplay();
	vector<string>* updateFeedback();
	Command* getInverseCommand();
//	string updateDisplayIndicator();
};

#endif


