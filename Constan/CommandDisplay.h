//@author A0116661J
#pragma once

#ifndef COMMANDDISPLAY_H_
#define COMMANDDISPLAY_H_

#include "Command.h"
#include "Task.h"
#include "TaskManager.h"

class CommandDisplay :
	public Command {

private:
	string _displayType;
public:
	//Constructor for CommandDisplay
	CommandDisplay(string displayType, vector<Task>* currentDisplay, string currentDisplayIndicator);

	~CommandDisplay();
	void execute();
	vector<Task>* updateDisplay();
	vector<string>* updateFeedback();
	Command* getInverseCommand();
	vector<Task>* generateDisplay();
	string updateDisplayIndicator();

	//converts input to lower case
	void toStringLower(string& input);
	
	//check if input contains a number
	bool isNumberFound(string input);
};
#endif
