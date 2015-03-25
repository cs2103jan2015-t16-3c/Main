#pragma once
#ifndef COMMANDADD_H_
#define COMMANDADD_H_

#include "Command.h"

using namespace std;

class CommandAdd :
	public Command {
private:
	string _taskName;
	string _startTime;
	string _endTime;
	string _priority;
	string _feedback;
	Task* _newTask;

public:
	CommandAdd(string taskName, string startTime, string endTime, string priority);
	//~CommandAdd(void);
	void execute();
	//Command getInverseCommand();
	vector<Task> getTaskToDisplay();

};

#endif
