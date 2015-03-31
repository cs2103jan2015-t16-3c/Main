#pragma once
#ifndef COMMANDEDIT_H_
#define COMMANDEDIT_H_

#include "Command.h"
#include "Task.h"
#include "TaskManager.h"

class CommandEdit
{
private:

public:
	CommandEdit(void);
	~CommandEdit(void);

	void execute();
	void updateDisplay(vector<Task>* currentDisplay);
	void updateFeedback(vector<string>* feedbackVector);
};
#endif

