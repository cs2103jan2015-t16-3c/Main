#include "TaskManager.h"

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

//Read and Write might need to be moved to a separate class
void readFromFile(vector<Task>& _tasks, char *argv[]) {
	Task data; 
	ifstream ifs(argv[1]);
	while (getline(ifs, data) ) { 
		_tasks.push_back(data); 
	} 
	ifs.close();
}

void writeToFile(vector<Task>& _tasks, char *argv[]) {
	ofstream ofs; 
	ofs.open(argv[1], ofstream::out | ofstream::trunc); 
	for (int i = 0; i < _tasks.size(); i++) { 
		ofs << _tasks[i] << endl; 
	} 
	ofs.close();
}

void TaskManager::addTask(Task task) {
	_tasks.push_back(task);
}

void TaskManager::deleteTask(int deleteIndex) {
	_tasks.erase(_tasks.begin() + deleteIndex - 1);
}

vector<Task>* TaskManager::retrieveTimedTask(string timeIndicator) {
	vector<Task> timedTaskVector;
	getTimedTaskVector(timedTaskVector);
	if (timeIndicator != "all") {
		vector<Task>* newVector = new vector<Task>;	
		for (int i = 0; i < timedTaskVector.size(); i++) {
			if (timedTaskVector[i].getStartDate() == timeIndicator) {
				newVector->push_back(timedTaskVector[i]);
			}
		}
		return newVector;
	} else {
		return &timedTaskVector;
	}
}

void TaskManager::getTimedTaskVector(vector<Task> &timedTaskVector){
	for (int i = 0; i < _tasks.size(); i++) {
		if (_tasks[i].getType() == "timed") {
			timedTaskVector.push_back(_tasks[i]);
		}
	}
}

vector<Task>* TaskManager::retrieveFloatingTask(string timeIndicator) {
	vector<Task> floatingTaskVector;
	getFloatingTaskVector(floatingTaskVector);
	if (timeIndicator != "all") {
		vector<Task>* newVector = new vector<Task>;	
		for (int i = 0; i < floatingTaskVector.size(); i++) {
			if (floatingTaskVector[i].getStartDate() == timeIndicator) {
				newVector->push_back(floatingTaskVector[i]);
			}
		}
		return newVector;
	} else {
		return &floatingTaskVector;
	}
}

void TaskManager::getFloatingTaskVector(vector<Task> &floatingTaskVector) {
	vector<Task>* newVector = new vector<Task>;
	for (int i = 0; i < _tasks.size(); i++) {
		if (_tasks[i].getType() == "floating") {
			floatingTaskVector.push_back(_tasks[i]);
		}
	}
}

vector<Task>* TaskManager::retrieveDeadline(string timeIndicator) {
	vector<Task> deadlineVector;
	getDeadlineVector(deadlineVector);
	if (timeIndicator != "all") {
		vector<Task>* newVector = new vector<Task>;	
		for (int i = 0; i < deadlineVector.size(); i++) {
			if (deadlineVector[i].getStartDate() == timeIndicator) {
				newVector->push_back(deadlineVector[i]);
			}
		}
		return newVector;
	} else {
		return &deadlineVector;
	}
}

void TaskManager::getDeadlineVector(vector<Task> &deadlineVector) {
	vector<Task>* newVector = new vector<Task>;
	for (int i = 0; i < _tasks.size(); i++) {
		if (_tasks[i].getType() == "deadline") {
			deadlineVector.push_back(_tasks[i]);
		}
	}
}

//void TaskManager::setCompletionStatus(int index, bool isComplete) {
	//_tasks[index - 1].setCompletionStatus(isComplete);
//}

//requires user to key in all 3 fields even if not editing them
void TaskManager::editTask(int editIndex, string taskName, string startTime, string endTime) {
	_tasks[editIndex - 1].setTaskName = taskName;
	_tasks[editIndex - 1].setStartTime = startTime;
	_tasks[editIndex - 1].setEndTime = endTime;
}

void TaskManager::clearAllTasks() {
	_tasks.clear();
}

void TaskManager::searchForString(string searchTerm) {
	int matchIndex;
	TextUI::printMessage(MATCH_FOUND);
	for (int i = 0; i < _tasks.size(); i++) {
		if (_tasks[i].getTaskName().find(searchTerm) != string::npos) {
			matchIndex = i + 1;
			TextUI::printIndex(matchIndex);
			TextUI::printMessage("\n");
		}
	}
}

//void TaskManager::sortTasksByAscendingAlphabet(vector<Task> _tasks) {
	//Task temp;
	//bool isSorted = false;
	//for (int i = 0; i < _tasks.size(); i++) {
		//isSorted = true;
		//for (int j = 1; j < _tasks.size() - i; j++) {
			//if (_tasks[j - 1].getTaskName() > _tasks[j].getTaskName())
				//temp = _tasks[j - 1];
			//_tasks[j - 1] = _tasks[j];
			//_tasks[j] = temp;
			//isSorted = false;
		//}
	//}
	//if (isSorted) return;
//}

void TaskManager::sortTasksByNearestDeadline(vector<Task> _tasks) {
	Task temp;
	bool isSorted = false;
	for (int i = 0; i < _tasks.size(); i++) {
		isSorted = true;
		for (int j = 1; j < _tasks.size() - i; j++) {
			if (_tasks[j - 1].getEndTime() > _tasks[j].getEndTime())
				temp = _tasks[j - 1];
			_tasks[j - 1] = _tasks[j];
			_tasks[j] = temp;
			isSorted = false;
		}
	}
	if (isSorted) return;
}
