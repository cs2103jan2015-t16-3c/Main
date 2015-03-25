#include "Parser.h"
#include <vector>

Command Parser::parse(string input) {
	vector<string>* inputVector = new vector<string>;
	splitInput(inputVector, input);
	return translateInput(*inputVector);
}

void Parser::translateInput(vector<string>& inputVector) {
	switch (getCommandType(inputVector[0])) {
		case ADD:
			getTaskName(inputVector);
			getStartTime(inputVector);
			getEndTime(inputVector);
			getType();
			CommandAdd addTask(taskName,startDate,startTime,endDate,endTime,type);
			return addTask;
			break;
		case DELETE:
			getIndex(inputVector);
			CommandDelete deleteTask(index);
			return deleteTask;
			break;
		case DISPLAY:
			getDisplayType(inputVector);
			CommandDisplay displayTask(_displayType);
			return displayTask;
			break;
		case SEARCH:
			getKeyword(inputVector);
			CommandSearch searchTask(_keyword);
			return searchTask;
			break;
		case EDIT:
			getIndex(inputVector);
			getTaskName(inputVector);
			getStartTime(inputVector);
			getEndTime(inputVector);
			getType();
			CommandEdit editTask(taskName,startDate,startTime,endDate,endTime,type);
			return editTask;
			break;
		case EXIT:
			break;
	}
}

void Parser::getKeyword(vector<string> &inputVector) {
	_keyword = inputVector[1];	
}

void Parser::getIndex(vector<string> &inputVector) {
	_index = inputVector[1];	
}

void Parser::displayType(vector<string> &inputVector) {
	_displayType = inputVector[1];	
}

void Parser::getType() {
	if (_startTime != "NULL" && _endTime != "NULL") {
		_taskType = "timed";
	} else if (_startTime == "NULL" && _endTime != "NULL") {
		_taskType = "deadline";
	} else {
		_taskType = "floating";
	}
}

bool Parser::isStartTimeDelimiterFound(vector<string> &inputVector, &index) {
	for (int i = 0; i<inputVector.size(), i++){
		if (inputVector[i] == "-s"){
			index = i;
			return true;
		}
	}
	return false;
}

bool Parser::isEndTimeDelimiterFound(vector<string> &inputVector, &index) {
	for (int i = 0; i<inputVector.size(), i++){
		if (inputVector[i] == "-e"){
			index = i;
			return true;
		}
	}
	return false;
}

bool Parser::isTaskNameDelimiterFound(vector<string> &inputVector, &index) {
	for (int i = 0; i<inputVector.size(), i++){
		if (inputVector[i] == "-t"){
			index = i;
			return true;
		}
	}
	return false;
}



bool Parser::isDelimiter (string input) {
	if (input == "-t" || input == "-s" || input == "-e") {
		return true;
	} else {
		return false;
	}
}

void Parser::getEndTime(vector<string> &inputVector) {
	string tempString = "";
	int index;
	if(isEndTimeDelimiterFound(inputVector, index)) {
		index++;
		while (!isDelimiter(inputVector[index])){
			tempString = tempString + " " + inputVector[index];
			index++;
		}
		unsigned int startIndex = 0;
		unsigned int partitionIndex = tempString.find_last_of(" ");
		_endDate = tempString.substr(startIndex, partitionIndex-startIndex);
		_endTime = tempString.substr(partitionIndex+1);
	} else {
		_endTime = "NULL";
		_endDate = "NULL";
	}
}

void Parser::getStartTime(vector<string> &inputVector) {
	string tempString = "";
	int index;
	if(isStartTimeDelimiterFound(inputVector, index)) {
		index++;
		while (!isDelimiter(inputVector[index])){
			tempString = tempString + " " + inputVector[index];
			index++;
		}
		unsigned int startIndex = 0;
		unsigned int partitionIndex = tempString.find_last_of(" ");
		_startDate = tempString.substr(startIndex, partitionIndex-startIndex);
		_startTime = tempString.substr(partitionIndex+1);
	} else {
		_startTime = "NULL";
		_startDate = "NULL";
	}
}

void Parser::getTaskName(vector<string> &inputVector) {
	string tempString = "";
	int index;
	if(isTaskNameDelimiterFound(inputVector, index)) {
		index++;
		while (!isDelimiter(inputVector[index])){
			tempString = tempString + " " + inputVector[index];
			index++;
		}
		_taskName = tempString;
	} else {
		_taskName = "NULL";
	}
}

COMMAND_TYPE Parser::getCommandType(string command) {
	toStringLower(command);
	if (command == "add"){
		return ADD;
	} else if (command == "display") {
		return DISPLAY;
	} else if (command == "delete") {
		return DELETE;
	} else if (command == "clear") {
		return CLEAR;
	} else if (command == "exit") {
		return EXIT;
	} else if (command == "edit") {
		return EDIT;
	} else if (command == "search") {
		return SEARCH;
	} else {
		return INVALID;
	}
}


void Parser::splitInput(vector<string>* inputVector, string input) {
	vector<string>::iterator inputVectorIter;
	inputVectorIter = inputVector->begin();
	
	istringstream read(string);
	string temporaryString;
	
	while(in >> temporaryString) {
		*inputVectorIter = temporaryString;
		inputVectorIter++;
	}
}