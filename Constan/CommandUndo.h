#pragma once
#ifndef COMMANDUNDO_H_
#define COMMANDUNDO_H_

#include "Command.h"
#include "TaskManager.h"
#include "Task.h"
#include <stack>

using namespace std;

class CommandUndo :
	public Command {
private:
	stack<Command*>* _inverseCommandStack;
	Command* recentCommand;
public:
	CommandUndo(stack<Command*>* inverseCommandStack);
	void execute();
	Command* getInverseCommand();
	vector<string>* updateFeedback();

//	vector<Task>* updateDisplay();
//	vector<Task> getTaskToDisplay();
	//~CommandAdd(void);
};

#endif
