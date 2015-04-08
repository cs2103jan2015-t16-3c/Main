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
	vector<Task>* _currentDisplay;
	vector<string>* _feedbackLogic;
	stack<Command*> inverseCommandStack;
	Parser parser;

public:
	Logic();
	~Logic(void);
	void processCommand(string input);
	//vector<string>* getDisplay();
	vector<string>* getFeedback();

	vector<Task>* getDisplayVector();
//	string getFeedback();
};

#endif

