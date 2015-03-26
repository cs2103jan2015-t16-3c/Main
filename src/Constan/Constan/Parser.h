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
#include <sstream>
#include <Command.h>
#include <CommandAdd.h>
#include <CommandDelete.h>
#include <CommandEdit.h>
#include <CommandDisplay.h>
#include <CommandSearch.h>
#include <CommandClear.h>

using namespace std;

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

//	string strindex;
	int _index;

public:
	enum COMMAND_TYPE {
		ADD, DISPLAY, DELETE, INVALID, EDIT, SEARCH, EXIT
	};	
	
	Command parse(string input);
	void translateInput(vector<string>& inputVector);
	void getKeyword(vector<string> &inputVector);
	void getIndex(vector<string> &inputVector);
	void displayType(vector<string> &inputVector);
	void getType();
	bool isStartTimeDelimiterFound(vector<string> &inputVector, &index);
	bool isEndTimeDelimiterFound(vector<string> &inputVector, &index);
	bool isTaskNameDelimiterFound(vector<string> &inputVector, &index);
	bool isDelimiter (string input);
	void getEndTime(vector<string> &inputVector);
	void getStartTime(vector<string> &inputVector);
	void getTaskName(vector<string> &inputVector);
	COMMAND_TYPE getCommandType(string command);
	void splitInput(vector<string>* inputVector, string input);
	
	

#endif