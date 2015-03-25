#include "CommandAdd.h"

CommandAdd::CommandAdd(string taskName, string startTime, string endTime, string priority) {
	_taskName = taskName;
	_startTime = startTime;
	_endTime = endTime;
	_priority = priority;
	_newTask = new Task (_taskName, _startTime, _endTime, _priority);
}


//CommandAdd::~CommandAdd(void) {
//}

void CommandAdd::execute() {
	TaskManager::getInstance()->addTask(*_newTask);
}

vector<Task> CommandAdd::getTaskToDisplay() {
	vector<Task>* newTaskVector = new vector<Task>;
	newTaskVector->push(*_newTask);
	return *newTaskVector;
}

//Command CommandAdd::getInverseCommand() {
	//find location;
	//int index = location;
//	CommandDelete invAdd(_index);
//	return invAdd;
//}