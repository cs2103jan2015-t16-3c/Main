#include "TaskManager.h"

TaskManager::TaskManager() {
	TaskManager* taskManagerPointer = new TaskManager;
}

TaskManager::~TaskManager() {
	//destructor
}

//Read and Write might need to be moved to a separate class
void readFromFile(vector<Task>& _tasks, char *argv[]) {
	//Task data; 
	//ifstream ifs(argv[1]);
	//while (getline(ifs, data)) { 
	//	_tasks.push_back(data); 
	//} 
	//ifs.close();
}

void writeToFile(vector<Task>& _tasks, char *argv[]) {
	//ofstream ofs; 
	//ofs.open(argv[1], ofstream::out | ofstream::trunc); 
	//for (int i = 0; i < _tasks.size(); i++) { 
	//	ofs << _tasks[i] << endl; 
	//} 
	//ofs.close();
}

void TaskManager::addTask(Task task) {
	_tasks.push_back(task);
}

void TaskManager::deleteTask(int deleteIndex) {
	_tasks.erase(_tasks.begin() + deleteIndex - 1);
}

void TaskManager::setCompletionStatus(int index, bool isComplete) {
	_tasks[index - 1].setCompletionStatus(isComplete);
}

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

void TaskManager::sortTasksByAscendingAlphabet(vector<Task> _tasks) {
	Task temp;
	bool isSorted = false;
	for (int i = 0; i < _tasks.size(); i++) {
		isSorted = true;
		for (int j = 1; j < _tasks.size() - i; j++) {
			if (_tasks[j - 1].getTaskName() > _tasks[j].getTaskName())
				temp = _tasks[j - 1];
			_tasks[j - 1] = _tasks[j];
			_tasks[j] = temp;
			isSorted = false;
		}
	}
	if (isSorted) return;
}

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
