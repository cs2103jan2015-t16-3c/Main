//@author A0116661J
#include "Parser.h"

Parser::Parser () {
}

//This constructor takes inverseCommandStack and initialise Parser's own _inverseCommandStack to it.
Parser::Parser(stack<Command*>* inverseCommandStack){
	_inverseCommandStack = inverseCommandStack;
}

//takes in user input and returns Command object pointer
Command* Parser::parse(string input) {
	vector<string> inputVector;
	splitInput(&inputVector, input);
	return translateInput(inputVector);
}

void Parser::updateDisplay (vector<Task>* currentDisplay) {
	_currentDisplay = currentDisplay;
}

void Parser::updateCurrentDisplayIndicator(string currentDisplayIndicator) {
	_currentDisplayIndicator = currentDisplayIndicator;
}

void Parser::updateInverseCommandStack(stack<Command*> *inverseCommandStack) {
	_inverseCommandStack = inverseCommandStack;
}

//@author A0116180R
Command* Parser::translateInput(vector<string>& inputVector) {
	COMMAND_TYPE commandType = determineCommandType(inputVector[0]);
	_report = INVALID_COMMAND_DEFAULT;
	getReportType(inputVector);
	if (commandType == ADD) {	
		if(_report != INVALID_COMMAND_DEFAULT){
				CommandInvalid* invalidEntry = new CommandInvalid (_report, _currentDisplayIndicator);
			    return invalidEntry;
			} else {
				getTaskName(inputVector);	
				getStartingTime(inputVector);
				getEndingTime(inputVector);
				CommandAdd* addTask = new CommandAdd (_taskName, _startDate, _startTime, _endDate, _endTime, _currentDisplay, _currentDisplayIndicator);
				return addTask;
			}
	} else if (commandType == DELETE_IT) {
			if(_report != INVALID_COMMAND_DEFAULT){
				CommandInvalid* invalidEntry = new CommandInvalid (_report, _currentDisplayIndicator);
				return invalidEntry;
			} else {
				getIndex(inputVector);
				CommandDelete* deleteTask = new CommandDelete (_index, _currentDisplay, _currentDisplayIndicator);
				return deleteTask;
			}
	} else if (commandType == DISPLAY) {			
			if(_report != INVALID_COMMAND_DEFAULT){
				CommandInvalid* invalidEntry = new CommandInvalid (_report, _currentDisplayIndicator);
			    return invalidEntry;
			} else {
				getDisplayType(inputVector);
				CommandDisplay* displayTask = new CommandDisplay (_displayType, _currentDisplay, _currentDisplayIndicator);
				return displayTask;
			}
	} else if (commandType == SEARCH) {
			if(_report != INVALID_COMMAND_DEFAULT){
				CommandInvalid* invalidEntry = new CommandInvalid (_report, _currentDisplayIndicator);
			    return invalidEntry;
			} else {
				getKeyword(inputVector);
				CommandSearch* searchTask = new CommandSearch (_keyword, _currentDisplayIndicator);
				return searchTask;
			}
	} else if (commandType == EDIT) {
			if(_report != INVALID_COMMAND_DEFAULT){
				CommandInvalid* invalidEntry = new CommandInvalid (_report, _currentDisplayIndicator);
			    return invalidEntry;
			} else {
				getIndex(inputVector);
				getTaskName(inputVector);
				getStartingTime(inputVector);
				getEndingTime(inputVector);
				CommandEdit* editTask = new CommandEdit (_index, _taskName, _startDate, _startTime, _endDate, _endTime, _currentDisplay, _currentDisplayIndicator);
				return editTask;
			}
	} else if (commandType == MARK) {
			if(_report != INVALID_COMMAND_DEFAULT){
				CommandInvalid* invalidEntry = new CommandInvalid (_report, _currentDisplayIndicator);
				return invalidEntry;
			} else {
				getIndex(inputVector);
				CommandMark* markTask = new CommandMark (_index, _currentDisplay, _currentDisplayIndicator);
				return markTask;
			}
	} else if (commandType == UNMARK) {
			if(_report != INVALID_COMMAND_DEFAULT){
				CommandInvalid* invalidEntry = new CommandInvalid (_report, _currentDisplayIndicator);
				return invalidEntry;
			} else {
				getIndex(inputVector);
				CommandUnmark* unmarkTask = new CommandUnmark (_index, _currentDisplay, _currentDisplayIndicator);
				return unmarkTask;
			}
	} else if (commandType == SAVE) {
			if(_report != INVALID_COMMAND_DEFAULT){
				CommandInvalid* invalidEntry = new CommandInvalid (_report, _currentDisplayIndicator);
				return invalidEntry;
			} else {
				getFileName(inputVector);
				CommandSave* saveTask = new CommandSave (_fileName, _currentDisplay, _currentDisplayIndicator);
				return saveTask;
			}
	} else if (commandType == UNDO) {
			CommandUndo* undoTask = new CommandUndo (_inverseCommandStack, _currentDisplayIndicator); 
			return undoTask;
	} else if (commandType == INVALID) {
			CommandInvalid* invalidEntry = new CommandInvalid (_report, _currentDisplayIndicator);
			return invalidEntry;
	}
}

