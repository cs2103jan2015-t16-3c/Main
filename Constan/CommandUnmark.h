//@author A0114148M
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

public:
	//Main constructor for CommandUnmark
	CommandUnmark(int index, vector<Task>* currentDisplay,  string currentDisplayIndicator);

	//Constructor for CommandUnmark as inverse Command object of CommandMark
	CommandUnmark(vector<Task>* currentDisplay, int taskID);
	
	~CommandUnmark();
	void execute();
	vector<string>* updateFeedback();

	////returns CommandMark object to support undo function
	Command* getInverseCommand();
};

#endif