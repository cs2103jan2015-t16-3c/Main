#include "Parser.h"

Parser::Parser (){
}

Parser::Parser(stack<Command*>* inverseCommandStack){
	_inverseCommandStack = inverseCommandStack;
	_count = 0;
}

Command* Parser::parse(string input) {
	vector<string> inputVector;
	splitInput(&inputVector, input);
	return translateInput(inputVector);
}

void Parser::generateTaskID(){
	_count++;
	_taskID = _count;
}

void Parser::updateDisplay (vector<Task>* currentDisplay) {
	_currentDisplay = currentDisplay;
}

void Parser::updateInverseCommandStack(stack<Command*> *inverseCommandStack) {
	_inverseCommandStack = inverseCommandStack;
}

Command* Parser::translateInput(vector<string>& inputVector) {
	COMMAND_TYPE commandType = determineCommandType(inputVector[0]);
	_report = NULL_STRING;
	getReportType(inputVector);
	if (commandType == ADD) {
			getTaskName(inputVector);			
			if(_report != NULL_STRING){
				CommandInvalid* invalidEntry = new CommandInvalid (_report);
			    return invalidEntry;
			}
			else {
				getStartingTime(inputVector);
				getEndingTime(inputVector);
				generateTaskID();
				CommandAdd* addTask = new CommandAdd (_taskName, _startDate, _startTime, _endDate, _endTime, _taskID, _currentDisplay);
				return addTask;
			}
	} else if (commandType == DELETE_IT) {
			if(_report != NULL_STRING){
				CommandInvalid* invalidEntry = new CommandInvalid (_report);
				return invalidEntry;
			}
			else {
				getIndex(inputVector);
				CommandDelete* deleteTask = new CommandDelete (_index, _currentDisplay);
				return deleteTask;
			}
	} else if (commandType == DISPLAY) {			
			if(_report != NULL_STRING){
				CommandInvalid* invalidEntry = new CommandInvalid (_report);
			    return invalidEntry;
			}
			else {
				getDisplayType(inputVector);
				CommandDisplay* displayTask = new CommandDisplay (_displayType, _currentDisplay);
				return displayTask;
			}
	} else if (commandType == SEARCH) {
			if(_report != NULL_STRING){
				CommandInvalid* invalidEntry = new CommandInvalid (_report);
			    return invalidEntry;
			}
			else {
				getKeyword(inputVector);
				CommandSearch* searchTask = new CommandSearch (_keyword);
				return searchTask;
			}
	} else if (commandType == EDIT) {
			if(_report != NULL_STRING){
				CommandInvalid* invalidEntry = new CommandInvalid (_report);
			    return invalidEntry;
			}
			else {
				getIndex(inputVector);
				getTaskName(inputVector);
				getStartingTime(inputVector);
				getEndingTime(inputVector);
				CommandEdit* editTask = new CommandEdit (_index, _taskName, _startDate, _startTime, _endDate, _endTime, _currentDisplay);
				return editTask;
			}
	} else if (commandType == MARK) {
			if(_report != NULL_STRING){
				CommandInvalid* invalidEntry = new CommandInvalid (_report);
				return invalidEntry;
			}
			else {
				getIndex(inputVector);
				CommandMark* markTask = new CommandMark (_index, _currentDisplay);
				return markTask;
			}
	} else if (commandType == UNMARK) {
			if(_report != NULL_STRING){
				CommandInvalid* invalidEntry = new CommandInvalid (_report);
				return invalidEntry;
			}
			else {
				getIndex(inputVector);
				CommandUnmark* unmarkTask = new CommandUnmark (_index, _currentDisplay);
				return unmarkTask;
			}
	} else if (commandType == UNDO) {
			CommandUndo* undoTask = new CommandUndo (_inverseCommandStack); 
			return undoTask;
	} else if (commandType == INVALID) {
			CommandInvalid* invalidEntry = new CommandInvalid (_report);
			return invalidEntry;
	}
}

