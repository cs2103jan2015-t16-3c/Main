#pragma once
#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include "Task.h"
#include "TaskManager.h"

class Command {
protected:
	vector<Task>* _timedTaskVector;
	vector<Task>* _floatingTaskVector;
	vector<Task>* _deadlineVector;
	vector<Task>* _currentDisplay;
public:
	Command(void);
	~Command(void);
	void execute();
	Command getInverseCommand();
	void setDisplay(vector<Task>* displayVector);
};

#endif

