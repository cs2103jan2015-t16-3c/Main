#pragma once

#ifndef COMMANDSAVE_H_
#define COMMANDSAVE_H_

#include "Command.h"
#include "Task.h"
#include "TaskManager.h"

using namespace std;

class CommandSave :
	public Command
{
private:
	string _fileName;
public:
	CommandSave(string fileName, vector<Task>* currentDisplay,  string currentDisplayIndicator);
	~CommandSave(void);
	void execute();
	vector<string>* updateFeedback();
};

#endif