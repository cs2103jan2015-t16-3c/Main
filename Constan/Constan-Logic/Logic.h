#pragma once
#ifndef LOGIC_H_
#define LOGIC_H_


#include <string>
#include <vector>
#include <stack>
#include "Task.h"
#include "Command.h"
#include "../Constan-Parser/ConstanParser.h"

using namespace std;

class Logic {
private:
	vector<Task>* _currentDisplay;
	vector<string>* _feedbackLogic;
	stack<Command> inverseCommandStack;
	ConstanParser parser;

public:
	Logic();
	~Logic(void);
	void processCommand(string input);
	vector<string>* getDisplay();
	vector<string>* getFeedback();

//	string getFeedback();
};

#endif
