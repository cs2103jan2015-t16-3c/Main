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
#include <stdio.h>
#include <time.h>
#include <sstream>
#include "Command.h"
#include "CommandAdd.h"
#include "CommandDelete.h"
#include "CommandUndo.h"
#include "CommandEdit.h"
#include "CommandDisplay.h"
#include "CommandSearch.h"
//#include "CommandClear.h"

using namespace std;



enum MONTH_NAME {
	JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

enum ALPHABETICAL_DATE {
	TODAY, TOMORROW, UNDEFINED
};
	
enum COMMAND_TYPE {
	ADD, DISPLAY, DELETE_IT, INVALID, EDIT, SEARCH, EXIT, UNDO, CLEAR
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
	int _taskID;
	int _count;
	vector<Task>* _currentDisplay;
	vector<string>* _vectorString;
	stack<Command>* _inverseCommandStack;

//	string strindex;
	int _index;
public:
	Parser(stack<Command> *inputStack);
	void updateDisplay(vector<Task>* currentDisplay);
//	Parser(vector<Task>* currentDisplay);

	Command* parse(string input);
	Command* translateInput(vector<string>& inputVector);
	void getKeyword(vector<string> &inputVector);
	void getIndex(vector<string> &inputVector);
	void getDisplayType(vector<string> &inputVector);
	void getType();
	bool isStartTimeDelimiterFound(vector<string> &inputVector, int &index);
	bool isEndTimeDelimiterFound(vector<string> &inputVector, int &index);
	bool isTaskNameDelimiterFound(vector<string> &inputVector, int &index);
	bool isDelimiter (string input);
	void getEndingTime(vector<string> &inputVector);
	void getStartingTime(vector<string> &inputVector);
	void getTaskName(vector<string> &inputVector);
	COMMAND_TYPE determineCommandType(string command);
	void splitInput(vector<string>* inputVector, string input);
	void toStringLower(string& input);
	string processToday();
	string processTomorrow();
	string processDate(string input);
	MONTH_NAME determineMonthName(string month);
	vector<string>* unparse(vector<Task>* vectorTask);
	string convertTaskToString(Task& task);
	void generateTaskID();
	string readDate(string input);
	bool isNumberFound (string input);
	int stringToInt(string);
	string intToString(int);
	ALPHABETICAL_DATE determineAlphabeticalDate(string input);
//	void extractEndingTime (string input);
//	void determineEndTimeOrDate(string input);
//	bool isTime(string input);
};

#endif