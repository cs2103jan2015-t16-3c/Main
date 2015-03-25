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
        INVALID, HELP, OTHERS
    };

    private:

    static const string MESSAGE_WELCOME;
    static const string MESSAGE_ADDED;
    static const string MESSAGE_DELETED;
    static const string MESSAGE_EDITED;

    static const string ERROR_UNRECOGNISED_COMMAND_TYPE;
    static const string ERROR_INVALID_FORMAT;
    static const string ERROR_INVALID_DATE_TIME;
    static const string ERROR_OTHERS;
    static const string HELP_USER_GUIDE;

    vector<string> output;
    Display displayTask;
	string userCommandTemp;

    string getFirstWord(string userCommand);
    COMMAND_TYPE_FEEDBACK determineCommandType(string commandTypeString);
    void displayResult();
    void displayTaskList();
    void printCommand(string userCommand);
    void showToUser(string text);

public:
    TextUI(void);
    ~TextUI(void);
    void main();

};

#endif