#pragma once
#ifndef COMMANDINVERSEEDIT_H_
#define COMMANDINVERSEEDIT_H_

#include "Command.h"
#include "Task.h"
#include "TaskManager.h"

class CommandInverseEdit : 
	public Command {

private:

public:
	CommandInverseEdit(int taskID, string taskName, string startDate, string startTime, string endDate, string endTime, bool isComplete);
	~CommandInverseEdit(void);

	void execute();
//	vector<Task>* updateDisplay();
//	vector<string>* updateFeedback();
//	Command* getInverseCommand();
};
#endif
