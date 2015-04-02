#include "CommandDelete.h"

CommandDelete::CommandDelete(int index, vector<Task>* currentDisplay) {
	_index = index;
	_currentDisplay = currentDisplay;
}

//CommandDelete::~CommandDelete(void)
//{
//}

void CommandDelete::execute() {
	_taskID = _currentDisplay->at(_index-1).getTaskID();
	_taskName = _currentDisplay->at(_index-1).getTaskName();
	_startDate = _currentDisplay->at(_index-1).getStartDate();
	_startTime = _currentDisplay->at(_index-1).getStartTime();
	_endDate = _currentDisplay->at(_index-1).getEndDate();
	_endTime = _currentDisplay->at(_index-1).getEndTime();
	_type = _currentDisplay->at(_index-1).getType();
	TaskManager::getInstance()->deleteTask(_taskID);
    
}

void CommandDelete::updateDisplay(vector<Task>* currentDisplay) {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask("02042015");
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline("02042015");
	_mergedDisplay = _deadlineVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _timedTaskVector->begin(), _timedTaskVector->end());
	//merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	currentDisplay = _mergedDisplay;
}

void CommandDelete::updateFeedback(vector<string>* feedbackVector) {
	_feedback = new vector<string>; 
	_feedback->push_back ("delete");
	_feedback->push_back (_taskName);
	feedbackVector = _feedback;
}

Command CommandDelete::getInverseCommand() {
	//get info;
	CommandAdd invDelete(_taskName, _startDate, _startTime, _endDate, _endTime, _type, _taskID, _currentDisplay);
	return invDelete;
}