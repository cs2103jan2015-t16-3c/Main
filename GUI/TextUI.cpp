#include "TextUI.h"

string TextUI::EMPTY_STRING = "";
string TextUI::SPACE = " ";
string TextUI::SEPARATOR = "]";

string TextUI::FEEDBACK_SUCCESSFUL = "successful";
string TextUI::FEEDBACK_UNSUCCESSFUL = "unsuccessful";

string TextUI::TASK_STATUS_DONE = "done";
string TextUI::TASK_STATUS_UNDONE = "undone";

string TextUI::MESSAGE_ADDED = "Task added: ";
string TextUI::MESSAGE_DELETED = "Task deleted: ";
string TextUI::MESSAGE_EDITED = "Task edited: ";
string TextUI::MESSAGE_DISPLAYED = "Task displayed: ";
string TextUI::MESSAGE_UNDONE = "Command undone.";
string TextUI::MESSAGE_MARKED = "Task marked: ";
string TextUI::MESSAGE_UNMARKED = "Task unmarked: ";
string TextUI::MESSAGE_SAVED = "Task saved: ";

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
string TextUI::ERROR_INVALID_COMMAND_MESSAGE = "Error: Invalid command.";
string TextUI::ERROR_UNRECOGNISED_COMMAND_TYPE = "ERROR: Unrecognised command type.\nEnter \"help\" for list of valid command type in CONSTAN!";
string TextUI::ERROR_INVALID_FORMAT = "ERROR: Invalid format.\nEnter \"help\" for list of valid formatting in CONSTAN!";
string TextUI::ERROR_INVALID_DATE_TIME = "ERROR: Invalid date or time.";
string TextUI::ERROR_OTHERS = "ERROR.";

//string TextUI::HELP_USER_GUIDE = "General Command: \n1. Undo : \"undo\" \n2. Redo : \"redo\" \n3. Search : \"search [keyword(s)]\" \n\nTask Manipulation Commands: \n1. Creating/Adding task : \"add [task name] -s [start time] -e [end time]\" \n2. Displaying task : \"display\" \n3. Deleting task : \"delete [task index]\" \n4. Editing task : \"edit [task number] [task name] -s [start time] -e [end time]\" \n5. Mark task as done : \"mark [task index]\" \n6. Unmark \'done\' task : \"unmark [task index]\" ";

string TextUI::STARTS_FROM = " starts from ";
string TextUI::UNTIL = " to ";
string TextUI::DUE = " due ";

string TextUI::DISPLAY_TYPE_ALL = "all";
string TextUI::DISPLAY_TYPE_TODAY = "today";
string TextUI::DISPLAY_TYPE_TOMORROW = "tomorrow";
string TextUI::DISPLAY_TYPE_SEARCH = "search";
string TextUI::DISPLAY_TYPE_ALL_TASK = "All task:";
string TextUI::DISPLAY_TYPE_TODAY_TASK = "Today's task:";
string TextUI::DISPLAY_TYPE_TOMORROW_TASK = "Tomorrow's task:";
string TextUI::DISPLAY_TYPE_SEARCH_TASK = "Search result(s):";
string TextUI::DISPLAY_TYPE_DATE = "Task on ";
string TextUI::COLON = ":";

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

	toLogic.processCommand(userCommand);

	setFeedback(userCommand);
	setDisplay();

}

/*GET FEEDBACK FROM LOGIC THEN DIFFERENTIATE FEEDBACK TYPE OR ERROR TYPE*/
void TextUI::setFeedback(string userCommand) {

	_feedback = toLogic.getFeedback();

	if ( _feedback->at(1) == FEEDBACK_SUCCESSFUL ) {

		displayFeedbackAccordingToType();

	} else if ( _feedback->at(1) == FEEDBACK_UNSUCCESSFUL ) {

		processErrorFeedback();

	}

}

void TextUI::displayFeedbackAccordingToType() {

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
		case SAVE_TASK:
			displayedFeedback(MESSAGE_SAVED);
			return;
		default:
			displayedFeedback();
			return;
	}

}


