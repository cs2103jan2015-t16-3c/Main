#ifndef TASK_H_
#define TASK_H_

#include <string>

using namespace std;

const string DEFAULT_TASK_NAME = "NULL";
const string DEFAULT_START_DATE = "NULL";
const string DEFAULT_START_TIME = "NULL";
const string DEFAULT_END_DATE = "NULL";
const string DEFAULT_END_TIME = "NULL";

class Task {
private:
	string _taskName;
	string _startDate;
	string _startTime;
	string _endDate;
	string _endTime;
	string _type;
	int _taskID;
//	bool _isComplete;


public:
	Task();
	Task(string taskName, string startDate, string startTime, string endDate, string endTime, string type);
	~Task();
	void setTaskName(string taskName);
	string getTaskName();
	void setStartDate(string startDate);
	string getStartDate();
	void setStartTime(string startTime);
	string getStartTime();
	void setEndDate(string endDate);
	string getEndDate();
	void setEndTime(string endTime);
	string getEndTime();
	void setType(string type);
	string getType();
	void setTaskID (int taskID);
	int getTaskID();
//	void setCompletionStatus(bool isComplete);
//	bool getCompletionStatus();
};

#endif