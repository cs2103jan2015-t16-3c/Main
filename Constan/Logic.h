#pragma once

#ifndef LOGIC_H_
#define LOGIC_H_

#include <string>
#include <vector>
#include <stack>
#include "Task.h"
#include "Command.h"
#include "Parser.h"

using namespace std;

class Logic {

private:
	Parser parser;	
	vector<Task>* _currentDisplay;
	vector<Task>* _deadlineVector;
	vector<string>* _feedback;
	stack<Command*> inverseCommandStack;

	string _todayDate;
	string _currentDisplayIndicator;

	void updateLogicAttributes(Command* cmd);

public:
	Logic();
	~Logic();
	void processCommand(string input);
	vector<string>* getFeedback();
	vector<Task>* getDisplayVector();
	vector<Task>* getDeadlineVector();
	string getTodayDate();
	string getCurrentDisplayIndicator();

	//vector<string>* getDisplay();
};

#endif

