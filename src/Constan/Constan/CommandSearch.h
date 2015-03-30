#pragma once

#ifndef COMMANDSEARCH_H_
#define COMMANDSEARCH_H_

#include "Command.h"
#include "Task.h"
#include "TaskManager.h"

using namespace std;

class CommandSearch
{
public:
	CommandSearch(string keyWord);
	~CommandSearch(void);

	void execute();
	void updateDisplay(vector<Task>* currentDisplay);
	void updateFeedback(vector<string>* feedbackVector);
};

#endif
