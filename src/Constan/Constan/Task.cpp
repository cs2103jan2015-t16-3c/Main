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

void Task::setTaskID(int id) {
	_taskID = id;
}

int Task::getTaskID() const {
	return _taskID;
}
void Task::setTaskName(string taskName) {
	_taskName = taskName;
}

string Task::getTaskName() const {
	return _taskName;
}

void Task::setStartDate(string startDate) {
	_startDate = startDate;
}

string Task::getStartDate() const {
	return _startDate;
}

void Task::setStartTime(string startTime) {
	_startTime = startTime;
}

string Task::getStartTime() const {
	return _startTime;
}

void Task::setEndDate(string endDate) {
	_endDate = endDate;
}

string Task::getEndDate() const {
	return _endDate;
}

void Task::setEndTime(string endTime) {
	_endTime = endTime;
}

string Task::getEndTime() const {
	return _endTime;
}

void Task::setType(string type) {
	_type = type;
}

string Task::getType() const {
	return _type;
}

//void Task::setCompletionStatus(bool isComplete) {
	//_isComplete = isComplete;
//}

//bool Task::getCompletionStatus() const {
	//return _isComplete;
//}

