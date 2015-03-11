#include "TextBuddy.h"


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
	myTextFile.push_back(input);
}

void TextBuddy::displayFile(){
	for (int i = 0; i < myTextFile.size(); i++) {
		cout << i + 1 << ". " << getText(i) << endl;
	}
}

string TextBuddy::getText(int line) {
	return myTextFile[line];
}

void TextBuddy::deleteInput(int a) {
	myTextFile.erase(myTextFile.begin() + (a - 1));
}

void TextBuddy::clearFile() {
	myTextFile.clear();
}

void TextBuddy::saveFile() {
	ofstream writeFile("mytextfile.txt", ios::out);

	for (int i = 0; i < myTextFile.size(); i++) {
		writeFile << myTextFile[i] << endl;
	}

	writeFile.close();
}

void TextBuddy::retrieveFile() {
	string temp;

	ifstream readFile("mytextfile.txt", ios::in);

	while (getline (readFile, temp)) {
		myTextFile.push_back(temp);
	}

	readFile.close();
}

void TextBuddy::sortFile() {
	sort(myTextFile.begin(), myTextFile.end());
}

int TextBuddy::searchFile(string input) {
	int lineNumber = -1;

	lineNumber = searchKeyWord(input);

	return lineNumber;
}

int TextBuddy::searchKeyWord(string input) {
	int answer = -1;

	for (int i = 0; i < myTextFile.size(); i++) {
		if ((myTextFile[i]).find(input) != -1) {
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

	TextBuddy textFile;

	textFile.showToUser(TextBuddy::MESSAGE_WELCOME);

	cout << argv[1] << endl;

	textFile.retrieveFile();

	while (true) {
		cout << endl << "Enter command: ";
		string command;
		cin >> command;

		TextBuddy::COMMAND_TYPE commandType = getCommandType(command);

		string input;

		switch (commandType) {
		case TextBuddy::COMMAND_TYPE::ADD:
			getline(cin, input);
			textFile.addToFile(input);
			textFile.showToUser(TextBuddy::MESSAGE_ADDED);
			break;
		case TextBuddy::COMMAND_TYPE::DISPLAY:
			textFile.displayFile();
			break;
		case TextBuddy::COMMAND_TYPE::DELETE:
			int a;
			cin >> a;
			textFile.deleteInput(a);
			textFile.showToUser(TextBuddy::MESSAGE_DELETED);
			break;
		case TextBuddy::COMMAND_TYPE::CLEAR:
			textFile.clearFile();
			textFile.showToUser(TextBuddy::MESSAGE_CLEARED);
			break;
		case TextBuddy::COMMAND_TYPE::INVALID:
			cout << "Invalid Command" << endl;
			break;
		case TextBuddy::COMMAND_TYPE::SORT:
			textFile.sortFile();
			textFile.showToUser(TextBuddy::MESSAGE_SORTED);
			break;
		case TextBuddy::COMMAND_TYPE::SEARCH:
			int lineNumber;
			getline(cin, input);
			lineNumber = textFile.searchFile(input);
			if (lineNumber == -1){
				textFile.showToUser(TextBuddy::MESSAGE_NOT_FOUND);
			}
			else {
				textFile.showToUser(TextBuddy::MESSAGE_FOUND);
				cout << "Line number " << lineNumber << endl;
			}
			break;
		case TextBuddy::COMMAND_TYPE::EXIT:
			exit(EXIT_SUCCESS);
		}

		textFile.saveFile();

	}

	return 0;
}