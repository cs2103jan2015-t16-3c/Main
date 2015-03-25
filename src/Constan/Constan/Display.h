#pragma once
#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include "Logic.h"
#include "Task.h"

using namespace std;

class Display
{
private:
	static const string TITLE_DEADLINE;
	static const string TITLE_TIMED;
	static const string TITLE_FLOATING;
	static const string LINE_BREAK;

	void getTaskVectors(string DisplayType);
	void printAccordingToType(string DisplayType);
	void showAllTask();
	void showTodayTask();
	void showDeadlineTask();
	void showTimedTask();
	void showFloatingTask();
	void mergeTask(vector<Task>* todayTask);
	void printTodayTask(vector<Task>* todayTask);
	void showToUser(string text);

	Logic toLogic;
	vector<Task>* timedTask;
	vector<Task>* deadlineTask;
	vector<Task>* floatingTask;



public:

	void print(string DisplayType);
	Display(void);
	~Display(void);
};

#endif

