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

string TextUI::ERROR1_MESSAGE = "Error: Please enter task name e.g. add -t My task ..";
string TextUI::ERROR2_MESSAGE = "Error: Please specify when do you want to end this task";
string TextUI::ERROR3_MESSAGE = "Error: Please enter start date";
string TextUI::ERROR4_MESSAGE = "Error: Please specify the task's date";
string TextUI::ERROR5_MESSAGE = "Error: Your end date/time must be later than your start date/time";
string TextUI::ERROR6_MESSAGE = "Error: Invalid index. Please enter the index of the task displayed";
string TextUI::ERROR7_MESSAGE = "Error: Invalid display type.";
string TextUI::ERROR_ADD_MESSAGE = "Error: Please give the details of the task you want to add. ";
string TextUI::ERROR_DELETE_MESSAGE = "Error: Please enter the index of the task you want to delete e.g. delete 1";
string TextUI::ERROR_EDIT_MESSAGE = "Error: Please give the details of the task you want to edit.";
string TextUI::ERROR_DISPLAY_MESSAGE = "Error: Please specify the task you wish to display.";
string TextUI::ERROR_SEARCH_MESSAGE = "Error: Please specify the keywords of the task you want to search";
string TextUI::ERROR_MARK_MESSAGE = "Error: Specify the index of task you wish to mark or tick the checkbox";
string TextUI::ERROR_UNMARK_MESSAGE = "Error: Specify the index of task you wish to unmark or untick the checkbox";

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

/*RECEIVE USER INPUT FROM GUI AND PASS IT TO LOGIC*/
//set the feedback and display
void TextUI::processUserInput(string userCommand) {
//	string cmd = userCommand;
	toLogic.processCommand(userCommand);

	setFeedback(userCommand);
	setDisplay();

}

/*GET FEEDBACK FROM LOGIC THEN DIFFERENTIATE FEEDBACK TYPE OR ERROR TYPE*/
void TextUI::setFeedback(string userCommand) {

	_feedback = toLogic.getFeedback();

	if ( _feedback->at(1) == "successful" ) {

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
		default:
			displayedFeedback();
			return;
		}

	} else if ( _feedback->at(1) == "unsuccessful" ) {

		_errorType = _feedback->at(2);
		processErrorFeedback();

	}

}

/*CHANGE COMMAND TYPE FROM STRING TO ENUM*/
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

/*COMBINE FEEDBACK MESSAGE AND THE FEEDBACK FROM LOGIC*/
void TextUI::displayedFeedback(string message) {

	feedback = message + getFeedbackResult();
}

/*CREATE FEEDBACK FOR ERROR INPUTS*/
void TextUI::displayedFeedback() {

	feedback = getFeedbackResult();
}

/*GET FEEDBACK RESULT FROM LOGIC*/
string TextUI::getFeedbackResult() {

	string feedbackResult;
	string commandType = _feedback->at(0);

	if (commandType == "display" || commandType == "search" || commandType == "undo" ) {
		feedbackResult = _feedback->at(2);
	
	} else {

		string taskName = _feedback->at(2);
		feedbackResult = taskName;

		string startDate = _feedback->at(3);
		if (startDate != "NULL") {
			startDate = formatDate(startDate);
		}

		string startTime = _feedback->at(4);
		if (startTime != "NULL") {
			startTime = formatDate(startTime);
		}

		string endDate = _feedback->at(5);
		if (endDate != "NULL") {
			endDate = formatDate(endDate);
		}

		string endTime = _feedback->at(6);
		if (endTime != "NULL") {
			endTime = formatDate(endTime);
		}

		if (startDate != "NULL")
			feedbackResult = taskName + " starts from" + startDate + " " + startTime + " to " + endDate + " " + endTime;
		else if (endDate != "NULL")
			feedbackResult = taskName + " due " + endDate + " " + endTime;
		else
			feedbackResult = taskName;
	}

	return feedbackResult;
}

void TextUI::processErrorFeedback() {

	if (_errorType == ERROR_TYPE_1)
		feedback = ERROR1_MESSAGE;
	else if (_errorType == ERROR_TYPE_2)
		feedback = ERROR1_MESSAGE;
	else if (_errorType == ERROR_TYPE_3)
		feedback = ERROR1_MESSAGE;
	else if (_errorType == ERROR_TYPE_4)
		feedback = ERROR1_MESSAGE;
	else if (_errorType == ERROR_TYPE_5)
		feedback = ERROR1_MESSAGE;
	else if (_errorType == ERROR_TYPE_6)
		feedback = ERROR1_MESSAGE;
	else if (_errorType == ERROR_TYPE_7)
		feedback = ERROR1_MESSAGE;
	else if (_errorType == INVALID_COMMAND_ADD)
		feedback = ERROR_ADD_MESSAGE;
	else if (_errorType == INVALID_COMMAND_DELETE)
		feedback = ERROR_DELETE_MESSAGE;
	else if (_errorType == INVALID_COMMAND_EDIT)
		feedback = ERROR_EDIT_MESSAGE;
	else if (_errorType == INVALID_COMMAND_DISPLAY)
		feedback = ERROR_DISPLAY_MESSAGE;
	else if (_errorType == INVALID_COMMAND_SEARCH)
		feedback = ERROR_SEARCH_MESSAGE;
	else if (_errorType == INVALID_COMMAND_MARK)
		feedback = ERROR_MARK_MESSAGE;
	else if (_errorType == INVALID_COMMAND_UNMARK)
		feedback = ERROR_UNMARK_MESSAGE;
	else 
		feedback == ERROR_OTHERS;

}

string TextUI::showTodayDate() {
	
	getTodayDateString();
	return todayDate;
}

void TextUI::getTodayDateString() {

	todayDate = toLogic.getTodayDate();
	todayDate = formatDate(todayDate);
}



//pass the string of feedback to GUI
string TextUI::showFeedback() {

	return feedback;
}

string TextUI::showCurrentDisplayIndicator() {

	getCurrentDisplayType();
	unparseCurrentDisplayType();

	return _displayType;
}

void TextUI::getCurrentDisplayType() {

	_displayType = toLogic.getCurrentDisplayIndicator();

}

void TextUI::unparseCurrentDisplayType() {

	if (_displayType == "all")
		_displayType = "All task:";

	else if (_displayType == "today") 
		_displayType = "Today's task:";

	else if (_displayType == "tomorrow")
		_displayType = "Tomorrow's task:";

	else if (_displayType == "search")
		_displayType = "Search result(s):";

	else {
		_displayType = formatDate(_displayType);
		if(_displayType == todayDate)
			_displayType = "Today's task:";
		else
		_displayType = "Task on " + _displayType + ":";
	}

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
		if (startDate != "NULL") {
			startDate = formatDate(startDate);
			if (startDate == todayDate)
				startDate = "today";
		}

		string startTime = _displayVector->at(i).getStartTime();
		if (startTime != "NULL")
			startTime = formatTime(startTime);

		string endDate = _displayVector->at(i).getEndDate();
		if (endDate != "NULL") {
			endDate = formatDate(endDate);
			if (startDate == todayDate)
				startDate = "today";
		}

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
		endDate = formatDate(endDate);
			if (endDate == todayDate)
				endDate = "today";			

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

