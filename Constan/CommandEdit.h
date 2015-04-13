//@author A0114148M
#pragma once

#ifndef COMMANDEDIT_H_
#define COMMANDEDIT_H_

#include "Command.h"
#include "CommandInverseEdit.h"
#include "Task.h"
#include "TaskManager.h"

class CommandEdit : 
	public Command {

private:
	string _prevTaskName;
	string _prevStartDate;
	string _prevStartTime;
	string _prevEndDate;
	string _prevEndTime;
	bool _isPrevComplete;
public:
	//Constructor for CommandDisplay
	CommandEdit(int index, string taskName, string startDate, string startTime, string endDate, string endTime, vector<Task>* currentDisplay,  string currentDisplayIndicator);
	
	~CommandEdit();
	void execute();
	vector<string>* updateFeedback();

	//returns CommandInverseEdit object to support undo function
	Command* getInverseCommand();

	void processEdit();
	bool isIndexValid();
	bool isStartAndEndTimeValid();
	bool isEditValid();
};

#endif