//@author A0116180R
void Parser::getReportType(vector<string> &inputVector){
	string input = inputVector[0];
	toStringLower(input);
	if(input == COMMAND_ADD && inputVector.size() == 1){
		_report = INVALID_COMMAND_ADD;
	} else if(input == COMMAND_DELETE && inputVector.size() == 1){
		_report = INVALID_COMMAND_DELETE;
	} else if(input == COMMAND_EDIT && inputVector.size() == 1){
		_report = INVALID_COMMAND_EDIT;
	} else if(input == COMMAND_DISPLAY && inputVector.size() == 1){
		_report = INVALID_COMMAND_DISPLAY;
	} else if (input == COMMAND_SEARCH && inputVector.size() == 1){
		_report = INVALID_COMMAND_SEARCH;
	} else if (input == COMMAND_MARK && inputVector.size() == 1){
		_report = INVALID_COMMAND_MARK;
	} else if (input == COMMAND_UNMARK && inputVector.size() == 1){
		_report = INVALID_COMMAND_UNMARK;
	} else if (input == COMMAND_SAVE && inputVector.size() == 1){
		_report = INVALID_COMMAND_SAVE;
	}
}

//@author A0116661J
void Parser::getFileName(vector<string> &inputVector) {
	_fileName = inputVector[1];
}

void Parser::getKeyword(vector<string> &inputVector) {
	_keyword = inputVector[1];	
}

//takes in user input index and returns it as int
//returns false if the input has alphabet in it
void Parser::getIndex(vector<string> &inputVector) {
	if (isAlphabetFound(inputVector[1])){
		_index = INDEX_NOT_FOUND;
	} else {
		int indexLimit = findFirstDelimiter(inputVector);
		if (indexLimit > 1 || indexLimit == INDEX_NOT_FOUND) {
			_index = stoi(inputVector[1]);
		} else {
			_index = INDEX_NOT_FOUND;
		}
	}
}

//returns the location of the first delimiter (-t or -s or -e) found
int Parser::findFirstDelimiter(vector<string> &inputVector) {
	for (unsigned int i = 0; i < inputVector.size(); i++){
		if (isDelimiter(inputVector[i])){
			return i;
		}
	}
	return INDEX_NOT_FOUND;
}

//takes in input as a string and returns it in the DDMMYYYY format
void Parser::getDisplayType(vector<string> &inputVector) {
	string tempString = EMPTY_STRING;	
	unsigned int index = 1;
	while (index < inputVector.size() && !isDelimiter(inputVector[index])){
		tempString = tempString + WHITE_SPACE + inputVector[index];
		index++;
	}
	unsigned int startIndex = 1;
	_displayType = tempString.substr(startIndex);
	if (_displayType != DISPLAY_ALL){
		_displayType = readDate(_displayType);
	}
}

//returns the type of the task
void Parser::getType() {
	if (_startTime != NULL_STRING && _endTime != NULL_STRING) {
		_type = TASK_TYPE_TIMED;
	} else if (_startTime == NULL_STRING && _endTime != NULL_STRING) {
		_type = TASK_TYPE_DEADLINE;
	} else {
		_type = TASK_TYPE_FLOATING;
	}
}

//returns true if "-s" is found
//if found, it assigns index to the location of "-s"
bool Parser::isStartTimeDelimiterFound(vector<string> &inputVector, size_t &index) {
	for (unsigned int i = 0; i<inputVector.size(); i++){
		if (inputVector[i] == DELIMITER_STARTTIME){
			index = i;
			return true;
		}
	}
	return false;
}

//returns true if "-e" is found
//if found, it assigns index to the location of "-e"
bool Parser::isEndTimeDelimiterFound(vector<string> &inputVector, size_t &index) {
	for (unsigned int i = 0; i<inputVector.size(); i++){
		if (inputVector[i] == DELIMITER_ENDTIME){
			index = i;
			return true;
		}
	}
	return false;
}

//returns true if "-t" is found
//if found, it assigns index to the location of "-t"
bool Parser::isTaskNameDelimiterFound(vector<string> &inputVector, size_t &index) {
	for (unsigned int i = 0; i<inputVector.size(); i++){
		if (inputVector[i] == DELIMITER_TASKNAME){
			index = i;
			return true;
		}
	}
	return false;
}

//returns true if input is one of the delimiters (-t or -s or -e)
bool Parser::isDelimiter (string input) {
	if (input == DELIMITER_TASKNAME || input == DELIMITER_STARTTIME || input == DELIMITER_ENDTIME) {
		return true;
	} else {
		return false;
	}
}

