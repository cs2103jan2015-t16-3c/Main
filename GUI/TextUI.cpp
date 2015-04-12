#include "TextUI.h"

string TextUI::EMPTY_STRING = "";
string TextUI::SPACE = " ";

//string TextUI::MESSAGE_WELCOME = "Hello. Welcome to CONSTAN!";
string TextUI::MESSAGE_ADDED = "Task added: ";
string TextUI::MESSAGE_DELETED = "Task deleted: ";
string TextUI::MESSAGE_EDITED = "Task edited: ";
string TextUI::MESSAGE_DISPLAYED = "Task displayed: ";
string TextUI::MESSAGE_UNDONE = "Command undone.";
string TextUI::MESSAGE_MARKED = "Task marked: ";
string TextUI::MESSAGE_UNMARKED = "Task unmarked: ";

string TextUI::ERROR_UNRECOGNISED_COMMAND_TYPE = "ERROR: Unrecognised command type.\nEnter \"help\" for list of valid command type in CONSTAN!";
string TextUI::ERROR_INVALID_FORMAT = "ERROR: Invalid format.\nEnter \"help\" for list of valid formatting in CONSTAN!";
string TextUI::ERROR_INVALID_DATE_TIME = "ERROR: Invalid date or time.";
string TextUI::ERROR_OTHERS = "ERROR.";

//string TextUI::HELP_USER_GUIDE = "General Command: \n1. Undo : \"undo\" \n2. Redo : \"redo\" \n3. Search : \"search [keyword(s)]\" \n\nTask Manipulation Commands: \n1. Creating/Adding task : \"add [task name] -s [start time] -e [end time]\" \n2. Displaying task : \"display\" \n3. Deleting task : \"delete [task index]\" \n4. Editing task : \"edit [task number] [task name] -s [start time] -e [end time]\" \n5. Mark task as done : \"mark [task index]\" \n6. Unmark \'done\' task : \"unmark [task index]\" ";

string TextUI::JANUARY = "Jan";
string TextUI::FEBRUARY = "Feb";
string TextUI::MARCH = "Mar";
string TextUI::APRIL = "Apr";
string TextUI::MAY = "May";
string TextUI::JUNE = "Jun";
string TextUI::JULY = "Jul";
string TextUI::AUGUST = "Aug";
string TextUI::SEPTEMBER = "Sep";
string TextUI::OCTOBER = "Oct";
string TextUI::NOVEMBER = "Nov";
string TextUI::DECEMBER = "Dec";

string TextUI::FIRST = "01";
string TextUI::SECOND = "02";
string TextUI::THIRD = "03";
string TextUI::FOURTH = "04";
string TextUI::FIFTH = "05";
string TextUI::SIXTH = "06";
string TextUI::SEVENTH = "07";
string TextUI::EIGHTH = "08";
string TextUI::NINTH = "09";
string TextUI::TENTH = "10";
string TextUI::ELEVENTH = "11";
string TextUI::TWELFTH = "12";


void TextUI::processUserInput(string userCommand) {

	//pass user input as a string to Logic
	toLogic.processCommand(userCommand);
		/*
		if(TRUE //valid formatting, command succesfully executed) 
			printCommand();
		else 
			showToUser(ERROR_INVALID_FORMAT);	
		*/
	setFeedback(userCommand);
	setDisplay();

}


TextUI::COMMAND_TYPE_FEEDBACK TextUI::determineCommandType(string commandTypeString) {

	if(commandTypeString == "add")
		return COMMAND_TYPE_FEEDBACK::ADD_TASK;

	if (commandTypeString == "delete")
		return COMMAND_TYPE_FEEDBACK::DELETE_TASK;

	if (commandTypeString == "edit")
		return COMMAND_TYPE_FEEDBACK::EDIT_TASK;

	if (commandTypeString == "display")
		return COMMAND_TYPE_FEEDBACK::DISPLAY_TASK;

	if (commandTypeString == "undo")
		return COMMAND_TYPE_FEEDBACK::UNDO_TASK;

	if (commandTypeString == "mark")
		return COMMAND_TYPE_FEEDBACK::MARK_TASK;
	
	if (commandTypeString == "unmark")
		return COMMAND_TYPE_FEEDBACK::UNMARK_TASK;


	if (commandTypeString == "search")
		return COMMAND_TYPE_FEEDBACK::SEARCH_TASK;

	else {
		return COMMAND_TYPE_FEEDBACK::INVALID_TASK;
	}
}

void TextUI::setFeedback(string userCommand) {
	/*if(userCommand == "") {                                      
		showToUser(ERROR_UNRECOGNISED_COMMAND_TYPE);
	}*/

	_feedback = toLogic.getFeedback();
	string commandTypeString = _feedback->front();
		
	COMMAND_TYPE_FEEDBACK commandType = determineCommandType(commandTypeString);

	switch (commandType) {
	case ADD_TASK: 
		displayedFeedback(MESSAGE_ADDED);
		return;
	case DELETE_TASK:
		displayedFeedback(MESSAGE_DELETED);
		return;
	case EDIT_TASK:
		displayedFeedback(MESSAGE_EDITED);
		return;
	case DISPLAY_TASK:
		displayedFeedback(MESSAGE_DISPLAYED);
		return;
	case UNDO_TASK:
		displayedFeedback(MESSAGE_UNDONE);
		return;
	case MARK_TASK:
		displayedFeedback(MESSAGE_MARKED);
		return;
	case UNMARK_TASK:
		displayedFeedback(MESSAGE_UNMARKED);
		return;
//	case OTHERS:
//		displayedFeedback();
//		return;
	case INVALID_TASK:             
		//showToUser(ERROR_UNRECOGNISED_COMMAND_TYPE);
		return;
	default:
		return;
	}

}

