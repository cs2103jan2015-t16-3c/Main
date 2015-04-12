#include "CommandMark.h"

CommandMark::CommandMark(int index, vector<Task>* currentDisplay, string currentDisplayIndicator) {
	_index = index;
	_currentDisplay = currentDisplay;
	_taskID = EMPTY_NUMBER;
	_currentDisplayIndicator = currentDisplayIndicator;
}

CommandMark::CommandMark(vector<Task>* currentDisplay, int taskID) {
	_taskID = taskID;
	_currentDisplay = currentDisplay;
}

/*CommandMark::~CommandMark(void)
{
}
*/
void CommandMark::execute() {
	if (_taskID == EMPTY_NUMBER) {
		if (isIndexValid()) {
			_taskID = _currentDisplay->at(_index-1).getTaskID();
		} else {
			_errorType = ERROR_TYPE_6;
			_executionStatus = STATUS_UNSUCCESSFUL;
			return;
		}
	}
	TaskManager::getInstance()->markTask(_taskID);
	TaskManager::getInstance()->getTaskDetails(_taskID, _taskName, _startDate, _startTime, _endDate, _endTime, _isComplete);
	_executionStatus = STATUS_SUCCESSFUL;
}

vector<string>* CommandMark::updateFeedback() {
	_feedback = new vector<string>;
	_feedback->push_back (COMMAND_MARK);
	_feedback->push_back (_executionStatus);
	if (_executionStatus == STATUS_SUCCESSFUL) {
		insertTaskDetails();
	} else {
		_feedback->push_back (_errorType);
	}
	return _feedback;
}

Command* CommandMark::getInverseCommand() {
	CommandUnmark* invMark = new CommandUnmark( _currentDisplay, _taskID);
	return invMark;
}