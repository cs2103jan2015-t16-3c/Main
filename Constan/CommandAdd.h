#pragma once

#ifndef COMMANDADD_H_
#define COMMANDADD_H_

#include "Command.h"
#include "CommandDelete.h"
#include "TaskManager.h"
#include "Task.h"

using namespace std;

class CommandAdd :
	public Command {

public:
	//Main Constructor for CommandAdd
	CommandAdd(string taskName, string startDate, string startTime, string endDate, string endTime, vector<Task>* currentDisplay, string currentDisplayIndicator);
	
	//Constructor for CommandAdd as inverse Command object of CommandDelete
	CommandAdd (string taskName, string startDate, string startTime, string endDate, string endTime, int taskID, vector<Task>* currentDisplay);
	
	~CommandAdd();
	void execute();
	vector<string>* updateFeedback();
	
	//returns CommandDelete object to delete the newly created Task
	Command* getInverseCommand();
	
	//checks the Task member fields received from Parser.
	//returns false there are insufficient information or the start date and time are later than its end date and end time
	bool isAddValid();

	//returns false if the start date and time are later than the end date and end time
	bool isStartAndEndTimeValid();
	
	//returns the start date of the newly added Task
	string updateDisplayIndicator();
	void insertTaskDetails();
};

#endif
