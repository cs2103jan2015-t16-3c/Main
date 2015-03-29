#include "CommandDelete.h"

CommandDelete::CommandDelete(int index) {
	_index = index;
}

CommandDelete::~CommandDelete(void)
{
}

void CommandDelete::execute() {
}

/*Command CommandDelete::getInverseCommand() {
	//get info;
	CommandAdd invDelete(std::string taskName, std::string startTime, std::string endTime, bool isCompleted);
	return invDelete;
}*/