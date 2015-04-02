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
	string _type;
	int _taskID;
//	Task* _newTask;

public:
	CommandAdd(string taskName, string startDate, string startTime, string endDate, string endTime, string type, int taskID, vector<Task>* currentDisplay);

	void execute();
	void updateDisplay(vector<Task>* currentDisplay);
	void updateFeedback(vector<string>* feedbackVector);
	Command getInverseCommand();
//	vector<Task> getTaskToDisplay();
	//~CommandAdd(void);
};

#endif