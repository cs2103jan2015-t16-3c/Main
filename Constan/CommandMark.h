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

private:


public:
	CommandMark(int index, vector<Task>* currentDisplay,  string currentDisplayIndicator);
	CommandMark(vector<Task>* currentDisplay, int taskID);
//	~CommandMark(void);
	
	void execute();
//	void updateDisplay(vector<Task>* currentDisplay);
	vector<string>* updateFeedback();
	Command* getInverseCommand();
};

#endif