#include "TaskManager.h"

TaskManager::TaskManager() {
	load();
	updateTaskIDOnLoad();
	string fileName;
	fileName = retrieveFileName();
	setFileName(fileName);
}

TaskManager::~TaskManager() {
	//destructor
}

TaskManager* TaskManager::getInstance() {
	static TaskManager _instance;
	return &_instance;
}

void TaskManager::setFileName(string fileName) {
	_fileName = fileName;
	saveFileName();
}

//stores the file name/path in "filename.txt"
//"filename.txt" will only have one line which is the last file path the user used
void TaskManager::saveFileName() {
	ofstream ofs;
	ofs.open(FILE_NAME_KEEPER, ofstream::out | ofstream::trunc);
	ofs << _fileName << endl;
	ofs.close();
}

string TaskManager::retrieveFileName() {
	string fileName;
	ifstream ifs(FILE_NAME_KEEPER);
	getline(ifs, fileName);

	return fileName;
}

//combines all task data attributes into one string with white spaces between fields
//and writes these strings to file line by line
//one line represents all the data for one task
//the order of arrangement is as per the function
//the file is cleared before every save operation and the entire vector is re-written
void TaskManager::save() {
	ofstream ofs;
	ofs.open(_fileName, ofstream::out | ofstream::trunc);
	string wholeTask;
	for (unsigned int i = 0; i < _tasks.size(); i++) {
		 wholeTask = _tasks[i].getTaskName() + WHITE_SPACE +
					 _tasks[i].getTaskIDAsString() + WHITE_SPACE +
					 _tasks[i].getType() + WHITE_SPACE +
					 _tasks[i].getStartDate() + WHITE_SPACE +
					 _tasks[i].getStartTime() + WHITE_SPACE +
					 _tasks[i].getEndDate() + WHITE_SPACE +
					 _tasks[i].getEndTime() + WHITE_SPACE +
					 _tasks[i].getCompletionStatusAsString();
		 ofs << wholeTask << endl;
	}
	ofs.close();
}

//reads a file of strings line by line
//each line representing a task is stored as an individual vector
//a new task is constructed from this data and saved to _tasks
void TaskManager::load() {
	TaskManager* getInstance();
	_tasks.clear();

	string wholeTask;
	vector<string> splitTask;
	ifstream ifs(_fileName);

	string tempTaskName;
	string tempTaskID;
	string tempType;
	string tempStartDate;
	string tempStartTime;
	string tempEndDate;
	string tempEndTime;
	string tempCompletionStatus;
	int tempTaskIDInt;
	bool tempIsCompleteBool;

	while (getline(ifs, wholeTask)) {
		splitTask = splitParameters(wholeTask);

		tempCompletionStatus = splitTask[splitTask.size() - 1];
		splitTask.pop_back();
		tempEndTime = splitTask[splitTask.size() - 1];
		splitTask.pop_back();
		tempEndDate = splitTask[splitTask.size() - 1];
		splitTask.pop_back();
		tempStartTime = splitTask[splitTask.size() - 1];
		splitTask.pop_back();
		tempStartDate = splitTask[splitTask.size() - 1];
		splitTask.pop_back();
		tempType = splitTask[splitTask.size() - 1];
		splitTask.pop_back();
		tempTaskID = splitTask[splitTask.size() - 1];
		splitTask.pop_back();
		tempTaskName = convertVectorToString(splitTask); //remainder of vector is taskName

		tempTaskIDInt = convertTaskIDToInt(tempTaskID);
		tempIsCompleteBool = convertStatusToBool(tempCompletionStatus);

		Task reconstructedTask(tempTaskName, tempTaskIDInt, tempType, tempStartDate, tempStartTime, tempEndDate, tempEndTime, tempIsCompleteBool);
		_tasks.push_back(reconstructedTask);
	}
	ifs.close();
}

void TaskManager::addTask(string taskName, string startDate, string startTime, string endDate, string endTime, int taskID) {
	string type;
	type = getType(taskName, startDate, startTime, endDate, endTime);
	_newTask = new Task(taskName, startDate, startTime, endDate, endTime, type);
//	incrementTaskID();
	_newTask->setTaskID (taskID);
	_tasks.push_back(*_newTask);
	
	save();
	logger.log(TASK_ADDED);
}

void TaskManager::markTask(int taskID) {
	Task* taskToMark = findTask(taskID);
	taskToMark->setCompletionStatus(true);

	save();
	logger.log(TASK_MARKED_DONE);
}

void TaskManager::unmarkTask(int taskID) {
	Task* taskToMark = findTask(taskID);
	taskToMark->setCompletionStatus(false);

	save();
	logger.log(TASK_MARKED_UNDONE);
}

