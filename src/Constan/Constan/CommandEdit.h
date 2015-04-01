#pragma once
#ifndef COMMANDEDIT_H_
#define COMMANDEDIT_H_

#include "Command.h"
#include "Task.h"
#include "TaskManager.h"

class CommandEdit
{
private:
	int _index;
	int _taskID;
	string _taskName;
	string _startDate;
	string _startTime;
	string _endDate;
	string _endTime;
public:
	CommandEdit(void);
	~CommandEdit(void);

	void execute();
	void updateDisplay(vector<Task>* currentDisplay);
	void updateFeedback(vector<string>* feedbackVector);
};
#endif

