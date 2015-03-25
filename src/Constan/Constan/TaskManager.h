#include "Task.h"
#include "TextUI.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

static const string MATCH_FOUND = "The following entries match your query: ";

class TaskManager {
private:
	vector<Task> _tasks;

public:
	TaskManager();
	~TaskManager();
	void readFromFile(vector<Task>& _tasks, char *argv[]);
	void writeToFile(vector<Task>& _tasks, char *argv[]);
	void addTask(Task task);
	void deleteTask(int index);
	void setCompletionStatus(int index, bool isComplete);
	void editTask(int editIndex, string taskName, string startTime, string endTime);
	void clearAllTasks();
	void searchForString(string searchTerm);
	void sortTasksByAscendingAlphabet(vector<Task> _tasks);
	void sortTasksByNearestDeadline(vector<Task> _tasks);
};