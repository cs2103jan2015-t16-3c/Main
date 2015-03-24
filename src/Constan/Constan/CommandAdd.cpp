#include "CommandAdd.h"

CommandAdd::CommandAdd(std::string taskName, std::string startTime, std::string endTime, bool isCompleted) {
	_taskName = taskName;
	_startTime = startTime;
	_endTime = endTime;
	_isCompleted = isCompleted;
}


CommandAdd::~CommandAdd(void)
{
}

void CommandAdd::execute() {
}

Command CommandAdd::getInverseCommand() {
	//find location;
	//int index = location;
	CommandDelete invAdd(_index);
	return invAdd;
}