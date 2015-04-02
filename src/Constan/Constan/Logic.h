#pragma once
#ifndef LOGIC_H_
#define LOGIC_H_


#include <string>
#include <vector>
#include "Task.h"
#include "Command.h"
#include "Parser.h"

using namespace std;

class Logic {
private:
	vector<Task>* _currentDisplay;
	vector<string>* _feedback;
	Parser parser;

public:
	Logic();
	~Logic(void);
	void processCommand(string input);
	void getDisplay(vector<string>* currentDisplay);
	vector<string> getFeedback();

//	string getFeedback();
};

#endif

