#pragma once
#ifndef COMMANDDELETE_H_
#define COMMANDDELETE_H_

#include "Command.h"
#include "CommandAdd.h"
#include "Task.h"
#include "TaskManager.h"

using namespace std;

class CommandDelete :
	public Command {

private:
	int _index;
	int _taskID;
	string _taskName;
	string _startDate;
	string _startTime;
	string _endDate;
	string _endTime;
	string _type;
public:
	CommandDelete(int index, vector<Task>* currentDisplay);
	CommandDelete(vector<Task>* currentDisplay, int taskID);
	void getTaskDetails();
//	~CommandDelete(void);
	
	void execute();
//	vector<Task>* updateDisplay();
	vector<string>* updateFeedback();
	Command* getInverseCommand();
};

#endif