#pragma once
#ifndef COMMANDDELETE_H_
#define COMMANDDELETE_H_

#include "Command.h"
#include "CommandAdd.h"
#include "Task.h"
#include "TaskManager.h"

using namespace std;

class CommandDelete :
	public Command {

private:
	

public:
	CommandDelete(int index, vector<Task>* currentDisplay,  string currentDisplayIndicator);
	CommandDelete(vector<Task>* currentDisplay, int taskID);
	void getTaskDetails();
//	~CommandDelete(void);
	
	void execute();
//	vector<Task>* updateDisplay();
	vector<string>* updateFeedback();
	Command* getInverseCommand();
	void insertTaskDetails();
};

#endif