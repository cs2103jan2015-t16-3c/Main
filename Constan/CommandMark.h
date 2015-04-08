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
	int _index;
	int _taskID;
	string _taskName;

public:
	CommandMark(int index, vector<Task>* currentDisplay);
	CommandMark(vector<Task>* currentDisplay, int taskID);
//	~CommandMark(void);
	
	void execute();
//	void updateDisplay(vector<Task>* currentDisplay);
	void updateFeedback(vector<string>* feedbackVector);
	Command* getInverseCommand();
};

#endif