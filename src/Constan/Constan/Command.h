#pragma once
#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include "Task.h"
#include "TaskManager.h"

class Command {
protected:
	vector<Task>* _mergedDisplay;
	vector<Task>* _timedTaskVector;
	vector<Task>* _floatingTaskVector;
	vector<Task>* _deadlineVector;
	vector<string>* _feedback;

public:
	Command(void);
	~Command(void);
	void execute();
	Command getInverseCommand();
	void updateDisplay(vector<Task>* displayVector);
	void updateFeedback(vector<string>* feedbackVector);

	struct Compare_Task {
		bool operator() (Task& t1, Task& t2) {
			return (t1.getStartTime() < t2.getStartTime()) || ((t1.getStartTime() == t2.getStartTime()) && (t1.getEndTime() < t2.getEndTime()));
		}
	};
};

#endif

