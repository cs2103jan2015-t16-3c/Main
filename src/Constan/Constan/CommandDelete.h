#pragma once
#ifndef COMMANDDELETE_H_
#define COMMANDDELETE_H_

#include "Command.h"
#include "Task.h"
#include "TaskManager.h"

using namespace std;

class CommandDelete :
	public Command {

private:
	int _index;
	int _taskID;
	string _taskName;
public:
	CommandDelete(int index, vector<Task>* currentDisplay);
//	~CommandDelete(void);
	
	void execute();
	void updateDisplay(vector<Task>* currentDisplay);
	void updateFeedback(vector<string>* feedbackVector);
	Command getInverseCommand();
};

#endif