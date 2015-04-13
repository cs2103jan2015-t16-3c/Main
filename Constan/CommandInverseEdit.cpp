#include "CommandInverseEdit.h"


CommandInverseEdit::CommandInverseEdit(int taskID, string taskName, string startDate, string startTime, string endDate, string endTime, bool isComplete) {
	_taskID = taskID;
	_taskName = taskName;
	_startDate = startDate;
	_startTime = startTime;
	_endDate = endDate;
	_endTime = endTime;
	_isComplete = isComplete;
}

CommandInverseEdit::~CommandInverseEdit() {
}

void CommandInverseEdit::execute() {
	TaskManager::getInstance()->overwriteTask(_taskID, _taskName, _startDate, _startTime, _endDate, _endTime, _isComplete);
}
