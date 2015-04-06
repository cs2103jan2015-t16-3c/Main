#include "TextUI.h"

string TextUI::MESSAGE_WELCOME = "Hello. Welcome to CONSTAN!";
string TextUI::MESSAGE_ADDED = "Task added: ";
string TextUI::MESSAGE_DELETED = "Task deleted: ";
string TextUI::MESSAGE_EDITED = "Task edited: ";
string TextUI::MESSAGE_DISPLAYED = "Displaying: ";
string TextUI::MESSAGE_SEARCH_FOUND = "Task found: ";
string TextUI::MESSAGE_SEARCH_NOT_FOUND = "Task not found: ";

string TextUI::ERROR_UNRECOGNISED_COMMAND_TYPE = "ERROR: Unrecognised command type.\nEnter \"help\" for list of valid command type in CONSTAN!";
string TextUI::ERROR_INVALID_FORMAT = "ERROR: Invalid format.\nEnter \"help\" for list of valid formatting in CONSTAN!";
string TextUI::ERROR_INVALID_DATE_TIME = "ERROR: Invalid date or time.";
string TextUI::ERROR_OTHERS = "ERROR.";

string TextUI::HELP_USER_GUIDE = "General Command: \n1. Undo : \"undo\" \n2. Redo : \"redo\" \n3. Search : \"search [keyword(s)]\" \n\nTask Manipulation Commands: \n1. Creating/Adding task : \"add [task name] -s [start time] -e [end time]\" \n2. Displaying task : \"display\" \n3. Deleting task : \"delete [task index]\" \n4. Editing task : \"edit [task number] [task name] -s [start time] -e [end time]\" \n5. Mark task as done : \"mark [task index]\" \n6. Unmark \'done\' task : \"unmark [task index]\" ";

void TextUI::main() {
	showToUser(MESSAGE_WELCOME);
	cout << "Enter command:";
	getline (cin, userCommand);
		
	while (userCommand != "exit") {
		toLogic.processCommand(userCommand);
		/*
		if(TRUE //valid formatting, command succesfully executed) 
			printCommand();
		else 
			showToUser(ERROR_INVALID_FORMAT);	
		*/

		printFeedback();
		printDisplay();

		cout << "Enter command:";
		getline (cin, userCommand);
		
	}
}

/*
string TextUI::getFirstWord(string userCommand){
	userCommandTemp = userCommand;
	string commandTypeString = userCommandTemp.substr(0, userCommand.find(' '));
	return commandTypeString;
}
*/


TextUI::COMMAND_TYPE_FEEDBACK TextUI::determineCommandType(string commandTypeString) {

	if(commandTypeString == "add")
		return COMMAND_TYPE_FEEDBACK::ADD_TASK;

	if (commandTypeString == "delete")
		return COMMAND_TYPE_FEEDBACK::DELETE_TASK;

	if (commandTypeString == "edit")
		return COMMAND_TYPE_FEEDBACK::EDIT_TASK;

	if (commandTypeString == "help")
		return COMMAND_TYPE_FEEDBACK::HELP;

	if (commandTypeString == "display")
		return COMMAND_TYPE_FEEDBACK::DISPLAY;
	
	if (commandTypeString == "search")
		return COMMAND_TYPE_FEEDBACK::SEARCH_TASK;	 

	if (commandTypeString == "mark" || "unmark" || "undo" || "redo" )
		return COMMAND_TYPE_FEEDBACK::OTHERS;

	else {
		return COMMAND_TYPE_FEEDBACK::INVALID;
	}
}

void TextUI::printFeedback() {
	//if(userCommand == "") {                                      
	//	showToUser(ERROR_UNRECOGNISED_COMMAND_TYPE);
	//}

	_feedbackUI = toLogic.getFeedback();
	string commandTypeString = _feedbackUI->at(0);
		
	COMMAND_TYPE_FEEDBACK commandType = determineCommandType(commandTypeString);

	switch (commandType) {
	case ADD_TASK: 
		showToUser(MESSAGE_ADDED);
		showToUser(_feedbackUI->at(1));
		return;
	case DELETE_TASK:
		showToUser(MESSAGE_DELETED);
		showToUser(_feedbackUI->at(1));
		return;
	case EDIT_TASK:
		showToUser(MESSAGE_EDITED);
		showToUser(_feedbackUI->at(1));
		return;
/*	case HELP:
		showToUser(HELP_USER_GUIDE);
		return;
	case DISPLAY:
		showToUser(MESSAGE_DISPLAYED);
		showToUser(_feedback.at(1));
		return;
	case SEARCH_TASK:
		if (_feedback.at(2) == "true") {
			showToUser(MESSAGE_SEARCH_FOUND);
			cout << _feedback.at(1);
		} else {
			showToUser(MESSAGE_SEARCH_NOT_FOUND);
			cout << _feedback.at(1);
		}
	case OTHERS:
		return;
	case INVALID:             
		showToUser(ERROR_UNRECOGNISED_COMMAND_TYPE);
		return;*/
	default:
		return;
	}

}

void TextUI::printDisplay() {

	_output = toLogic.getDisplay();
	string displayComponent;

	for (unsigned i=0; i< _output->size(); i++)
	{
		displayComponent = _output->at(i);
		showToUser(displayComponent);
	}
}

/*
void TextUI::displayTaskList() {
	string DisplayType = userCommandTemp.substr(0, userCommandTemp.find(' '));
	displayTask.print(DisplayType);
}
*/

void TextUI::showToUser(string text) {
	cout << text << endl;
}

TextUI::TextUI() : toLogic() {
}


TextUI::~TextUI() {
}