void TaskManager::getTaskDetails(int taskID, string &prevTaskName, string &prevStartDate, string &prevStartTime, string &prevEndDate, string &prevEndTime, bool &isPrevComplete) {
	Task* taskToInspect = findTask(taskID);
	prevTaskName = taskToInspect->getTaskName();
	prevStartDate = taskToInspect->getStartDate();
	prevStartTime = taskToInspect->getStartTime();
	prevEndDate = taskToInspect->getEndDate();
	prevEndTime = taskToInspect->getEndTime();
	isPrevComplete = taskToInspect->getCompletionStatus();
}

void TaskManager::editTask(int taskID, string taskName, string startDate, string startTime, string endDate, string endTime) {
	Task* taskToEdit = findTask(taskID);
	if (taskName != DEFAULT_TASK_NAME && taskName != EMPTY_STRING) {
		taskToEdit->setTaskName(taskName);
	}
	if (startDate != DEFAULT_START_DATE && startDate != EMPTY_STRING) {
		taskToEdit->setStartDate(startDate);
	}
	if (startTime != DEFAULT_START_TIME && startTime != EMPTY_STRING) {
		taskToEdit->setStartTime(startTime);
	}
	if (endDate != DEFAULT_END_DATE && endDate != EMPTY_STRING) {
		taskToEdit->setEndDate(endDate);
	}
	if (endTime != DEFAULT_END_TIME && endTime != EMPTY_STRING) {
		taskToEdit->setEndTime(endTime);
	}
	_type = getType(taskToEdit->getTaskName(), taskToEdit->getStartDate(), taskToEdit->getStartTime(), taskToEdit->getEndDate(), taskToEdit->getEndTime());
	taskToEdit->setType(_type);

	save();
}

//completely overwrites a task
void TaskManager::overwriteTask(int taskID, string taskName, string startDate, string startTime, string endDate, string endTime, bool isComplete) {
	Task* taskToEdit = findTask(taskID);	
	taskToEdit->setTaskName(taskName);	
	taskToEdit->setStartDate(startDate);	
	taskToEdit->setStartTime(startTime);		
	taskToEdit->setEndDate(endDate);
	taskToEdit->setEndTime(endTime);
	_type = getType(taskToEdit->getTaskName(), taskToEdit->getStartDate(), taskToEdit->getStartTime(), taskToEdit->getEndDate(), taskToEdit->getEndTime());
	taskToEdit->setType(_type);
	taskToEdit->setCompletionStatus(isComplete);

	save();
	logger.log(TASK_EDITED);
}

//returns type of task depending on task information
string TaskManager::getType(string taskName, string startDate, string startTime, string endDate, string endTime) {
	if (startTime != DEFAULT_START_TIME && endTime != DEFAULT_END_TIME) {
		return TASK_TYPE_TIMED;
	} 
	else if (startTime == DEFAULT_START_TIME && endTime != DEFAULT_END_TIME) {
		return TASK_TYPE_DEADLINE;
	} 
	else {
		return TASK_TYPE_FLOATING;
	}
}

Task* TaskManager::findTask(int taskID) {
	vector<Task>::iterator taskIter;
	for (taskIter= _tasks.begin() ; taskIter != _tasks.end() ; taskIter++) {
		if (taskIter->getTaskID() == taskID) {
			return &(*taskIter);
		}
	}
	return NULL;
}

string TaskManager::getTaskName(int taskID) {
	vector<Task>::iterator taskIter;
	for (taskIter= _tasks.begin(); taskIter != _tasks.end(); taskIter++) {
		if (taskIter->getTaskID() == taskID) {
			return taskIter->getTaskName();
		}
	}
	return CANNOT_FIND_TASK;
}

string TaskManager::getTaskType(int taskID) {
	vector<Task>::iterator taskIter;
	for (taskIter= _tasks.begin(); taskIter != _tasks.end(); taskIter++) {
		if (taskIter->getTaskID() == taskID) {
			return taskIter->getType();
		}
	}
	return CANNOT_FIND_TASK;
}

void TaskManager::incrementTaskID() {
	_taskID++;
}

void TaskManager::updateTaskIDOnLoad() {
	int maxTaskID = 0;
	for (unsigned int i = 0; i < _tasks.size(); i++) {
		if (_tasks[i].getTaskID() > maxTaskID) {
			maxTaskID = _tasks[i].getTaskID();
		}
	}
	_taskID = maxTaskID + 1;
}

//deletes task with the matching task ID
void TaskManager::deleteTask(int taskID) {
	for (unsigned int i = 0; i < _tasks.size(); i++) {
		if (_tasks[i].getTaskID() == taskID) {
			_tasks.erase(_tasks.begin() + i);
		}
	}
	save();
	logger.log(TASK_DELETED);
}

