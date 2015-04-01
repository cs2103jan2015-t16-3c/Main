#pragma once

#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include "Task.h"
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <boost/serialization/vector.hpp>

using namespace std;
using namespace boost;

static const string MATCH_FOUND = "The following entries match your query: ";

struct CompareTaskName {
   bool operator()(const Task& a, const Task& b) const {
      return a.getTaskName() < b.getTaskName();
   }
};

struct CompareTaskEndDate {
   bool operator()(const Task& a, const Task& b) const {
      return a.getEndDate() < b.getEndDate();
   }
};

struct CompareTaskEndTime {
   bool operator()(const Task& a, const Task& b) const {
      return a.getEndTime() < b.getEndTime();
   }
};

class TaskManager {
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar & _tasks; 
	}

	static int _nextTaskID;
	vector<Task> _tasks;
	static TaskManager* _instance;
	TaskManager();

public:
	static TaskManager* getInstance();
	~TaskManager();
	void append(Task task);
	void addTask(Task task);
	void deleteTask(vector<Task>& _tasks, int taskIDToDelete);
	vector<Task>* retrieveTimedTask(string timeIndicator);
	void getTimedTaskVector(vector<Task>& timedTaskVector);
	vector<Task>* retrieveFloatingTask(string timeIndicator);
	void getFloatingTaskVector(vector<Task>& floatingTaskVector);
	vector<Task>* retrieveDeadline(string timeIndicator);
	void getDeadlineVector(vector<Task>& deadlineVector);
	//void setCompletionStatus(int index, bool isComplete);
	void editTask(int editIndex, string taskName, string startDate, string startTime, string endDate, string endTime);
	void clearAllTasks();
	vector<Task> searchForString(string searchTerm);
	vector<Task> searchForTasksDueToday(string todaysDate);
	void sortTasksByName();
	void sortTasksByNearestDeadline();
	void save(const char* fileName);
	void load(const char* fileName);
};

#endif
