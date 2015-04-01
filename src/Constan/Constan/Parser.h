#pragma once

#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <iterator>
#include <vector>
#include <list>
#include "stdio.h"
#include <sstream>
#include "Command.h"
#include "CommandAdd.h"
#include "CommandDelete.h"
#include "CommandUndo.h"
/*
#include "CommandEdit.h"
#include "CommandDisplay.h"
#include "CommandSearch.h"
#include "CommandClear.h"
*/

using namespace std;

enum COMMAND_TYPE {
	ADD, DISPLAY, DELETE, INVALID, CLEAR, EDIT, SEARCH, EXIT
};

enum MONTH_NAME {
	JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};
	
class Parser {
private:
	string _taskName;
	string _startDate;
	string _startTime;
	string _endDate;
	string _endTime;
	string _type;
	string _displayType;
	string _keyword;
	vector<Task>* _currentDisplay;
	vector<string>* _vectorString;

//	string strindex;
	int _index;
public:
	Parser(vector<Task>* currentDisplay);

	Command parse(string input);
	Command translateInput(vector<string>& inputVector);
	void getKeyword(vector<string> &inputVector);
	void getIndex(vector<string> &inputVector);
	void displayType(vector<string> &inputVector);
	void getType();
	bool isStartTimeDelimiterFound(vector<string> &inputVector, int &index);
	bool isEndTimeDelimiterFound(vector<string> &inputVector, int &index);
	bool isTaskNameDelimiterFound(vector<string> &inputVector, int &index);
	bool isDelimiter (string input);
	void getEndTime(vector<string> &inputVector);
	void getStartTime(vector<string> &inputVector);
	void getTaskName(vector<string> &inputVector);
	COMMAND_TYPE getCommandType(string command);
	void splitInput(vector<string>* inputVector, string input);
	void toStringLower(string& input);
	string processToday();
	string processDate(string input);
	MONTH_NAME determineMonthName(string month);
	vector<string>* unparse(vector<Task>* vectorTask);
	string convertTaskToString(Task& task);
};

#endif