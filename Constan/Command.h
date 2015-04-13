//@author A0114148M
#pragma once

#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include <assert.h>
#include "Task.h"
#include "TaskManager.h"

static const string DISPLAY_INVALID = "invalid";
static const string COMMAND_ADD = "add";
static const string COMMAND_DELETE = "delete";
static const string COMMAND_DISPLAY = "display";
static const string COMMAND_MARK = "mark";
static const string COMMAND_EDIT = "edit";
static const string COMMAND_SEARCH = "search";
static const string COMMAND_UNDO = "undo";
static const string COMMAND_UNMARK = "unmark";
static const string COMMAND_INVALID = "invalid";
static const string COMMAND_SAVE = "save";
static const string STATUS_SUCCESSFUL = "successful";
static const string STATUS_UNSUCCESSFUL = "unsuccessful";
static const string NULL_STRING = "NULL";
static const string ERROR_TYPE_1 = "error1";
static const string ERROR_TYPE_2 = "error2";
static const string ERROR_TYPE_3 = "error3";
static const string ERROR_TYPE_4 = "error4";
static const string ERROR_TYPE_5 = "error5";
static const string ERROR_TYPE_6 = "error6";
static const string ERROR_TYPE_7 = "error7";
static const string BEGINNING_OF_THE_DAY = "0000";
static const string END_OF_THE_DAY = "2359";

static const int EMPTY_NUMBER = -1;

class Command {

protected:
	vector<Task>* _mergedDisplay;
	vector<Task>* _timedTaskVector;
	vector<Task>* _floatingTaskVector;
	vector<Task>* _deadlineVector;
	vector<string>* _feedback;
	vector<Task>* _currentDisplay;
	string _executionStatus;
	string _currentDisplayIndicator;
	string _errorType;
	string _taskName;
	string _startDate;
	string _startTime;
	string _endDate;
	string _endTime;
	string _type;
	int _taskID;
	int _index;
	bool _isComplete;

public:
	//Constructor for Command
	Command();

	~Command();
	virtual void execute();
	virtual Command* getInverseCommand();
	virtual vector<Task>* updateDisplay();
	virtual vector<string>* updateFeedback();
	virtual string updateDisplayIndicator();
	vector<Task>* updateDeadline();
	string updateTodayDate();
	void insertTaskDetails();
	bool isIndexValid();
	void getTaskID();
};

#endif

