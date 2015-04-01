#include "TaskManager.h"

int TaskManager::_nextTaskID = 1;

TaskManager::TaskManager() {
}

TaskManager::~TaskManager() {
	//destructor
}

TaskManager* TaskManager::getInstance() {
	if (_instance == NULL) {
		_instance = new TaskManager();
	}
	return _instance;
}

void TaskManager::append(Task task) {
	_tasks.push_back(task);
}

//assigns a task a unique ID and adds it to vector
void TaskManager::addTask(Task task) {
	task.setTaskID(_nextTaskID);
	_nextTaskID++;
	_tasks.push_back(task);
}

void TaskManager::deleteTask(vector<Task>& _tasks, int taskIDToDelete) {
	vector<Task>::iterator it;
	for (it = _tasks.begin(); it != _tasks.end(); ) {
        if ((*it).getTaskID() == taskIDToDelete) {
            // store the return value from erase
            it = _tasks.erase(it);
        }
        else {
            it++;
        }
    }
}

vector<Task>* TaskManager::retrieveTimedTask(string timeIndicator) {
	vector<Task> timedTaskVector;
	getTimedTaskVector(timedTaskVector);
	if (timeIndicator != TASK_TYPE_ALL) {
		vector<Task>* newVector = new vector<Task>;	
		for (unsigned int i = 0; i < timedTaskVector.size(); i++) {
			if (timedTaskVector[i].getStartDate() == timeIndicator) {
				newVector->push_back(timedTaskVector[i]);
			}
		}
		return newVector;
	} 
	else {
		return &timedTaskVector;
	}
}

void TaskManager::getTimedTaskVector(vector<Task> &timedTaskVector){
	for (unsigned int i = 0; i < _tasks.size(); i++) {
		if (_tasks[i].getType() == TASK_TYPE_TIMED) {
			timedTaskVector.push_back(_tasks[i]);
		}
	}
}

vector<Task>* TaskManager::retrieveFloatingTask(string timeIndicator) {
	vector<Task> floatingTaskVector;
	getFloatingTaskVector(floatingTaskVector);
	if (timeIndicator != TASK_TYPE_ALL) {
		vector<Task>* newVector = new vector<Task>;	
		for (unsigned int i = 0; i < floatingTaskVector.size(); i++) {
			if (floatingTaskVector[i].getStartDate() == timeIndicator) {
				newVector->push_back(floatingTaskVector[i]);
			}
		}
		return newVector;
	} 
	else {
		return &floatingTaskVector;
	}
}

void TaskManager::getFloatingTaskVector(vector<Task> &floatingTaskVector) {
	vector<Task>* newVector = new vector<Task>;
	for (unsigned int i = 0; i < _tasks.size(); i++) {
		if (_tasks[i].getType() == TASK_TYPE_FLOATING) {
			floatingTaskVector.push_back(_tasks[i]);
		}
	}
}

vector<Task>* TaskManager::retrieveDeadline(string timeIndicator) {
	vector<Task> deadlineVector;
	getDeadlineVector(deadlineVector);
	if (timeIndicator != "TASK_TYPE_ALL") {
		vector<Task>* newVector = new vector<Task>;	
		for (unsigned int i = 0; i < deadlineVector.size(); i++) {
			if (deadlineVector[i].getStartDate() == timeIndicator) {
				newVector->push_back(deadlineVector[i]);
			}
		}
		return newVector;
	} 
	else {
		return &deadlineVector;
	}
}

void TaskManager::getDeadlineVector(vector<Task> &deadlineVector) {
	vector<Task>* newVector = new vector<Task>;
	for (unsigned int i = 0; i < _tasks.size(); i++) {
		if (_tasks[i].getType() == TASK_TYPE_DEADLINE) {
			deadlineVector.push_back(_tasks[i]);
		}
	}
}

//void TaskManager::setCompletionStatus(int index, bool isComplete) {
	//_tasks[index - 1].setCompletionStatus(isComplete);
//}

//requires user to key in all 5 fields even if not editing them
void TaskManager::editTask(int editIndex, string taskName, string startDate, string startTime, string endDate, string endTime) {
	_tasks[editIndex - 1].setTaskName(taskName);
	_tasks[editIndex - 1].setStartDate(startDate);
	_tasks[editIndex - 1].setStartTime(startTime);
	_tasks[editIndex - 1].setEndDate(endDate);
	_tasks[editIndex - 1].setEndTime(endTime);
}

void TaskManager::clearAllTasks() {
	_tasks.clear();
}

//returns a vector of Tasks with searchTerm as a substring of taskName
vector<Task> TaskManager::searchForString(string searchTerm) {
	vector<Task> searchResults;
	for (unsigned int i = 0; i < _tasks.size(); i++) {
		if (_tasks[i].getTaskName().find(searchTerm) != string::npos) {
			searchResults.push_back(_tasks[i]);
		}
	}
	return searchResults;
}

//returns a vector of Tasks with endDate equal to todaysDate
vector<Task> TaskManager::searchForTasksDueToday(string todaysDate) {
	vector<Task> searchResults;
	for (unsigned int i = 0; i < _tasks.size(); i++) {
		//if (_tasks[i].getEndDate() == "x") { //call parser to get todaysDate
			searchResults.push_back(_tasks[i]);
		//}
	}
	return searchResults;
}

void TaskManager::sortTasksByName() {
	CompareTaskName compareName;
	sort(_tasks.begin(), _tasks.end(), compareName);
}

void TaskManager::sortTasksByNearestDeadline() {
	CompareTaskEndDate compareEndDate;
	CompareTaskEndTime compareEndTime;
	sort(_tasks.begin(), _tasks.end(), compareEndTime);
	sort(_tasks.begin(), _tasks.end(), compareEndDate);
}

void TaskManager::save(const char* fileName){
    // make an archive
    std::ofstream ofs(fileName);
    boost::archive::text_oarchive oa(ofs);
    oa << _tasks;
}

void TaskManager::load(const char* fileName) {
	 // open the archive
    std::ifstream ifs(fileName);
    boost::archive::text_iarchive ia(ifs);
    ia >> _tasks;
}

