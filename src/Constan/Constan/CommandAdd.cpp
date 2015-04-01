#include "CommandAdd.h"
#include <algorithm>

CommandAdd::CommandAdd(string taskName, string startDate, string startTime, string endDate, string endTime, string type, int taskID, vector<Task>* currentDisplay) {
	_taskName = taskName;
	_startDate = startDate;
	_startTime = startTime;
	_endDate = endDate;
	_endTime = endTime;
	_type = type;
	_taskID = taskID;
	_currentDisplay = currentDisplay;
//	_newTask = new Task(_taskName, _startDate, _startTime, _endDate, _endTime, _type);
}

void CommandAdd::execute() {
	TaskManager::getInstance()->addTask(_taskName, _startDate, _startTime, _endDate, _endTime, _type, int taskID);
}

void CommandAdd::updateDisplay(vector<Task>* currentDisplay) {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask("02042015");
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline("02042015");
	_mergedDisplay = _deadlineVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _timedTaskVector->begin(), _timedTaskVector->end());
	//merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	currentDisplay = _mergedDisplay;
}

void CommandAdd::updateFeedback(vector<string>* feedbackVector) {
	_feedback = new vector<string>;
	_feedback->push_back ("add");
	_feedback->push_back (_taskName);
	feedbackVector = _feedback;
}

Command CommandAdd::getInverseCommand() {
	CommandDelete invAdd(_taskID, _currentDisplay);
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