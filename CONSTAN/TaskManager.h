#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include "Task.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

static const string MATCH_FOUND = "The following entries match your query: ";

class TaskManager {
private:
	vector<Task> _tasks;
	TaskManager* _instance;
	TaskManager();
	Task* _newTask;
	int _taskID;
	string _type;

public:
	static TaskManager* getInstance();
	~TaskManager();
	void readFromFile(vector<Task>& _tasks, char *argv[]);
	void writeToFile(vector<Task>& _tasks, char *argv[]);
	void addTask(string taskName, string startDate, string startTime, string endDate, string endTime, string type, int taskID);
	void deleteTask(int taskID);
	vector<Task>* retrieveTimedTask(string timeIndicator);
	void getTimedTaskVector(vector<Task>& timedTaskVector);
	vector<Task>* retrieveFloatingTask(string timeIndicator);
	void getFloatingTaskVector(vector<Task>& floatingTaskVector);
	vector<Task>* retrieveDeadline(string timeIndicator);
	void getDeadlineVector(vector<Task>& deadlineVector);
	//void setCompletionStatus(int index, bool isComplete);
	void editTask(int editIndex, string taskName, string startTime, string endTime);
	void clearAllTasks();
	vector<Task>* searchForString(string keyword);
	//void sortTasksByAscendingAlphabet(vector<Task> _tasks);
	void sortTasksByNearestDeadline(vector<Task> _tasks);
	void incrementTaskID();
	string getTaskName(int taskID);
	void editTask(int taskID, string taskName, string startDate, string startTime, string endDate, string endTime);
	Task* findTask(int taskID);
	string getType (string taskName, string startDate, string startTime, string endDate, string endTime);
};

#endif