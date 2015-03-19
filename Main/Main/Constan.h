#ifndef CONSTAN_H_
#define CONSTAN_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <iterator>
#include <vector>
#include <assert.h>
#include <sstream>

using namespace std;

struct entry {
	string task;
	string start;
	string end;
	string repeat;
};

class TextBuddy{
private:
	vector<entry> logBook;

public:
	// These are the possible command types
	enum COMMAND_TYPE {
		ADD, DISPLAY, DELETE, CLEAR, INVALID, SORT, SEARCH, EXIT
	};

	static const string MESSAGE_ADDED;
	static const string MESSAGE_DELETED;
	static const string MESSAGE_WELCOME;
	static const string MESSAGE_CLEARED;
	static const string MESSAGE_SORTED;
	static const string MESSAGE_FOUND;
	static const string MESSAGE_NOT_FOUND;

	static void showToUser(string text);

	static COMMAND_TYPE determineCommandType(string commandTypeString);

	void addToFile(string input);

	void displayFile();

	string getText(int line);

	string getInfo(int line);

	void deleteInput(int a);

	void clearFile();

	void saveFile();

	void retrieveFile();

//	void sortFile();

	int searchFile(string input);

	int searchKeyWord(string input);
};

#endif