/*CHANGE COMMAND TYPE FROM STRING TO ENUM*/
TextUI::COMMAND_TYPE_FEEDBACK TextUI::determineCommandType(string commandTypeString) {

	if(commandTypeString == COMMAND_ADD)
		return COMMAND_TYPE_FEEDBACK::ADD_TASK;

	if (commandTypeString == COMMAND_DELETE)
		return COMMAND_TYPE_FEEDBACK::DELETE_TASK;

	if (commandTypeString == COMMAND_EDIT)
		return COMMAND_TYPE_FEEDBACK::EDIT_TASK;

	if (commandTypeString == COMMAND_DISPLAY)
		return COMMAND_TYPE_FEEDBACK::DISPLAY_TASK;

	if (commandTypeString == COMMAND_UNDO)
		return COMMAND_TYPE_FEEDBACK::UNDO_TASK;

	if (commandTypeString == COMMAND_MARK)
		return COMMAND_TYPE_FEEDBACK::MARK_TASK;
	
	if (commandTypeString == COMMAND_UNMARK)
		return COMMAND_TYPE_FEEDBACK::UNMARK_TASK;

	if (commandTypeString == COMMAND_SEARCH)
		return COMMAND_TYPE_FEEDBACK::SEARCH_TASK;

	if (commandTypeString == COMMAND_SAVE)
		return COMMAND_TYPE_FEEDBACK::SAVE_TASK;

	else {
		return COMMAND_TYPE_FEEDBACK::INVALID_TASK;
	}
}

/*COMBINE FEEDBACK MESSAGE AND THE FEEDBACK FROM LOGIC*/
void TextUI::displayedFeedback(string message) {

	_feedbackString = message + getFeedbackResult();
}

/*CREATE FEEDBACK FOR ERROR INPUTS*/
void TextUI::displayedFeedback() {

	_feedbackString = getFeedbackResult();
}

/*GET FEEDBACK RESULT FROM LOGIC*/
string TextUI::getFeedbackResult() {

	string feedbackResult;
	string commandType = _feedback->at(0);

	if ( commandType == COMMAND_DISPLAY || commandType == COMMAND_SEARCH || commandType == COMMAND_UNDO || commandType == COMMAND_SAVE ) {
		feedbackResult = _feedback->at(2);
	
	} else {

		string taskName = _feedback->at(2);
		feedbackResult = taskName;

		string startDate = _feedback->at(3);
		if (startDate != NULL_STRING) {
			startDate = formatDate(startDate);
		}

		string startTime = _feedback->at(4);
		if (startTime != NULL_STRING) {
			startTime = formatDate(startTime);
		}

		string endDate = _feedback->at(5);
		if (endDate != NULL_STRING) {
			endDate = formatDate(endDate);
		}

		string endTime = _feedback->at(6);
		if (endTime != NULL_STRING) {
			endTime = formatDate(endTime);
		}

		if (startDate != NULL_STRING)
			feedbackResult = taskName + STARTS_FROM + startDate + SPACE + startTime + UNTIL + endDate + SPACE + endTime;
		else if (endDate != NULL_STRING)
			feedbackResult = taskName + DUE + endDate + SPACE + endTime;
		else
			feedbackResult = taskName;
	}

	return feedbackResult;
}

