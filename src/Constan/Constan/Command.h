#pragma once
#ifndef COMMAND_H_
#define COMMAND_H_

class Command {
public:
	Command(void);
	~Command(void);
	void execute();
	Command getInverseCommand();
};

#endif