void Parser::getReportType(vector<string> &inputVector){
	string input = inputVector[0];
	toStringLower(input);
	if(input == COMMAND_ADD && inputVector.size() == 1){
		_report = "invalidAdd";
	} else if(input == COMMAND_DELETE && inputVector.size() == 1){
		_report = "invalidDelete";
	} else if(input == COMMAND_EDIT && inputVector.size() == 1){
		_report = "invalidEdit";
	} else if(input == COMMAND_DISPLAY && inputVector.size() != 2){
		_report = "invalidDisplay";
//	} else if (input =="display" && !correctDisplay(inputVector[1])){
//		_report = "invalidDisplay";
	} else if (input == COMMAND_SEARCH && inputVector.size() == 1){
		_report = "invalidSearch";
	} else if (input == COMMAND_MARK && inputVector.size() == 1){
		_report = "invalidMark";
	} else if (input == COMMAND_UNMARK && inputVector.size() == 1){
		_report = "invalidUnmark";
	}
}

void Parser::getKeyword(vector<string> &inputVector) {
	_keyword = inputVector[1];	
}

void Parser::getIndex(vector<string> &inputVector) {
	int indexLimit = findFirstDelimiter(inputVector);
	if (indexLimit > 1 || indexLimit == INDEX_NOT_FOUND) {
		_index = std::stoi(inputVector[1]);
	} else {
		_index = INDEX_NOT_FOUND;
	}
}

int Parser::findFirstDelimiter(vector<string> &inputVector) {
	for (unsigned int i = 0; i < inputVector.size(); i++){
		if (isDelimiter(inputVector[i])){
			return i;
		}
	}
	return INDEX_NOT_FOUND;
}

void Parser::getDisplayType(vector<string> &inputVector) {
	_displayType = inputVector[1];	
}

void Parser::getType() {
	if (_startTime != NULL_STRING && _endTime != NULL_STRING) {
		_type = TASK_TYPE_TIMED;
	} else if (_startTime == NULL_STRING && _endTime != NULL_STRING) {
		_type = TASK_TYPE_DEADLINE;
	} else {
		_type = TASK_TYPE_FLOATING;
	}
}

bool Parser::isStartTimeDelimiterFound(vector<string> &inputVector, int &index) {
	for (unsigned int i = 0; i<inputVector.size(); i++){
		if (inputVector[i] == DELIMITER_STARTTIME){
			index = i;
			return true;
		}
	}
	return false;
}

bool Parser::isEndTimeDelimiterFound(vector<string> &inputVector, int &index) {
	for (unsigned int i = 0; i<inputVector.size(); i++){
		if (inputVector[i] == DELIMITER_ENDTIME){
			index = i;
			return true;
		}
	}
	return false;
}

bool Parser::isTaskNameDelimiterFound(vector<string> &inputVector, int &index) {
	for (unsigned int i = 0; i<inputVector.size(); i++){
		if (inputVector[i] == DELIMITER_TASKNAME){
			index = i;
			return true;
		}
	}
	return false;
}



bool Parser::isDelimiter (string input) {
	if (input == DELIMITER_TASKNAME || input == DELIMITER_STARTTIME || input == DELIMITER_ENDTIME) {
		return true;
	} else {
		return false;
	}
}

void Parser::getEndingTime(vector<string> &inputVector) {
	string tempString = EMPTY_STRING;
	int index;
	if(isEndTimeDelimiterFound(inputVector, index)) {
		index++;
		while (index < inputVector.size() && !isDelimiter(inputVector[index])){
			tempString = tempString + WHITE_SPACE + inputVector[index];
			index++;
		}
		unsigned int startIndex = 1;
		unsigned int partitionIndex = tempString.find_last_of(WHITE_SPACE);
		_endDate = tempString.substr(startIndex, partitionIndex-startIndex);
		_endDate = readDate(_endDate);
		_endTime = tempString.substr(partitionIndex+1);
	} else {
		_endDate = NULL_STRING;
		_endTime = NULL_STRING;

	}
}

