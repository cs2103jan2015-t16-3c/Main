#pragma once
#ifndef COMMANDDELETE_H_
#define COMMANDDELETE_H_

#include "Command.h"

using namespace std;

class CommandDelete :
	public Command {
private:
	int _index;
public:
	CommandDelete(int index);
//	~CommandDelete(void);
	void execute();
//	Command getInverseCommand();
};

#endif