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
	if (getCommandType(inputVector[0]) == ADD) {
			getTaskName(inputVector);
			getStartTime(inputVector);
			getEndTime(inputVector);
			getType();
			CommandAdd addTask(_taskName, _startDate, _startTime, _endDate, _endTime, _type);
			return addTask;
//			break;
	} else if (getCommandType(inputVector[0]) == DELETE) {
//		case DELETE:
			getIndex(inputVector);
			CommandDelete deleteTask(_index, _currentDisplay);
			return deleteTask;}
//			break;
/*		case DISPLAY:
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
//		case EXIT:
	//		break;
	//}
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

string Parser::processToday(){
	time_t t = time(0); 
	char tmp[64]; 
	strftime( tmp, sizeof(tmp), "%d%m%Y",localtime(&t) );  
	string today(tmp);

	return today;
}

MONTH_NAME Parser::determineMonthName(string month) {

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
		vector<string> temp;
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
	string taskName = taskName;
	string startDate = startDate;
	string startTime = startTime;
	string endDate = endDate;
	string endTime = endTime;
	string type = type;
	if (type == "timed") {
		return taskName + "\tStart: " + startDate + "\t(" + startTime + ")\tEnd: " + endDate + "\t(" + endTime + ")";
	} else if (type == "deadline") {
		return taskName + "\tDeadline: " + endDate + "\t(" + endTime + ")!!!!";
	} else if (type == "floating") {
		return taskName;
	}
}