#include "Constan.h"


const string TextBuddy::MESSAGE_ADDED = "Added to file";
const string TextBuddy::MESSAGE_WELCOME = "Welcome to TextBuddy!";
const string TextBuddy::MESSAGE_DELETED = "Deleted from file";
const string TextBuddy::MESSAGE_CLEARED = "All content deleted from file";
const string TextBuddy::MESSAGE_SORTED = "File has been sorted";
const string TextBuddy::MESSAGE_FOUND = "Keyword is found!";
const string TextBuddy::MESSAGE_NOT_FOUND = "Keyword is not found!";

void TextBuddy::showToUser(string text) {
	cout << text << endl;
}

TextBuddy::COMMAND_TYPE getCommandType(string command){
	if (command.substr(0, 3) == "add"){
		return TextBuddy::ADD;
	}
	else if (command.substr(0, 7) == "display") {
		return TextBuddy::DISPLAY;
	}
	else if (command.substr(0, 6) == "delete") {
		return TextBuddy::DELETE;
	}
	else if (command.substr(0, 5) == "clear") {
		return TextBuddy::CLEAR;
	}
	else if (command.substr(0, 4) == "exit") {
		return TextBuddy::EXIT;
	}
	else if (command.substr(0, 4) == "sort") {
		return TextBuddy::SORT;
	}
	else if (command.substr(0, 6) == "search") {
		return TextBuddy::SEARCH;
	}
	else {
		return TextBuddy::INVALID;
	}
}

void TextBuddy::addToFile(string input) {
	entry temp = {"","",""};
	string signal;
	istringstream in(input);
	in >> temp.task;
//	in >> signal;
	while (in >> signal) {
		if ( signal == "-s" ) {
			in >> temp.start;
		} else if ( signal == "-e" ) {
			in >> temp.end;
		} else if ( signal == "-r" ) {
			in >> temp.repeat;
		}
	}
	logBook.push_back(temp);
}

void TextBuddy::displayFile(){
	for (int i = 0; i < logBook.size(); i++) {
		cout << i + 1 << ". " << getText(i) << endl;
	}
}

string TextBuddy::getText(int line) {
	string task = logBook[line].task;
	string start = logBook[line].start;
	string end = logBook[line].end;
	string repeat = logBook[line].repeat;
	string output = task;
	if (start != "") {
		output = output + " start time: " + start;
	}
	if (end != "") {
		output = output + " end time: " + end;
	}
	if (repeat != "") {
		output = output + " repeat: " + repeat;
	}
	return output;
}

void TextBuddy::deleteInput(int a) {
	logBook.erase(logBook.begin() + (a - 1));
}

void TextBuddy::clearFile() {
	logBook.clear();
}

void TextBuddy::saveFile() {
	ofstream writeFile("mytextfile.txt", ios::out);

	for (int i = 0; i < logBook.size(); i++) {
		writeFile << getInfo(i) << endl;
	}

	writeFile.close();
}

string TextBuddy::getInfo(int line) {
	string task = logBook[line].task;
	string start = logBook[line].start;
	string end = logBook[line].end;
	string repeat = logBook[line].repeat;
	string output = task;
	if (start != "") {
		output = output + " -s " + start;
	}
	if (end != "") {
		output = output + " -s " + end;
	}
	if (repeat != "") {
		output = output + " -r " + repeat;
	}
	return output;
}

void TextBuddy::retrieveFile() {
	string temp;

	ifstream readFile("mytextfile.txt", ios::in);

	while (getline (readFile, temp)) {
		addToFile(temp);
	}

	readFile.close();
}

//void TextBuddy::sortFile() {
//	sort(logBook.begin(), logBook.end());
//}

int TextBuddy::searchFile(string input) {
	int lineNumber = -1;

	lineNumber = searchKeyWord(input);

	return lineNumber;
}

int TextBuddy::searchKeyWord(string input) {
	int answer = -1;

	for (int i = 0; i < logBook.size(); i++) {
		if ((logBook[i].task).find(input) != -1) {
			answer = i + 1;
		}
	}
	
	return answer;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Invalid input" << endl;
		return 0;
	}

	TextBuddy myList;

	myList.showToUser(TextBuddy::MESSAGE_WELCOME);

	cout << argv[1] << endl;

	myList.retrieveFile();

	while (true) {
		cout << endl << "Enter command: ";
		string command;
		cin >> command;

		TextBuddy::COMMAND_TYPE commandType = getCommandType(command);

		string input;

		switch (commandType) {
		case TextBuddy::COMMAND_TYPE::ADD:
			getline(cin, input);
			myList.addToFile(input);
			myList.showToUser(TextBuddy::MESSAGE_ADDED);
			break;
		case TextBuddy::COMMAND_TYPE::DISPLAY:
			myList.displayFile();
			break;
		case TextBuddy::COMMAND_TYPE::DELETE:
			int a;
			cin >> a;
			myList.deleteInput(a);
			myList.showToUser(TextBuddy::MESSAGE_DELETED);
			break;
		case TextBuddy::COMMAND_TYPE::CLEAR:
			myList.clearFile();
			myList.showToUser(TextBuddy::MESSAGE_CLEARED);
			break;
		case TextBuddy::COMMAND_TYPE::INVALID:
			cout << "Invalid Command" << endl;
			break;
//		case TextBuddy::COMMAND_TYPE::SORT:
//			myList.sortFile();
//			myList.showToUser(TextBuddy::MESSAGE_SORTED);
//			break;
		case TextBuddy::COMMAND_TYPE::SEARCH:
			int lineNumber;
			getline(cin, input);
			lineNumber = myList.searchFile(input);
			if (lineNumber == -1){
				myList.showToUser(TextBuddy::MESSAGE_NOT_FOUND);
			}
			else {
				myList.showToUser(TextBuddy::MESSAGE_FOUND);
				cout << "Line number " << lineNumber << endl;
			}
			break;
		case TextBuddy::COMMAND_TYPE::EXIT:
			exit(EXIT_SUCCESS);
		}

		myList.saveFile();

	}

	return 0;
}