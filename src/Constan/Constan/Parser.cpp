#include "Parser.h"


Parser::Parser(vector<Task>* currentDisplay){
	_currentDisplay = currentDisplay;
}

Command Parser::parse(string input) {
	vector<string>* inputVector = new vector<string>;
	splitInput(inputVector, input);
	return translateInput(*inputVector);
}

Command Parser::translateInput(vector<string>& inputVector) {
	switch (getCommandType(inputVector[0])) {
		case ADD:
			getTaskName(inputVector);
			getStartTime(inputVector);
			getEndTime(inputVector);
			getType();
			CommandAdd addTask(_taskName, _startDate, _startTime, _endDate, _endTime, _type);
			return addTask;
			break;
/*		case DELETE:
			getIndex(inputVector);
			CommandDelete deleteTask(_index, _currentDisplay);
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
			CommandEdit editTask(_index, _taskName, _startDate, _startTime, _endDate, _endTime, _type);
			return editTask;
			break; */
		case EXIT:
			break;
	}
}

void Parser::getKeyword(vector<string> &inputVector) {
	_keyword = inputVector[1];	
}

void Parser::getIndex(vector<string> &inputVector) {
	_index = std::stoi(inputVector[1]);	
}

void Parser::displayType(vector<string> &inputVector) {
	_displayType = inputVector[1];	
}

void Parser::getType() {
	if (_startTime != "NULL" && _endTime != "NULL") {
		_type = "timed";
	} else if (_startTime == "NULL" && _endTime != "NULL") {
		_type = "deadline";
	} else {
		_type = "floating";
	}
}

bool Parser::isStartTimeDelimiterFound(vector<string> &inputVector, int &index) {
	for (int i = 0; i<inputVector.size(); i++){
		if (inputVector[i] == "-s"){
			index = i;
			return true;
		}
	}
	return false;
}

bool Parser::isEndTimeDelimiterFound(vector<string> &inputVector, int &index) {
	for (int i = 0; i<inputVector.size(); i++){
		if (inputVector[i] == "-e"){
			index = i;
			return true;
		}
	}
	return false;
}

bool Parser::isTaskNameDelimiterFound(vector<string> &inputVector, int &index) {
	for (int i = 0; i<inputVector.size(); i++){
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

void Parser::toStringLower(string& input) {
	for (unsigned int i = 0; i < input.size(); i++) {
		input[i] = tolower(input[i]);
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
	
	while(read >> temporaryString) {
		*inputVectorIter = temporaryString;
		inputVectorIter++;
	}
}