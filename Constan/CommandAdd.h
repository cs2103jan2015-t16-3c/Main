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



public:
	CommandAdd(string taskName, string startDate, string startTime, string endDate, string endTime, int taskID, vector<Task>* currentDisplay, string currentDisplayIndicator);
	CommandAdd (string taskName, string startDate, string startTime, string endDate, string endTime, int taskID, vector<Task>* currentDisplay);
	void execute();
//	vector<Task>* updateDisplay();
	vector<string>* updateFeedback();
	Command* getInverseCommand();
//	vector<Task> getTaskToDisplay();
	//~CommandAdd(void);
	bool isAddValid();
	string updateDisplayIndicator();
	bool isStartAndEndTimeValid();
	void insertTaskDetails();
};

#endif