void Parser::getStartingTime(vector<string> &inputVector) {
	string tempString = EMPTY_STRING;
	int index;
	if(isStartTimeDelimiterFound(inputVector, index)) {
		index++;
		while (index < inputVector.size() && !isDelimiter(inputVector[index])){
			tempString = tempString + WHITE_SPACE + inputVector[index];
			index++;
		}
		unsigned int startIndex = 1;
		unsigned int partitionIndex = tempString.find_last_of(WHITE_SPACE);
		_startDate = tempString.substr(startIndex, partitionIndex-startIndex);
		_startDate = readDate(_startDate);
		_startTime = tempString.substr(partitionIndex+1);
	} else {
		_startDate = NULL_STRING;
		_startTime = NULL_STRING;
	}
}

string Parser::readDate(string input) {
	if (isNumberFound(input)) {
//		if (input.size() > 9) {
			return processDate(input);
//		} else
//			return input;
	} else {
		//ALPHABETICAL_DATE alphaDate = determineAlphabeticalDate(input);
		switch (determineAlphabeticalDate(input)){
			case TODAY:
				return processToday();
				break;
			case TOMORROW:
				return processTomorrow();
				break;
			case UNDEFINED:
				return NULL_STRING;
				break;
			default:
				return NULL_STRING;
		}
	}
}

ALPHABETICAL_DATE Parser::determineAlphabeticalDate(string input) {
	toStringLower(input);
	if (input == DISPLAY_TODAY){
		return TODAY;
	} else if (input == DISPLAY_TOMORROW) {
		return TOMORROW;
	} else {
		return UNDEFINED;
	}
}

bool Parser::isNumberFound(string input) {
	for (unsigned int i =0; i < input.size(); i++) {
		if (isdigit(input.at(i))) {
			return true;
		}
	}
	return false;
}

void Parser::getTaskName(vector<string> &inputVector) {
	string tempString = EMPTY_STRING;
	int index;
	if(isTaskNameDelimiterFound(inputVector, index)) {
		index++;
		while (index < inputVector.size() && !isDelimiter(inputVector[index])){
			tempString = tempString + WHITE_SPACE + inputVector[index];
			index++;
		}
		_taskName = tempString.substr(1);
	} else {
		_taskName = NULL_STRING;
	}
}

void Parser::toStringLower(string& input) {
	for (unsigned int i = 0; i < input.size(); i++) {
		input[i] = tolower(input[i]);
	}
}

COMMAND_TYPE Parser::determineCommandType(string command) {
	toStringLower(command);
	if (command == COMMAND_ADD){
		return ADD;
	} else if (command == COMMAND_DISPLAY) {
		return DISPLAY;
	} else if (command == COMMAND_DELETE) {
		return DELETE_IT;
	} else if (command == COMMAND_MARK) {
		return MARK;
	} else if (command == COMMAND_UNMARK) {
		return UNMARK;
	} else if (command == COMMAND_EXIT) {
		return EXIT;
	} else if (command == COMMAND_EDIT) {
		return EDIT;
	} else if (command == COMMAND_SEARCH) {
		return SEARCH;
	} else if (command == COMMAND_UNDO) {
		return UNDO;
	} else {
		return INVALID;
	}
}


void Parser::splitInput(vector<string>* inputVector, string input) {
	//vector<string>::iterator inputVectorIter;
	//inputVectorIter = inputVector->begin();
	
	istringstream read(input);
	string temporaryString;
	
	while(read >> temporaryString) {
		inputVector->push_back(temporaryString);
	}
}

string Parser::processToday(){
	time_t t = time(0); 
	char tmp[64]; 
	strftime( tmp, sizeof(tmp), "%d%m%Y",localtime(&t) );  
	string today(tmp);

	return today;
}