void TaskManager::clearAllTasks() {
	_tasks.clear();
	save();
	logger.log(TASK_DELETED_ALL);
}

string TaskManager::retrieveTodayDate() {
	return processToday();
}

//takes in a word to search for
//returns a vector of Tasks in whose name the search term appears
vector<Task>* TaskManager::searchForString(string keyword) {
	vector<Task>* resultVector = new vector<Task>;
	vector<Task>::iterator taskIter;
	string taskName;
	for (taskIter = _tasks.begin(); taskIter != _tasks.end(); taskIter++) {
		taskName = (*taskIter).getTaskName();
		if (taskName.find(keyword) != -1) {
			resultVector->push_back(*taskIter);
		}
	}
	return resultVector;
}

//takes in todays date in YYYYMMDD format
//returns a vector of Tasks due "today"
vector<Task> TaskManager::retrieveTodaysTasks(string todaysDate) {
	vector<Task> searchResults;
	for (unsigned int i = 0; i < _tasks.size(); i++) {
		if (_tasks[i].getEndDate() == todaysDate) {
			searchResults.push_back(_tasks[i]);
		}
	}
	return searchResults;
}

string TaskManager::processTimeIndicator(string input) {
	if (input == DISPLAY_TODAY) {
		return processToday();
	} else if (input == DISPLAY_TOMORROW) {
		return processTomorrow();
	} else if (input == DISPLAY_ALL){
		return DISPLAY_ALL;
	} else {
		return input;
	}
}

vector<Task>* TaskManager::retrieveTimedTask(string timeIndicator) {
	vector<Task>* timedTaskVector = new vector<Task>;
	_timeIndicator = processTimeIndicator(timeIndicator);
	getTimedTaskVector(timedTaskVector);
	if (_timeIndicator != TASK_TYPE_ALL) {
		vector<Task>* newVector = new vector<Task>;	
		for (unsigned int i = 0; i < timedTaskVector->size(); i++) {
			if (timedTaskVector->at(i).getStartDate() == _timeIndicator) {
				newVector->push_back(timedTaskVector->at(i));
			}
		}
		return newVector;
	} 
	else {
		return timedTaskVector;
	}
}

vector<Task>* TaskManager::retrieveFloatingTask(string timeIndicator) {
	vector<Task>* floatingTaskVector = new vector<Task>;
	_timeIndicator = processTimeIndicator(timeIndicator);
	getFloatingTaskVector(floatingTaskVector);
	if (_timeIndicator != TASK_TYPE_ALL) {
		vector<Task>* newVector = new vector<Task>;	
		for (unsigned int i = 0; i < floatingTaskVector->size(); i++) {
			if (floatingTaskVector->at(i).getStartDate() == _timeIndicator) {
				newVector->push_back(floatingTaskVector->at(i));
			}
		}
		return newVector;
	} 
	else {
		return floatingTaskVector;
	}
}

vector<Task>* TaskManager::retrieveDeadline(string timeIndicator) {
	vector<Task>* deadlineVector = new vector<Task>;
	_timeIndicator = processTimeIndicator(timeIndicator);
	getDeadlineVector(deadlineVector);
	if (_timeIndicator != TASK_TYPE_ALL) {
		vector<Task>* newVector = new vector<Task>;	
		for (unsigned int i = 0; i < deadlineVector->size(); i++) {
			if (deadlineVector->at(i).getEndDate() == _timeIndicator) {
				newVector->push_back(deadlineVector->at(i));
			}
		}
		return newVector;
	} else {
		return deadlineVector;
	}
}

void TaskManager::getTimedTaskVector(vector<Task>* timedTaskVector){
	for (unsigned int i = 0; i < _tasks.size(); i++) {
		if (_tasks[i].getType() == TASK_TYPE_TIMED) {
			timedTaskVector->push_back(_tasks[i]);
		}
	}
}

void TaskManager::getFloatingTaskVector(vector<Task>* floatingTaskVector) {
	for (unsigned int i = 0; i < _tasks.size(); i++) {
		if (_tasks[i].getType() == TASK_TYPE_FLOATING) {
			floatingTaskVector->push_back(_tasks[i]);
		}
	}
}

void TaskManager::getDeadlineVector(vector<Task>* deadlineVector) {
	for (unsigned int i = 0; i < _tasks.size(); i++) {
		if (_tasks[i].getType() == TASK_TYPE_DEADLINE) {
			deadlineVector->push_back(_tasks[i]);
		}
	}
}