void TextUI::processErrorFeedback() {

	_errorType = _feedback->at(2);

	if (_errorType == ERROR_TYPE_1) {
		_feedbackString = ERROR1_MESSAGE;

	} else if (_errorType == ERROR_TYPE_2) {
		_feedbackString = ERROR2_MESSAGE;

	} else if (_errorType == ERROR_TYPE_3) {
		_feedbackString = ERROR3_MESSAGE;

	} else if (_errorType == ERROR_TYPE_4) {
		_feedbackString = ERROR4_MESSAGE;

	} else if (_errorType == ERROR_TYPE_5) {
		_feedbackString = ERROR5_MESSAGE;

	} else if (_errorType == ERROR_TYPE_6) {
		_feedbackString = ERROR6_MESSAGE;

	} else if (_errorType == ERROR_TYPE_7) {
		_feedbackString = ERROR7_MESSAGE;

	} else if (_errorType == INVALID_COMMAND_ADD) {
		_feedbackString = ERROR_ADD_MESSAGE;

	} else if (_errorType == INVALID_COMMAND_DELETE) {
		_feedbackString = ERROR_DELETE_MESSAGE;

	} else if (_errorType == INVALID_COMMAND_EDIT) {
		_feedbackString = ERROR_EDIT_MESSAGE;

	} else if (_errorType == INVALID_COMMAND_DISPLAY) {
		_feedbackString = ERROR_DISPLAY_MESSAGE;

	} else if (_errorType == INVALID_COMMAND_SEARCH) {
		_feedbackString = ERROR_SEARCH_MESSAGE;

	} else if (_errorType == INVALID_COMMAND_MARK) {
		_feedbackString = ERROR_MARK_MESSAGE;

	} else if (_errorType == INVALID_COMMAND_UNMARK) {
		_feedbackString = ERROR_UNMARK_MESSAGE;

	} else if (_errorType == INVALID_COMMAND_DEFAULT) {
		_feedbackString = ERROR_INVALID_COMMAND_MESSAGE;

	} else {
		_feedbackString == ERROR_OTHERS;
	}

}

/*PASS TODAY'S DATE TO GUI*/
string TextUI::showTodayDate() {
	
	getTodayDateString();
	return _todayDate;
}

/*GET TODAY'S DATE FROM LOGIC*/
void TextUI::getTodayDateString() {

	_todayDate = toLogic.getTodayDate();
	_todayDate = formatDate(_todayDate);
}

/*PASS FEEDBACK TO GUI*/
string TextUI::showFeedback() {

	return _feedbackString;
}

/*GET AND PASS DISPLAY TYPE TO GUI*/
string TextUI::showCurrentDisplayIndicator() {

	getCurrentDisplayType();
	unparseCurrentDisplayType();

	return _displayType;
}

void TextUI::getCurrentDisplayType() {

	_displayType = toLogic.getCurrentDisplayIndicator();

}

void TextUI::unparseCurrentDisplayType() {

	if (_displayType == DISPLAY_TYPE_ALL) {
		_displayType = DISPLAY_TYPE_ALL_TASK;

	} else if (_displayType == DISPLAY_TYPE_TODAY) {
		_displayType = DISPLAY_TYPE_TODAY_TASK;

	} else if (_displayType == DISPLAY_TYPE_TOMORROW) {
		_displayType = DISPLAY_TYPE_TOMORROW_TASK;

	} else if (_displayType == DISPLAY_TYPE_SEARCH) {
		_displayType = DISPLAY_TYPE_SEARCH_TASK;

	} else {
		_displayType = formatDate(_displayType);

		if(_displayType == _todayDate) {
			_displayType = DISPLAY_TYPE_TODAY_TASK;
		} else {
		_displayType = DISPLAY_TYPE_DATE + _displayType + COLON;
		}
	}

}

/*SET THE CONTENT OF THE DISPLAY GOING TO BE PRINTED*/
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

	_display = EMPTY_STRING;

	for ( size_t i=0 ; i < _displayVector->size() ; i++ ) {

		string taskName = _displayVector->at(i).getTaskName();
		//taskName = convertToCorrectFormat(taskName);

		string startDate = _displayVector->at(i).getStartDate();
		if (startDate != NULL_STRING) {
			startDate = formatDate(startDate);
			if (startDate == _todayDate)
				startDate = DISPLAY_TYPE_TODAY;
		}

		string startTime = _displayVector->at(i).getStartTime();
		if (startTime != NULL_STRING)
			startTime = formatTime(startTime);

		string endDate = _displayVector->at(i).getEndDate();
		if (endDate != NULL_STRING) {
			endDate = formatDate(endDate);
			if (startDate == _todayDate)
				startDate = DISPLAY_TYPE_TODAY;
		}

		string endTime = _displayVector->at(i).getEndTime();
		if (endTime != NULL_STRING)
			endTime = formatTime(endTime);

		string status = _displayVector->at(i).getCompletionStatusAsString();
		_display = _display + taskName + SEPARATOR + startDate + SEPARATOR + startTime + SEPARATOR + endDate + SEPARATOR + endTime + SEPARATOR + status + SEPARATOR;
	}
}

