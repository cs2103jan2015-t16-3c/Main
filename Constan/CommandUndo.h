//@author A0114148M
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
	//Constructor for CommandUndo
	CommandUndo(stack<Command*>* inverseCommandStack,  string currentDisplayIndicator);
	
	~CommandUndo();
	void execute();
	Command* getInverseCommand();
	vector<string>* updateFeedback();
};

#endif
