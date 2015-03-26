#include "CommandAdd.h"
#include <algorithm>

CommandAdd::CommandAdd(string taskName, string startDate, string startTime, string endDate, string endTime, string type) {
	_taskName = taskName;
	_startDate = startDate;
	_startTime = startTime;
	_endDate = endDate;
	_endTime = endTime;
	_type = type;
	_newTask = new Task (_taskName, _startDate, _startTime, _endDate, _endTime, _type);
}


//CommandAdd::~CommandAdd(void) {
//}

void CommandAdd::execute() {
	TaskManager::getInstance()->addTask(*_newTask);
}

//vector<Task> CommandAdd::getTaskToDisplay() {
//	vector<Task>* newTaskVector = new vector<Task>;
//	newTaskVector->push(*_newTask);
//	return *newTaskVector;
//}

void setDisplay(vector<Task>* currentDisplay) {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask("26 March 2015");
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline("26 March 2015");
	_displayVector = new vector<Task>;
	merge ((_timedTaskVector->begin()).getStartTime()
}

//Command CommandAdd::getInverseCommand() {
	//find location;
	//int index = location;
//	CommandDelete invAdd(_index);
//	return invAdd;
//}