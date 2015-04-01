#pragma once
#ifndef TEXTUI_H_
#define TEXTUI_H_

#include "Logic.h"
#include "Display.h"
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
        ADD_TASK, DELETE_TASK, EDIT_TASK, DISPLAY, 
        INVALID, HELP, OTHERS, SEARCH_TASK
    };

    private:

    static string MESSAGE_WELCOME;
    static string MESSAGE_ADDED;
    static string MESSAGE_DELETED;
    static string MESSAGE_EDITED;
	static string MESSAGE_SEARCH_FOUND;
	static string MESSAGE_SEARCH_NOT_FOUND;

    static string ERROR_UNRECOGNISED_COMMAND_TYPE;
    static string ERROR_INVALID_FORMAT;
    static string ERROR_INVALID_DATE_TIME;
    static string ERROR_OTHERS;
    static string HELP_USER_GUIDE;

    vector<string> output;
    Display displayTask;
	string userCommandTemp;

    string getFirstWord(string userCommand);
    COMMAND_TYPE_FEEDBACK determineCommandType(string commandTypeString);
    void displayResult();
    void displayTaskList();
    void printFeedback();
    void showToUser(string text);
	Logic toLogic;
	vector<string>* _feedback;

public:
    TextUI(void);
    ~TextUI(void);
    void main();

};

#endif