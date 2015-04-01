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
	CommandDisplay(void);
	~CommandDisplay(void);

	void execute();
	void updateDisplay();
};
#endif
