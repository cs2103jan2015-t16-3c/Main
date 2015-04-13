//@author A0116661J
#pragma once

#ifndef COMMANDINVALID_H_
#define COMMANDINVALID_H_

#include "command.h"
class CommandInvalid :
	public Command
{
private:
	string _report;
public:
	//Constructor for CommandInvalid
	CommandInvalid(string report,  string currentDisplayIndicator);
	
	~CommandInvalid();
	void execute();
	vector<string>* updateFeedback();
};

#endif