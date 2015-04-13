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
#include "CommandInvalid.h"
#include "CommandMark.h"
#include "CommandUnmark.h"
#include "CommandSave.h"

using namespace std;

//static const string NULL_STRING = "NULL";
/*static const string COMMAND_ADD = "add";
static const string COMMAND_DELETE = "delete";
static const string COMMAND_DISPLAY = "display";
static const string COMMAND_MARK = "mark";
static const string COMMAND_EDIT = "edit";
static const string COMMAND_SEARCH = "search";
static const string COMMAND_UNDO = "undo";
static const string COMMAND_UNMARK = "unmark";
static const string COMMAND_INVALID = "invalid";
static const string DISPLAY_TODAY = "today";
static const string DISPLAY_TOMORROW = "tomorrow"; */
static const string COMMAND_EXIT = "exit"; 
static const string DELIMITER_TASKNAME = "-t";
static const string DELIMITER_STARTTIME = "-s";
static const string DELIMITER_ENDTIME = "-e";

static const string INVALID_COMMAND_ADD = "invalid_add";
static const string INVALID_COMMAND_DELETE = "invalid_delete";
static const string INVALID_COMMAND_DISPLAY = "invalid_display";
static const string INVALID_COMMAND_MARK = "invalid_mark";
static const string INVALID_COMMAND_EDIT = "invalid_edit";
static const string INVALID_COMMAND_SEARCH = "invalid_search";
static const string INVALID_COMMAND_UNDO = "invalid_undo";
static const string INVALID_COMMAND_UNMARK = "invalid_unmark";
static const string INVALID_COMMAND_SAVE = "invalid_save";
static const string INVALID_COMMAND_DEFAULT = "invalid_command";

static const int INDEX_NOT_FOUND = -1;
static const int ZERO = 0;
static const int SIZE_TIME_STRING = 4;


enum MONTH_NAME {
	JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

enum ALPHABETICAL_DATE {
	TODAY, TOMORROW, UNDEFINED
};
	
enum COMMAND_TYPE {
	ADD, DISPLAY, DELETE_IT, INVALID, EDIT, SEARCH, EXIT, UNDO, MARK, UNMARK, SAVE
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
	string _report;
	string _currentDisplayIndicator;
	string _fileName;
	int _taskID;
	int _count;
	vector<Task>* _currentDisplay;
	vector<string>* _vectorString;
	stack<Command*>* _inverseCommandStack;


//	string strindex;
	int _index;
public:
	Parser();
	Parser(stack<Command*> *inverseCommandStack);
	void updateDisplay(vector<Task>* currentDisplay);
	void updateInverseCommandStack(stack<Command*> *inverseCommandStack);
	void updateCurrentDisplayIndicator(string currentDisplayIndicator);
//	Parser(vector<Task>* currentDisplay);

	Command* parse(string input);
	Command* translateInput(vector<string>& inputVector);
	
	void getKeyword(vector<string> &inputVector);
	void getIndex(vector<string> &inputVector);
	void getDisplayType(vector<string> &inputVector);
	void getType();
	void getEndingTime(vector<string> &inputVector);
	void getStartingTime(vector<string> &inputVector);
	void getTaskName(vector<string> &inputVector);
	void splitInput(vector<string>* inputVector, string input);
	void toStringLower(string& input);
	void generateTaskID();
	void getReportType(vector<string> &inputVector);
	void getFileName(vector<string> &inputVector);

	bool isStartTimeDelimiterFound(vector<string> &inputVector, size_t &index);
	bool isEndTimeDelimiterFound(vector<string> &inputVector, size_t &index);
	bool isTaskNameDelimiterFound(vector<string> &inputVector, size_t &index);
	bool isDelimiter (string input);
	bool isNumberFound (string input);
	bool isAlphabetFound(string input);
	bool correctDisplay(string input);

	COMMAND_TYPE determineCommandType(string command);

	string processToday();
	string processTomorrow();
	string processDate(string input);
//	string convertTaskToString(Task& task);
	string readDate(string input);
	string intToString(int);
	string verifyTime(string input);

	int stringToInt(string);
	int findFirstDelimiter(vector<string> &inputVector);
	bool checkEndOfMonth(int day, string month);

	MONTH_NAME determineMonthName(string month);
//	vector<string>* unparse(vector<Task>* vectorTask);
	ALPHABETICAL_DATE determineAlphabeticalDate(string input);
//	void extractEndingTime (string input);
//	void determineEndTimeOrDate(string input);
//	bool isTime(string input);
};

#endif