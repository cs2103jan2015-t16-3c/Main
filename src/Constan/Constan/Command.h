#pragma once
#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include "Task.h"
#include "TaskManager.h"

class Command {
public:
	Command(void);
	~Command(void);
	void execute();
	Command getInverseCommand();
};

#endif

