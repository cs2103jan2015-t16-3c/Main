#pragma once

#ifndef COMMANDMARK_H_
#define COMMANDMARK_H_

#include "Command.h"
#include "CommandUnmark.h"
#include "Task.h"
#include "TaskManager.h"

using namespace std;

class CommandMark:
	public Command {

public:
	CommandMark(int index, vector<Task>* currentDisplay,  string currentDisplayIndicator);
	CommandMark(vector<Task>* currentDisplay, int taskID);
	~CommandMark();
	void execute();
	vector<string>* updateFeedback();
	Command* getInverseCommand();
};

#endif