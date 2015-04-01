#pragma once

#ifndef TASK_H_
#define TASK_H_

#include <string>
#include <functional>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

using namespace std;
using namespace boost;

const int DEFAULT_TASK_ID = 0;
const string DEFAULT_TASK_NAME = "NULL";
const string DEFAULT_START_DATE = "NULL";
const string DEFAULT_START_TIME = "NULL";
const string DEFAULT_END_DATE = "NULL";
const string DEFAULT_END_TIME = "NULL";
const string TASK_TYPE_ALL = "all";
const string TASK_TYPE_TIMED = "timed";
const string TASK_TYPE_DEADLINE = "deadline";
const string TASK_TYPE_FLOATING = "floating";

class Task {
private:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, unsigned int version) {
		ar & _taskID;
		ar & _startDate;
		ar & _taskName;
		ar & _startTime;
		ar & _endDate;
		ar & _endTime;
		ar & _type;
//		ar & _iscomplete;
	}

	int _taskID; //each task has a unique ID number
	string _taskName;
	string _startDate;
	string _startTime;
	string _endDate;
	string _endTime;
	string _type;
//  bool _isComplete;

public:
	Task();
	Task(string taskName, string startDate, string startTime, string endDate, string endTime, string type);
	~Task();
	void setTaskID(int id);
	int getTaskID() const;
	void setTaskName(string taskName);
    string getTaskName() const;
	void setStartDate(string startDate);
	string getStartDate() const;
	void setStartTime(string startTime);
	string getStartTime() const;
	void setEndDate(string endDate);
	string getEndDate() const;
	void setEndTime(string endTime);
	string getEndTime() const;
	void setType(string type);
	string getType() const;
//	void setCompletionStatus(bool isComplete);
//	bool getCompletionStatus();
};

#endif

