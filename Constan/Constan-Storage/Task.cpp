#include "Task.h"

Task::Task() {
	//default constructor
	setTaskName(DEFAULT_TASK_NAME);
	setStartDate(DEFAULT_START_DATE);
	setStartTime(DEFAULT_START_TIME);
	setEndDate(DEFAULT_END_DATE);
	setEndTime(DEFAULT_END_TIME);
	//setCompletionStatus(false);
}

Task::Task(string taskName, string startDate, string startTime, string endDate, string endTime, string type) {
	//constructor
	setTaskName(taskName);
	setStartDate(startDate);
	setStartTime(startTime);
	setEndDate(endDate);
	setEndTime(endTime);
	setType(type);
	//setCompletionStatus(false);
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

void Task::setStartDate(string startDate) {
	_startDate = startDate;
}

string Task::getStartDate() {
	return _startDate;
}

void Task::setStartTime(string startTime) {
	_startTime = startTime;
}

string Task::getStartTime() {
	return _startTime;
}

void Task::setEndDate(string endDate) {
	_endDate = endDate;
}

string Task::getEndDate() {
	return _endDate;
}

void Task::setEndTime(string endTime) {
	_endTime = endTime;
}

string Task::getEndTime() {
	return _endTime;
}

void Task::setType(string type) {
	_type = type;
}

string Task::getType() {
	return _type;
}

void Task::setTaskID (int taskID) {
	_taskID = taskID;
}

int Task::getTaskID() {
	return _taskID;
}

//void Task::setCompletionStatus(bool isComplete) {
	//_isComplete = isComplete;
//}

//bool Task::getCompletionStatus() {
	//return _isComplete;
//}