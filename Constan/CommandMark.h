//@author A0116661J
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
	//Main constructor for CommandMark
	CommandMark(int index, vector<Task>* currentDisplay,  string currentDisplayIndicator);
	
	//Constructor for CommandMark as inverse Command object of CommandUnmark
	CommandMark(vector<Task>* currentDisplay, int taskID);
	
	~CommandMark();
	void execute();
	vector<string>* updateFeedback();

	//returns CommandUnmark object to support undo function
	Command* getInverseCommand();
};

#endif