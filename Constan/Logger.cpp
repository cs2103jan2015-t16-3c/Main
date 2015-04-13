//@author A0112528M
#include "Logger.h"

Logger::Logger(void) {
}

Logger::~Logger(void) {
}

void Logger::log(string logMessage) {
	ofstream ofs;
	ofs.open(LOG_FILE_NAME, ofstream::out | ofstream::app);
	ofs << logMessage << endl;
	ofs.close();
}