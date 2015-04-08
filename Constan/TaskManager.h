#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include "Task.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <functional>
#include <iostream>
#include <assert.h>
#include <time.h>

using namespace std;

static const string MATCH_FOUND = "The following entries match your query: ";
static const string WHITE_SPACE = " ";
static const string CANNOT_FIND_TASK = "CANNOT FIND TASK";
static const string FILE_NAME_KEEPER = "filename.txt";
static const string DISPLAY_TODAY = "today";
static const string DISPLAY_TOMORROW = "tomorrow";
static const string DISPLAY_ALL = "all";

class TaskManager {
private:
	vector<Task> _tasks;
//	static TaskManager* _instance;
	TaskManager();
	TaskManager(TaskManager const&);
	void operator=(TaskManager const&);
	Task* _newTask;
	int _taskID;
	string _type;
	string _fileName;
	string _timeIndicator;
public:
	static TaskManager* getInstance();
	~TaskManager();
	void setFileName(string fileName);
	void saveFileName();
	string retrieveFileName();
	void save();
	void load();
	void addTask(string taskName, string startDate, string startTime, string endDate, string endTime, int taskID);
	void editTask(int taskID, string taskName, string startDate, string startTime, string endDate, string endTime);
	void overwriteTask(int taskID, string taskName, string startDate, string startTime, string endDate, string endTime, bool isComplete);
	void markTask(int taskID);
	void unmarkTask(int taskID);
	void deleteTask(int taskID);
	void clearAllTasks();
	vector<Task>* searchForString(string keyword);
	vector<Task> retrieveTodaysTasks(string todaysDate);
	vector<Task>* retrieveTimedTask(string timeIndicator);
	void getTimedTaskVector(vector<Task>* timedTaskVector);
	vector<Task>* retrieveFloatingTask(string timeIndicator);
	void getFloatingTaskVector(vector<Task>* floatingTaskVector);
	vector<Task>* retrieveDeadline(string timeIndicator);
	void getDeadlineVector(vector<Task>* deadlineVector);
	void setCompletionStatus(int index, bool isComplete);
	void incrementTaskID();
	void updateTaskIDOnLoad();
	string getTaskName(int taskID);
	string processTimeIndicator(string input);
	Task* findTask(int taskID);
	string getType (string taskName, string startDate, string startTime, string endDate, string endTime);
	void sortTasksByAscendingAlphabet();
	void sortTasksByNearestDeadline();
	void getTaskDetails(int taskID, string &prevTaskName, string &prevStartDate, string &prevStartTime, string &prevEndDate, string &prevEndTime, bool &isPrevComplete);

	//the following are support functions
	vector<string> splitParameters(string wholeTask); 
	int convertTaskIDToInt(string taskID);
	string convertVectorToString(vector<string> taskName);
	bool convertStatusToBool(string completionStatus);
	static bool TaskManager::keyLowestAlphabet(Task& a, Task& b);
	static bool TaskManager::keyNearestDeadline(Task& a, Task& b);

	string processToday();
	string processTomorrow();
	string intToString(int);
	int stringToInt(string);
};

#endif