#include "Task.h"

Task::Task() {
	//default constructor
	setTaskName(DEFAULT_TASK_NAME);
	setStartTime(DEFAULT_START_TIME);
	setEndTime(DEFAULT_END_TIME);
	setCompletionStatus(false);
}

Task::Task(string taskName, string startTime, string endTime) {
	//constructor
	setTaskName(taskName);
	setStartTime(startTime);
	setEndTime(endTime);
	setCompletionStatus(false);
}

Task::~Task() {
	//destructor
}

void Task::setTaskName(string taskName) {
	_taskName = taskName;
}

string Task::getTaskName() {
	return _taskName;
}

void Task::setStartTime(string startTime) {
	_startTime = startTime;
}

string Task::getStartTime() {
	return _startTime;
}

void Task::setEndTime(string endTime) {
	_endTime = endTime;
}

string Task::getEndTime() {
	return _endTime;
}

void Task::setCompletionStatus(bool isComplete) {
	_isComplete = isComplete;
}

bool Task::getCompletionStatus() {
	return _isComplete;
}