/*
string TextUI::getFirstWord(string userCommand){

	userCommandTemp = userCommand;
	string commandTypeString = userCommandTemp.substr(0, userCommand.find(' '));
	//string commandTypeString = toLogic.getCommandType();

	return commandTypeString;
}
*/


//combine feedback message with feedback result
void TextUI::displayedFeedback(string message) {

	feedback = message + getFeedbackResult();
}

//create feedback for commands who don't require messages
void TextUI::displayedFeedback() {

	feedback = getFeedbackResult();
}


string TextUI::showTodayDate() {
	
	getTodayDateString();
	return todayDate;
}

void TextUI::getTodayDateString() {

	todayDate = toLogic.getTodayDate();
	todayDate = formatDate(todayDate);
}

//get feedback result from Logic CLASS
string TextUI::getFeedbackResult() {
	if (_feedback->size() > 1) {
		return _feedback->at(1);
	}
	return EMPTY_STRING;
}

//pass the string of feedback to GUI
string TextUI::showFeedback() {

	return feedback;
}

//set the content of the display going to be printed 
void TextUI::setDisplay() {

	getDisplayVector();
	unparseDisplayVector();
	getDeadlineVector();
	unparseDeadlineVector();

}

void TextUI::getDisplayVector() { 

	_displayVector =  toLogic.getDisplayVector();

}

void TextUI::unparseDisplayVector() {

	display = EMPTY_STRING;

	for ( size_t i=0 ; i < _displayVector->size() ; i++ ) {

		string taskName = _displayVector->at(i).getTaskName();
		//taskName = convertToCorrectFormat(taskName);

		string startDate = _displayVector->at(i).getStartDate();
		if (startDate != "NULL")
			startDate = formatDate(startDate);

		string startTime = _displayVector->at(i).getStartTime();
		if (startTime != "NULL")
			startTime = formatTime(startTime);

		string endDate = _displayVector->at(i).getEndDate();
		if (endDate != "NULL")
			endDate = formatDate(endDate);

		string endTime = _displayVector->at(i).getEndTime();
		if (endTime != "NULL")
			endTime = formatTime(endTime);

		string status = _displayVector->at(i).getCompletionStatusAsString();
		display = display + taskName + "]" + startDate + "]" + startTime + "]" + endDate + "]" + endTime + "]" + status + "]";
	}
}

void TextUI::getDeadlineVector() { 

	_deadlineVector =  toLogic.getDeadlineVector();

}


void TextUI::unparseDeadlineVector() {

	displayDeadline = EMPTY_STRING;

	for ( size_t i=0 ; i < _deadlineVector->size() ; i++ ) {

		string taskName = _deadlineVector->at(i).getTaskName();

		string endDate = _deadlineVector->at(i).getEndDate();
			if (endDate == todayDate)
				endDate = "today";
			else
				endDate = formatDate(endDate);

		string endTime = _deadlineVector->at(i).getEndTime();
			endTime = formatTime(endTime);

		string status = _deadlineVector->at(i).getCompletionStatusAsString();

		if (status == "undone")
			displayDeadline = displayDeadline + taskName + "]" + endDate + "]" + endTime + "]";
	}
}


string TextUI::formatDate(string date) {

	string day = date.substr(0,2);
	if( day == FIRST || day == SECOND || day == THIRD || day == FOURTH || day == FIFTH || day == SIXTH || day == SEVENTH || day == EIGHTH || day == NINTH )
		day = day.substr(1,1);
	string month = date.substr(2,2);
	string year = date.substr(4,4);

	if (month == FIRST)
		date = day + SPACE + JANUARY + SPACE + year;
	if (month == SECOND)
		date = day + SPACE + FEBRUARY + SPACE + year;
	if (month == THIRD)
		date = day + SPACE + MARCH + SPACE + year;
	if (month == FOURTH)
		date = day + SPACE + APRIL + SPACE + year;
	if (month == FIFTH)
		date = day + SPACE + MAY + SPACE + year;
	if (month == SIXTH)
		date = day + SPACE + JUNE + SPACE + year;
	if (month == SEVENTH)
		date = day + SPACE + JULY + SPACE + year;
	if (month == EIGHTH)
		date = day + SPACE + AUGUST + SPACE + year;
	if (month == NINTH)
		date = day + SPACE + SEPTEMBER + SPACE + year;
	if (month == TENTH)
		date = day + SPACE + OCTOBER + SPACE + year;
	if (month == ELEVENTH)
		date = day + SPACE + NOVEMBER + SPACE + year;
	if (month == TWELFTH)
		date = day + SPACE + DECEMBER + SPACE + year;

	return date;

}

string TextUI::formatTime(string time) {

	string hour = time.substr(0,2);
	string min = time.substr(2,2);

	time = hour + ":" + min;

	return time;
}

/*
Capitalize first letter, lowercase the rest. might not be necessary
string Display::convertToCorrectFormat(string taskName) {

	if( !taskName.empty() ) {

    taskName[0] = toupper(taskName[0]);

    for( size_t i=1 ; i < taskName.length() ; i++ )
        taskName[i] = tolower(taskName[i]);
	}

	return taskName;

}
*/

//return ONE string of display for GUI class
string TextUI::showDisplay() {

	return display;
}

string TextUI::showDeadline() {

	return displayDeadline;
}

int TextUI::getNoOfTask() {
	noOfTask = _displayVector->size();
	return noOfTask;
}

int TextUI::getNoOfDeadline() {
	noOfDeadline = _deadlineVector->size();
	return noOfDeadline;
}

/*
void TextUI::showToUser(string text) {
	cout << text << endl;
}
*/


TextUI::TextUI(void) {
}


TextUI::~TextUI(void) {
}

