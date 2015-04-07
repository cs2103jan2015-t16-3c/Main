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
	string _prevTaskName;
	string _prevStartDate;
	string _prevStartTime;
	string _prevEndDate;
	string _prevEndTime;
public:
	CommandEdit(int index, string taskName, string startDate, string startTime, string endDate, string endTime, vector<Task>* currentDisplay);
	~CommandEdit(void);

	void execute();
//	vector<Task>* updateDisplay();
	vector<string>* updateFeedback();
	Command* getInverseCommand();
};
#endif