void Parser::getEndingTime(vector<string> &inputVector) {
	string tempString = EMPTY_STRING;
	size_t index;
	if(isEndTimeDelimiterFound(inputVector, index)) {
		index++;
		while (index < inputVector.size() && !isDelimiter(inputVector[index])){
			tempString = tempString + WHITE_SPACE + inputVector[index];
			index++;
		}
		if (tempString.size() == ZERO) {
			_endDate = NULL_STRING;
			_endTime = NULL_STRING;		
		} else {
			unsigned int startIndex = 1;
			unsigned int partitionIndex = tempString.find_last_of(WHITE_SPACE);
			_endDate = tempString.substr(startIndex, partitionIndex-startIndex);
			_endDate = readDate(_endDate);
			_endTime = tempString.substr(partitionIndex+1);
			_endTime = verifyTime(_endTime);
		}
	} else {
		_endDate = NULL_STRING;
		_endTime = NULL_STRING;

	}
}

void Parser::getStartingTime(vector<string> &inputVector) {
	string tempString = EMPTY_STRING;
	size_t index;
	if(isStartTimeDelimiterFound(inputVector, index)) {
		index++;
		while (index < inputVector.size() && !isDelimiter(inputVector[index])){
			tempString = tempString + WHITE_SPACE + inputVector[index];
			index++;
		}
		if (tempString.size() == ZERO) {
			_startDate = NULL_STRING;
			_startTime = NULL_STRING;
		} else {
			unsigned int startIndex = 1;
			unsigned int partitionIndex = tempString.find_last_of(WHITE_SPACE);
			_startDate = tempString.substr(startIndex, partitionIndex-startIndex);
			_startDate = readDate(_startDate);
			_startTime = tempString.substr(partitionIndex+1);
			_startTime = verifyTime(_startTime);
		}
	} else {
		_startDate = NULL_STRING;
		_startTime = NULL_STRING;
	}
}

string Parser::verifyTime(string input) {
	if (input.size() == SIZE_TIME_STRING) {
		return input;
	}
	return NULL_STRING;
}

string Parser::readDate(string input) {
	if (isNumberFound(input)) {
		if (input.size() > 4) {
			return processDate(input);
		} else
			return NULL_STRING;
	} else {
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

bool Parser::isAlphabetFound(string input) {
	for (unsigned int i =0; i < input.size(); i++) {
		if (isalpha(input.at(i))) {
			return true;
		}
	}
	return false;
}

void Parser::getTaskName(vector<string> &inputVector) {
	string tempString = EMPTY_STRING;
	size_t index;
	if(isTaskNameDelimiterFound(inputVector, index)) {
		index++;
		while (index < inputVector.size() && !isDelimiter(inputVector[index])){
			tempString = tempString + WHITE_SPACE + inputVector[index];
			index++;
		}
		if (tempString.size() == ZERO) {
			_taskName = NULL_STRING;
		} else {
			_taskName = tempString.substr(1);
		}
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
	} else if (command == COMMAND_SAVE) {
		return SAVE;
	} else if (command == COMMAND_UNDO) {
		return UNDO;
	} else {
		return INVALID;
	}
}

void Parser::splitInput(vector<string>* inputVector, string input) {
	istringstream read(input);
	string temporaryString;
	
	while(read >> temporaryString) {
		inputVector->push_back(temporaryString);
	}
}

//@author A0116180R-reused
string Parser::processToday(){
	time_t t = time(0); 
	char tmp[64]; 
	strftime( tmp, sizeof(tmp), "%d%m%Y",localtime(&t) );  
	string today(tmp);

	return today;
}

string Parser::processTomorrow(){
	time_t t = time(0); 
	char tmp[64]; 
	strftime(tmp, sizeof(tmp), "%d%m%Y",localtime(&t));  
	string today(tmp);

	string day = today.substr(0,2);
	string month = today.substr(2,2);
	string year = today.substr(4,4);
	string monthYear = today.substr(2,6);
	int intDay = stringToInt(day);
	intDay++;
	if(checkEndOfMonth(intDay, month) == true){
		int intMonth = stringToInt(month);
		intMonth++;
		intDay = 1;
		day = intToString(intDay);
		month = intToString(intMonth);
		return day + month + year;
	}
	else{
		day = intToString(intDay);
		return day + monthYear;
	}
}

//@author A0116180R
bool Parser::checkEndOfMonth(int day, string month){
	if(month == "01" && day == 32){
		return true;
	}
	if(month == "02" && day == 29){
		return true;
	}
	if(month == "03" && day == 32){
		return true;
	}
	if(month == "04" && day == 31){
		return true;
	}
	if(month == "05" && day == 32){
		return true;
	}
	if(month == "06" && day == 31){
		return true;
	}
	if(month == "07" && day == 32){
		return true;
	}
	if(month == "08" && day == 32){
		return true;
	}
	if(month == "09" && day == 31){
		return true;
	}
	if(month == "10" && day == 32){
		return true;
	}
	if(month == "11" && day == 31){
		return true;
	}
	if(month == "12" && day == 32){
		return true;
	}

	return false;
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