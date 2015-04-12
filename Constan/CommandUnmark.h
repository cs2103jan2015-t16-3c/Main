#pragma once
#ifndef COMMANDUNMARK_H_
#define COMMANDUNMARK_H_

#include "Command.h"
#include "CommandMark.h"
#include "Task.h"
#include "TaskManager.h"

using namespace std;

class CommandUnmark :
	public Command {

private:

public:
	CommandUnmark(int index, vector<Task>* currentDisplay,  string currentDisplayIndicator);
	CommandUnmark(vector<Task>* currentDisplay, int taskID);
//	~CommandUnmark(void);
	
	void execute();
//	void updateDisplay(vector<Task>* currentDisplay);
	vector<string>* updateFeedback();
	Command* getInverseCommand();
};

#endif