#pragma once
#include "command.h"
class CommandInvalid :
	public Command
{
private:
	string _report;
public:
	CommandInvalid(string report);
	~CommandInvalid(void);

	void execute();
	vector<string>* updateFeedback();
};