//added tomorrow 
string Parser::processTomorrow(){
	time_t t = time(0); 
	char tmp[64]; 
	strftime( tmp, sizeof(tmp), "%d%m%Y",localtime(&t) );  
	string today(tmp);

	string day = today.substr(0,2);
	string monthYear = today.substr(2,6);

	int intDay = stringToInt(day);
	intDay++;
	day = intToString(intDay);

	return day + monthYear;
}

string Parser::intToString(int inputInt){

	stringstream outputStream;

	if(inputInt < 10){
		outputStream << '0' << inputInt;
	} else {
		outputStream << inputInt;
	}

	return outputStream.str();
}

int Parser::stringToInt(string inputString){
	int outputInt;
	istringstream outputStream(inputString);

	outputStream >> outputInt;

	return outputInt;
}
// end of edit

MONTH_NAME Parser::determineMonthName(string month) {
	toStringLower(month);
	if(month == "jan")
		return MONTH_NAME::JAN;

	if (month == "feb")
		return MONTH_NAME::FEB;

	if (month == "mar")
		return MONTH_NAME::MAR;

	if (month == "apr")
		return MONTH_NAME::APR;

	if (month == "may")
		return MONTH_NAME::MAY;
	
	if (month == "jun")
		return MONTH_NAME::JUN;	 

	if (month == "jul")
		return MONTH_NAME::JUL;

	if(month == "aug")
		return MONTH_NAME::AUG;

	if (month == "sep")
		return MONTH_NAME::SEP;

	if (month == "oct")
		return MONTH_NAME::OCT;

	if (month == "nov")
		return MONTH_NAME::NOV;

	if (month == "dec")
		return MONTH_NAME::DEC;
}

string Parser::processDate(string input) {
	if (input.size() != 8){
		istringstream in(input);
		vector<string> temp(3);
		in>>temp[0];
		in>>temp[1];
		in>>temp[2];
		toStringLower(temp[1]);

		switch(determineMonthName(temp[1])){
			case JAN:
				return temp[0] + "01" + temp[2];
				break;
			case FEB:
				return temp[0] + "02" + temp[2];
				break;
		    case MAR:
		    	return temp[0]+ "03" + temp[2];
				break;
		    case APR:
		    	return temp[0]+ "04" + temp[2];
				break;
			case MAY:
				return temp[0]+ "05" + temp[2];
				break;
			case JUN:
				return temp[0]+ "06" + temp[2];
				break;
			case JUL:
				return temp[0]+ "07" + temp[2];
				break;
			case AUG:
				return temp[0]+ "08" + temp[2];
				break;
			case SEP:
				return temp[0]+ "09" + temp[2];
				break;
			case OCT:
				return temp[0]+ "10" + temp[2];
				break;
			case NOV:
				return temp[0]+ "11" + temp[2];
				break;
			case DEC:
				return temp[0]+ "12" + temp[2];
				break;
		}
	}
	else {
		return input;
	}
}

/*
vector<string>* Parser::unparse(vector<Task>* vectorTask) {
	_vectorString = new vector<string>;
	vector<Task>::iterator taskIter;
	string output;
	for (taskIter= vectorTask->begin() ; taskIter != vectorTask->end() ; taskIter++) {
		output = convertTaskToString(*taskIter);
		_vectorString->push_back(output);
	}
	return _vectorString;
}

string Parser::convertTaskToString(Task& task) {
	string taskName = task.getTaskName();
	string startDate = task.getStartDate();
	string startTime = task.getStartTime();
	string endDate = task.getEndDate();
	string endTime = task.getEndTime();
	string type = task.getType();
	if (type == "timed") {
		return taskName + "\tStart: " + startDate + "\t(" + startTime + ")\tEnd: " + endDate + "\t(" + endTime + ")";
	} else if (type == "deadline") {
		return taskName + "\tDeadline: " + endDate + "\t(" + endTime + ")!!!!";
	} else if (type == "floating") {
		return taskName;
	}
}
*/