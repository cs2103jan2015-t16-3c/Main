//@author A0114148M
#pragma once

#ifndef COMMANDINVERSEEDIT_H_
#define COMMANDINVERSEEDIT_H_

#include "Command.h"
#include "Task.h"
#include "TaskManager.h"

//CommandInverseEdit is specifically used as as the inverse Command object of CommandEdit
class CommandInverseEdit : 
	public Command {

public:
	//Constructor for CommandInverseEdit
	CommandInverseEdit(int taskID, string taskName, string startDate, string startTime, string endDate, string endTime, bool isComplete);
	
	~CommandInverseEdit();
	void execute();
};

#endif