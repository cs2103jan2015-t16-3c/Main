#include "TextUI.h"

const string TextUI::MESSAGE_WELCOME = "Hello. Welcome to CONSTAN!";
const string TextUI::MESSAGE_ADDED = "Task added: ";
const string TextUI::MESSAGE_DELETED = "Task deleted: ";
const string TextUI::MESSAGE_EDITED = "Task edited: ";

const string TextUI::ERROR_UNRECOGNISED_COMMAND_TYPE = "ERROR: Unrecognised command type.\nEnter \"help\" for list of valid command type in CONSTAN!";
const string TextUI::ERROR_INVALID_FORMAT = "ERROR: Invalid format.\nEnter \"help\" for list of valid formatting in CONSTAN!";
const string TextUI::ERROR_INVALID_DATE_TIME = "ERROR: Invalid date or time.";
const string TextUI::ERROR_OTHERS = "ERROR.";

const string TextUI::HELP_USER_GUIDE = "General Command: \n1. Undo : \"undo\" \n2. Redo : \"redo\" \n3. Search : \"search [keyword(s)]\" \n\nTask Manipulation Commands: \n1. Creating/Adding task : \"add [task name] -s [start time] -e [end time]\" \n2. Displaying task : \"display\" \n3. Deleting task : \"delete [task index]\" \n4. Editing task : \"edit [task number] [task name] -s [start time] -e [end time]\" \n5. Mark task as done : \"mark [task index]\" \n6. Unmark \'done\' task : \"unmark [task index]\" ";

void TextUI::main() {
	showToUser(MESSAGE_WELCOME);
	cout << "Enter command:";
	string userCommand;
	getline (cin, userCommand);
		
	while (userCommand != "exit") {
		toLogic.processCommand(userCommand);
		/*
		if(TRUE //valid formatting, command succesfully executed) 
			printCommand();
		else 
			showToUser(ERROR_INVALID_FORMAT);	
		*/
		printCommand(userCommand);

		cout << "Enter command:";
		getline (cin, userCommand);
		
	}
}


string TextUI::getFirstWord(string userCommand){
	userCommandTemp = userCommand;
	string commandTypeString = userCommandTemp.substr(0, userCommand.find(' '));
	return commandTypeString;
}


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

	if (commandTypeString == "mark" || "unmark" || "search" || "undo" || "redo" )
		return COMMAND_TYPE_FEEDBACK::OTHERS;

	else {
		return COMMAND_TYPE_FEEDBACK::INVALID;
	}
}

void TextUI::printCommand(string userCommand) {
	if(userCommand == "") {                                      
		showToUser(ERROR_UNRECOGNISED_COMMAND_TYPE);
	}

	string commandTypeString = getFirstWord(userCommand);
		
	COMMAND_TYPE_FEEDBACK commandType = determineCommandType(commandTypeString);

	switch (commandType) {
	case ADD_TASK: 
		showToUser(MESSAGE_ADDED);
		displayResult();
		return;
	case DELETE_TASK:
		showToUser(MESSAGE_DELETED);
		displayResult();
		return;
	case EDIT_TASK:
		showToUser(MESSAGE_EDITED);
		displayResult();
		return;
	case HELP:
		showToUser(HELP_USER_GUIDE);
		return;
	case DISPLAY:
		displayTaskList();
		return;
	case OTHERS:
		displayResult();
		return;
	case INVALID:             
		showToUser(ERROR_UNRECOGNISED_COMMAND_TYPE);
		return;
	default:
		return;
	}

}

void TextUI::displayResult() {

	output = toLogic.getMainDisplay();

	for (unsigned i=0; i<output.size(); i++)
	{
		cout << output[i] << endl;
	}
}

void TextUI::displayTaskList() {
	string DisplayType = userCommandTemp.substr(0, userCommandTemp.find(' '));
	displayTask.print(DisplayType);
}

void TextUI::showToUser(string text) {
	cout << text << endl;
}

TextUI::TextUI(void)
{
}


TextUI::~TextUI(void)
{
}

