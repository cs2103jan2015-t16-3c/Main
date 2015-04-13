//@author A0112528M
#ifndef TASK_H_
#define TASK_H_

#include <string>
#include <sstream>

using namespace std;

static const string EMPTY_STRING = "";
static const string DEFAULT_TASK_NAME = "NULL";
static const string DEFAULT_START_DATE = "NULL";
static const string DEFAULT_START_TIME = "NULL";
static const string DEFAULT_END_DATE = "NULL";
static const string DEFAULT_END_TIME = "NULL";
static const string COMPLETION_TRUE = "done";
static const string COMPLETION_FALSE = "undone";
static const string TASK_TYPE_FLOATING = "floating";
static const string TASK_TYPE_DEADLINE = "deadline";
static const string TASK_TYPE_TIMED = "timed";
static const string TASK_TYPE_ALL = "all";

class Task {
private:
	int _taskID;
	string _taskName;
	string _type;	
	string _startDate;
	string _startTime;
	string _endDate;
	string _endTime;
	bool _isComplete;


public:
	Task();
	Task(string taskName, string startDate, string startTime, string endDate, string endTime, string type);
	Task(string taskName, int taskID, string type, string startDate, string startTime, string endDate, string endTime, bool isComplete);  
	~Task();
	void setTaskID (int taskID);
	int getTaskID();
	void setTaskName(string taskName);
	string getTaskName();
	void setType(string type);
	string getType();
	void setStartDate(string startDate);
	string getStartDate();
	void setStartTime(string startTime);
	string getStartTime();
	void setEndDate(string endDate);
	string getEndDate();
	void setEndTime(string endTime);
	string getEndTime();
	void setCompletionStatus(bool isComplete);
	void setCompletionStatusViaString(string isComplete);
	bool getCompletionStatus();
	string getTaskIDAsString();
	string getCompletionStatusAsString();
};

#endif