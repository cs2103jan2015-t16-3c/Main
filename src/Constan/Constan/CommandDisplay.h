#pragma once
#ifndef COMMANDDISPLAY_H_
#define COMMANDDISPLAY_H_

#include "Command.h"
#include "Task.h"
#include "TaskManager.h"

class CommandDisplay :
	public Command {

private:
	string _displayType;
public:
	CommandDisplay(string displayType);
	~CommandDisplay(void);

	void execute();
	void updateDisplay(vector<Task>* currentDisplay);
	void updateFeedback(vector<string>* feedbackVector);
};
#endif
