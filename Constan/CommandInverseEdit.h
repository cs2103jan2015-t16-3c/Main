#pragma once
#ifndef COMMANDINVERSEEDIT_H_
#define COMMANDINVERSEEDIT_H_

#include "Command.h"
#include "Task.h"
#include "TaskManager.h"

class CommandInverseEdit : 
	public Command {

private:
	int _taskID;
	string _taskName;
	string _startDate;
	string _startTime;
	string _endDate;
	string _endTime;
	bool _isComplete;
public:
	CommandInverseEdit(int taskID, string taskName, string startDate, string startTime, string endDate, string endTime, bool isComplete);
	~CommandInverseEdit(void);

	void execute();
//	vector<Task>* updateDisplay();
//	vector<string>* updateFeedback();
//	Command* getInverseCommand();
};
#endif
