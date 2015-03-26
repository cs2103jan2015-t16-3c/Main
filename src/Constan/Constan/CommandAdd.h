#pragma once
#ifndef COMMANDADD_H_
#define COMMANDADD_H_

#include "Command.h"

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
	Task* _newTask;

public:
	CommandAdd(string taskName, string startDate, string startTime, string endDate, string endTime, string type);
	//~CommandAdd(void);
	void execute();
	//Command getInverseCommand();
	void setDisplay(vector<Task>* currentDisplay);
//	vector<Task> getTaskToDisplay();

};

#endif
