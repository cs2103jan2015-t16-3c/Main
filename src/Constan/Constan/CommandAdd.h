#pragma once
#ifndef COMMANDADD_H_
#define COMMANDADD_H_

#include "Command.h"

class CommandAdd :
	public Command {
private:
	std::string _taskName;
	std::string _startTime;
	std::string _endTime;
	bool _isCompleted;
	int _index;
public:
	CommandAdd(std::string taskName, std::string startTime, std::string endTime, bool isCompleted);
	~CommandAdd(void);
	void execute();
	Command getInverseCommand();
};

#endif
