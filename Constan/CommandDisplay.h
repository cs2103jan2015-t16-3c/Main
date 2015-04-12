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
	CommandDisplay(string displayType);
	~CommandDisplay(void);

	void execute();
	vector<Task>* updateDisplay();
	vector<string>* updateFeedback();
	Command* getInverseCommand();
	vector<Task>* generateDisplay();
	void toStringLower(string& input);
	string updateDisplayIndicator();
	bool isNumberFound(string input);
};
#endif
