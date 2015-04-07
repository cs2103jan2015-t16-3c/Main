#include "CommandAdd.h"
#include <algorithm>

CommandAdd::CommandAdd(string taskName, string startDate, string startTime, string endDate, string endTime, int taskID, vector<Task>* currentDisplay) {
	_taskName = taskName;
	_startDate = startDate;
	_startTime = startTime;
	_endDate = endDate;
	_endTime = endTime;
	_taskID = taskID;
	_currentDisplay = currentDisplay;
//	_newTask = new Task(_taskName, _startDate, _startTime, _endDate, _endTime, _type);
}

void CommandAdd::execute() {
	TaskManager::getInstance()->addTask(_taskName, _startDate, _startTime, _endDate, _endTime);
}

/*vector<Task>* CommandAdd::updateDisplay() {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask("02042015");
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline("02042015");
	_mergedDisplay = _deadlineVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _timedTaskVector->begin(), _timedTaskVector->end());
	//merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	return _mergedDisplay;
}*/

vector<string>* CommandAdd::updateFeedback() {
	_feedback = new vector<string>;
	_feedback->push_back ("add");
	_feedback->push_back (_taskName);
	return _feedback;
}

Command* CommandAdd::getInverseCommand() {
	CommandDelete* invAdd = new CommandDelete (_taskID, _currentDisplay);
	return invAdd;
}


//vector<Task> CommandAdd::getTaskToDisplay() {
//	vector<Task>* newTaskVector = new vector<Task>;
//	newTaskVector->push(*_newTask);
//	return *newTaskVector;
//}
//Command CommandAdd::getInverseCommand() {
	//find location;
	//int index = location;
//	CommandDelete invAdd(_index);
//	return invAdd;
//}

//CommandAdd::~CommandAdd(void) {
//}