#pragma once
#ifndef COMMANDEDIT_H_
#define COMMANDEDIT_H_

#include "Command.h"
#include "Task.h"
#include "TaskManager.h"

class CommandEdit : 
	public Command {
private:
	int _index;
	int _taskID;
	string _taskName;
	string _startDate;
	string _startTime;
	string _endDate;
	string _endTime;
public:
	CommandEdit(int index, string taskName, string startDate, string startTime, string endDate, string endTime);
	~CommandEdit(void);

	void execute();
	void updateDisplay(vector<Task>* currentDisplay);
	void updateFeedback(vector<string>* feedbackVector);
};
#endif
