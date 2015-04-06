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
//	_type = _currentDisplay->at(_index-1).getType();
	TaskManager::getInstance()->deleteTask(_taskID);
    
}

/*vector<Task>* CommandDelete::updateDisplay() {
	_timedTaskVector = TaskManager::getInstance()->retrieveTimedTask("02042015");
	_deadlineVector  = TaskManager::getInstance()->retrieveDeadline("02042015");
	_mergedDisplay = _deadlineVector;
	_mergedDisplay->insert (_mergedDisplay->end(), _timedTaskVector->begin(), _timedTaskVector->end());
	//merge (_timedTaskVector.begin(), _timedTaskVector.end(), _deadlineVector.begin(), _deadlineVector.end(), _mergedDisplay.begin(), Compare_Task());
	return _mergedDisplay;
}*/

vector<string>* CommandDelete::updateFeedback() {
	_feedback = new vector<string>; 
	_feedback->push_back ("delete");
	_feedback->push_back (_taskName);
	return _feedback;
}

Command* CommandDelete::getInverseCommand() {
	//get info;
	CommandAdd* invDelete = new CommandAdd (_taskName, _startDate, _startTime, _endDate, _endTime, _taskID, _currentDisplay);
	return invDelete;
}