vector<Task>* TaskManager::retrieveOverdueTasks() {
	vector<Task>* overdueTasks;
	string todaysDate = convertDate(retrieveTodayDate());
	string now = processCurrentTime();

	for (unsigned int i = 0; i < _tasks.size(); i++) {
		if (todaysDate > convertDate(_tasks[i].getEndDate())) {
			overdueTasks->push_back(_tasks.at(i));	
		}
		else if (todaysDate == convertDate(_tasks[i].getEndDate()) && now > _tasks[i].getEndTime()) {
			overdueTasks->push_back(_tasks.at(i));  
		}
	}

	return overdueTasks;
}

void TaskManager::setCompletionStatus(int index, bool isComplete) {
	_tasks[index - 1].setCompletionStatus(isComplete);
	save();
}

void TaskManager::sortTasksByAscendingAlphabet() {
	sort(_tasks.begin(), _tasks.end(), keyLowestAlphabet);
	save();
	logger.log(TASKS_SORTED_ALPHABETICALLY);
}

void TaskManager::sortTasksByNearestDeadline() {
	sort(_tasks.begin(), _tasks.end(), keyNearestDeadline);
	save();
	logger.log(TASKS_SORTED_BY_DEADLINE);
}

//takes in a string with all task info concatenated with whitespace between words
//returns a vector of strings containing the individual words
vector<string> TaskManager::splitParameters(string wholeTask) {
	vector<string> tokens;
	istringstream iss(wholeTask);
    copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             back_inserter<vector<string> >(tokens));

	return tokens;
}

int TaskManager::convertTaskIDToInt(string taskID) {
	int taskIDInt;
    istringstream ss(taskID);
    ss.imbue(locale::classic());
    ss >> taskIDInt;

    return taskIDInt;
}

//takes in a vector containing words
//and joins them to recreate the _taskName
//while adding whitespaces after the first word
string TaskManager::convertVectorToString(vector<string> taskName) {
	string taskNameString;
	stringstream ss;
	for (unsigned int i = 0; i < taskName.size(); i++) {
		if (i > 0) {
			ss << WHITE_SPACE;
		}
		ss << taskName[i];
	}
	taskNameString = ss.str();

	return taskNameString;
}

bool TaskManager::convertStatusToBool(string completionStatus) {
	assert(completionStatus == COMPLETION_TRUE || completionStatus == COMPLETION_FALSE);
	if (completionStatus == COMPLETION_TRUE) {
		return true;
	}
	else {
		return false;
	}
}

//sorting predicate for sorting by task name
bool TaskManager::keyLowestAlphabet(Task& a, Task& b) { 
   if (a.getTaskName() != b.getTaskName()) {
	   return (a.getTaskName() < b.getTaskName());
   }
   else {
	   return false;
   }
} 

//sorting predicate for sorting by deadline
//date is in DDMMYYYY format, so compare year by taking substring, followed by month then day
//for sorting tasks by end date and within each tier sort again by end time
bool TaskManager::keyNearestDeadline(Task& a, Task& b) { 
   if (a.getEndDate().substr(4, 4) != b.getEndDate().substr(4, 4)) {
	   return (a.getEndDate().substr(4, 4) < b.getEndDate().substr(4, 4));
   }
   else if (a.getEndDate().substr(2, 2) != b.getEndDate().substr(2, 2)) {
	   return (a.getEndDate().substr(2, 2) < b.getEndDate().substr(2, 2));
   }
   else if (a.getEndDate().substr(0, 2) != b.getEndDate().substr(0, 2)) {
	   return (a.getEndDate().substr(0, 2) < b.getEndDate().substr(0, 2));
   }
   else if (a.getEndTime() != b.getEndTime()) {
	   return (a.getEndTime() < b.getEndTime());
   }
   else {
	   return false;
   }
} 

string TaskManager::processCurrentTime() {
	time_t t = time(0); 
	char tmp[64]; 
	strftime( tmp, sizeof(tmp), "%H%M",localtime(&t) );  
	string now(tmp);

	return now;
}

string TaskManager::convertDate(string date) {
	string yearMonthDayFormat;
	yearMonthDayFormat = date.substr(4,4) + date.substr(2,2) + date.substr(0,2);

	return yearMonthDayFormat;
}

string TaskManager::processToday(){
	time_t t = time(0); 
	char tmp[64]; 
	strftime( tmp, sizeof(tmp), "%d%m%Y",localtime(&t) );  
	string today(tmp);

	return today;
}

string TaskManager::processTomorrow(){
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

bool TaskManager::checkEndOfMonth(int day, string month){
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

string TaskManager::intToString(int inputInt){

	stringstream outputStream;

	if(inputInt < 10){
		outputStream << '0' << inputInt;
	} else {
		outputStream << inputInt;
	}

	return outputStream.str();
}

int TaskManager::stringToInt(string inputString){
	int outputInt;
	istringstream outputStream(inputString);

	outputStream >> outputInt;

	return outputInt;
}