void TextUI::getDeadlineVector() { 

	_deadlineVector =  toLogic.getDeadlineVector();

}

void TextUI::unparseDeadlineVector() {

	_displayDeadline = EMPTY_STRING;

	for ( size_t i=0 ; i < _deadlineVector->size() ; i++ ) {

		string taskName = _deadlineVector->at(i).getTaskName();

		string endDate = _deadlineVector->at(i).getEndDate();
		endDate = formatDate(endDate);
			if (endDate == _todayDate)
				endDate = DISPLAY_TYPE_TODAY;			

		string endTime = _deadlineVector->at(i).getEndTime();
			endTime = formatTime(endTime);

		string status = _deadlineVector->at(i).getCompletionStatusAsString();

		if (status == TASK_STATUS_UNDONE)
			_displayDeadline = _displayDeadline + taskName + SEPARATOR + endDate + SEPARATOR + endTime + SEPARATOR;
	}
}

/*CHANGE THE DATE FORMAT FROM DDMMYYYY TO DD MMM YYYY*/
string TextUI::formatDate(string date) {

	string day = date.substr(0,2);

	if ( day == FIRST || day == SECOND || day == THIRD || day == FOURTH || day == FIFTH || day == SIXTH || day == SEVENTH || day == EIGHTH || day == NINTH ) {
		day = day.substr(1,1);
	}

	string month = date.substr(2,2);
	string year = date.substr(4,4);

	if (month == FIRST) {
		date = day + SPACE + JANUARY + SPACE + year;
	}
	if (month == SECOND) {
		date = day + SPACE + FEBRUARY + SPACE + year;
	}
	if (month == THIRD) {
		date = day + SPACE + MARCH + SPACE + year;
	}
	if (month == FOURTH) {
		date = day + SPACE + APRIL + SPACE + year;
	}
	if (month == FIFTH) {
		date = day + SPACE + MAY + SPACE + year;
	}
	if (month == SIXTH) {
		date = day + SPACE + JUNE + SPACE + year;
	}
	if (month == SEVENTH) {
		date = day + SPACE + JULY + SPACE + year;
	}
	if (month == EIGHTH) {
		date = day + SPACE + AUGUST + SPACE + year;
	}
	if (month == NINTH) {
		date = day + SPACE + SEPTEMBER + SPACE + year;
	}
	if (month == TENTH) {
		date = day + SPACE + OCTOBER + SPACE + year;
	}
	if (month == ELEVENTH) {
		date = day + SPACE + NOVEMBER + SPACE + year;
	}
	if (month == TWELFTH) {
		date = day + SPACE + DECEMBER + SPACE + year;
	}

	return date;

}

/*CHANGE THE TIME FORMAT FROM HHMM TO HH:MM*/
string TextUI::formatTime(string time) {

	string hour = time.substr(0,2);
	string min = time.substr(2,2);

	time = hour + COLON + min;

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

/*RETURN ONE STRING OF DISPLAY TO GUI*/
string TextUI::showDisplay() {

	return _display;
}

/*RETURN ONE STRING OF DEADLINE TASK TO GUI*/
string TextUI::showDeadline() {

	return _displayDeadline;
}

/*RETURN NO OF TASK IN THE DISPLAY*/
int TextUI::getNoOfTask() {

	_noOfTask = _displayVector->size();
	return _noOfTask;
}

/*RETURN NO OF DEADLINE TASK DEADLINE DISPLAY*/
int TextUI::getNoOfDeadline() {

	_noOfDeadline = _deadlineVector->size();
	return _noOfDeadline;
}

TextUI::TextUI(void) {
}


TextUI::~TextUI(void) {
}

