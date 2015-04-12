#ifndef LOGGER_H_
#define LOGGER_H_

#include <fstream>
#include <string>

using namespace std;

static const string LOG_FILE_NAME = "log.txt";

class Logger {
private:
	static Logger* _instance;
public:
	Logger();
	~Logger();
	void log(string logMessage);
};

#endif