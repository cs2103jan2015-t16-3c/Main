#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include "Task.h"
#include "Logger.h"
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
static const string TASK_ADDED = "Task added";
static const string TASK_MARKED_DONE = "Task marked as done";
static const string TASK_MARKED_UNDONE = "Task marked as undone";
static const string TASK_EDITED = "Task edited";
static const string TASK_DELETED = "Task deleted";
static const string TASK_DELETED_ALL = "All tasks deleted";
static const string TASKS_SORTED_ALPHABETICALLY = "Tasks sorted alphabetically";
static const string TASKS_SORTED_BY_DEADLINE = "Tasks sorted by deadline";

class TaskManager {
private:
	Logger logger;
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
	int addTask(string taskName, string startDate, string startTime, string endDate, string endTime);
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
	vector<Task>* retrieveOverdueTasks();
	void setCompletionStatus(int index, bool isComplete);
	void incrementTaskID();
	void updateTaskIDOnLoad();
	string getTaskName(int taskID);
	string getTaskType(int taskID);
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

	string TaskManager::processCurrentTime();
	string processToday();
	string processTomorrow();
	string intToString(int);
	int stringToInt(string);
	string retrieveTodayDate();
	string convertDate(string date);
	bool checkEndOfMonth(int day, string month);
	bool isTaskStillOngoing(Task taskInput, string timeIndicator);
	bool isDate1BeforeDate2(string date1, string date2);
};

#endif