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
public:
	CommandDelete(int index);
//	~CommandDelete(void);
	
	void execute();
	void updateDisplay(vector<Task>* currentDisplay);
	void updateFeedback(vector<string>* feedbackVector);


//	Command getInverseCommand();
};

#endif