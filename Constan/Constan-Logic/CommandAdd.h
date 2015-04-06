#pragma once
#ifndef COMMANDADD_H_
#define COMMANDADD_H_

#include "Command.h"
#include "CommandDelete.h"
#include "TaskManager.h"
#include "Task.h"

using namespace std;

class CommandAdd :
	public Command {
private:
	string _taskName;
	string _startDate;
	string _startTime;
	string _endDate;
	string _endTime;
	int _taskID;
//	Task* _newTask;

public:
	CommandAdd(string taskName, string startDate, string startTime, string endDate, string endTime, int taskID, vector<Task>* currentDisplay);

	void execute();
//	vector<Task>* updateDisplay();
	vector<string>* updateFeedback();
	Command* getInverseCommand();
//	vector<Task> getTaskToDisplay();
	//~CommandAdd(void);
};

#endif