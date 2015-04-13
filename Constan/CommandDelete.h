#pragma once

#ifndef COMMANDDELETE_H_
#define COMMANDDELETE_H_

#include "Command.h"
#include "CommandAdd.h"
#include "Task.h"
#include "TaskManager.h"

using namespace std;

class CommandDelete :
	public Command {

private:
	

public:
	//Main Constructor for CommandDelete
	CommandDelete(int index, vector<Task>* currentDisplay,  string currentDisplayIndicator);
	
	//Constructor for CommandDelete as inverse Command object of CommandAdd
	CommandDelete(vector<Task>* currentDisplay, int taskID);
	
	~CommandDelete();
	void getTaskDetails();
	void execute();
	vector<string>* updateFeedback();
	Command* getInverseCommand();

	//packages the details of a Task into vector<string> to be passed to Logic as the feedback
	void insertTaskDetails();
};

#endif