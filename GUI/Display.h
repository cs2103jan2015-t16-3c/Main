//This class act as object modifier for display
//it receive VECTOR OF TASK/VECTOR OF STRING/STRING from logic and transform it into 
//object type that could be received by GUI

#pragma once
#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include "Task.h"

using namespace std;

class Display
{
private:
	static const string TITLE_DEADLINE;
	static const string TITLE_TIMED;
	static const string TITLE_FLOATING;
	static const string LINE_BREAK;

	void getTaskVectors();
	void unparseTaskVector();
	string convertToCorrectFormat(string taskName);
	void printAccordingToType(string DisplayType);
	//void showAllTask();
	//void showTodayTask();
	//void showDeadlineTask();
	//void showTimedTask();
	//void showFloatingTask();
	//void mergeTask(vector<Task>* todayTask);
	//void printTodayTask(vector<Task>* todayTask);
	//void showToUser(string text);

	Text
	Logic toLogic;
	vector<Task>* taskVector;

	string display;



public:
	void createDisplay();
	//void print(string DisplayType);
	string getDisplay();
	int findNoOfTask();
	Display(void);
	~Display(void);
};

#endif


