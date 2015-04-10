//this class act as the bridge between Logic and GUI.
//it contains messages that would be displayed to user as feedbacks
//as well as passing the correct feedback message based on the command type
//passes user command to Logic and receive feedback message and display

#pragma once
#ifndef TEXTUI_H_
#define TEXTUI_H_

#include "Logic.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

class TextUI
{
public:
    enum COMMAND_TYPE_FEEDBACK {
        ADD_TASK, DELETE_TASK, EDIT_TASK, DISPLAY_TASK, SEARCH_TASK,
        INVALID_TASK, HELP, OTHERS, UNDO_TASK, MARK_TASK, UNMARK_TASK
    };

    private:

	static string EMPTY_STRING;
	static string SPACE;

    static string MESSAGE_WELCOME;
    static string MESSAGE_ADDED;
    static string MESSAGE_DELETED;
    static string MESSAGE_EDITED;
	static string MESSAGE_DISPLAYED;
	static string MESSAGE_UNDONE;
    static string MESSAGE_MARKED;
	static string MESSAGE_UNMARKED;


    static string ERROR_UNRECOGNISED_COMMAND_TYPE;
    static string ERROR_INVALID_FORMAT;
    static string ERROR_INVALID_DATE_TIME;
    static string ERROR_OTHERS;
    static string HELP_USER_GUIDE;

	static string JANUARY;
	static string FEBRUARY;
	static string MARCH;
	static string APRIL;
	static string MAY;
	static string JUNE;
	static string JULY;
	static string AUGUST;
	static string SEPTEMBER;
	static string OCTOBER;
	static string NOVEMBER;
	static string DECEMBER;

	static string FIRST;
	static string SECOND;
	static string THIRD;
	static string FOURTH;
	static string FIFTH;
	static string SIXTH;
	static string SEVENTH;
	static string EIGHTH;
	static string NINTH;
	static string TENTH;
	static string ELEVENTH;
	static string TWELFTH;

	Logic toLogic;
	vector<string>* _feedback;
	vector<Task>* _displayVector;
	vector<Task>* _deadlineVector;
	string feedback;
	string display;
	string displayDeadline;
	int noOfTask;
	int noOfDeadline;

    //string getFirstWord(string userCommand);
    COMMAND_TYPE_FEEDBACK determineCommandType(string commandTypeString);
    void displayResult();
    void displayTaskList();
	string getFeedbackResult();
    void setFeedback(string userCommand);
    //void showToUser(string text);
	void displayedFeedback(string message);
	void displayedFeedback();

	void setDisplay();
	void getDisplayVector();
	void unparseDisplayVector();
//	void getDeadlineVector();
//	void unparseDeadlineVector();
	string formatDate(string date);
	string formatTime(string time);

public:
    TextUI(void);
    ~TextUI(void);
	string showFeedback();
	string showDisplay();
	string showDeadline();
	int getNoOfTask();
	int getNoOfDeadline();
    void processUserInput(string command);

};

#endif
