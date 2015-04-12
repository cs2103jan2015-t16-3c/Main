#pragma once
#include "command.h"
class CommandInvalid :
	public Command
{
private:
	string _report;
public:
	CommandInvalid(string report,  string currentDisplayIndicator);
	~CommandInvalid(void);

	void execute();
	vector<string>* updateFeedback();
};

