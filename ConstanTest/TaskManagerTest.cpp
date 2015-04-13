//@author A0112528M
#include "stdafx.h"
#include "CppUnitTest.h"
#define protected public
#define private   public
#include "TaskManager.h"
#undef protected
#undef private

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConstanTest {
	TEST_CLASS(TaskManagerTest)	{
	public:
		TEST_METHOD(AddTaskTest1) {
			TaskManager* testTM = TaskManager::getInstance();
			testTM->clearAllTasks();
			testTM->addTask("eat lunch", "08032015", "1200", "08032015", "1400");
			
			Assert::AreEqual(testTM->_tasks[0].getStartTime(), string("1200"));
		}

		TEST_METHOD(EditTaskTest1) {
			TaskManager* testTM = TaskManager::getInstance();
			testTM->clearAllTasks();
			testTM->addTask("eat lunch", DEFAULT_START_DATE, DEFAULT_START_TIME, DEFAULT_END_DATE, DEFAULT_END_TIME);
			testTM->editTask(testTM->_tasks[0].getTaskID(), "eat lunch", "01012015", "1200", "01012015", "1300");

			Assert::AreEqual(testTM->_tasks[0].getType(), TASK_TYPE_TIMED);
			Assert::AreEqual(testTM->_tasks[0].getStartTime(), string("1200"));
		}

		TEST_METHOD(DeleteTaskTest1) {
			TaskManager* testTM = TaskManager::getInstance();
			testTM->clearAllTasks();
			testTM->addTask("eat lunch", "08032015", "1200", "08032015", "1400");
			testTM->addTask("eat dinner", "08032015", "1900", "08032015", "2100");
			testTM->deleteTask(testTM->_tasks[0].getTaskID());

			Assert::AreEqual(int(testTM->_tasks.size()), 1);
			Assert::AreEqual(testTM->_tasks[0].getTaskName(), string("eat dinner"));
		}

		TEST_METHOD(ClearTasksTest1) {
			TaskManager* testTM = TaskManager::getInstance();
			testTM->clearAllTasks();
			testTM->addTask("eat lunch", "08032015", "1200", "08032015", "1400");
			testTM->addTask("eat dinner", "08032015", "1900", "08032015", "2100");
			testTM->clearAllTasks();

			Assert::AreEqual(int(testTM->_tasks.size()), 0);
		}

		
		TEST_METHOD(SearchForStringTest1) {
			TaskManager* testTM = TaskManager::getInstance();
			vector<Task>* resultsPtrs;
			testTM->clearAllTasks();
			testTM->addTask("eat lunch", "08032015", "1200", "08032015", "1400");
			testTM->addTask("eat dinner", "08032015", "1900", "08032015", "2100");
			resultsPtrs = testTM->searchForString("dinner");
			
			Assert::AreEqual((*resultsPtrs)[0].getTaskName(), string("eat dinner"));
		}
		
		TEST_METHOD(RetrieveTodaysTasksTest1) {
			vector<Task> results;
			TaskManager* testTM = TaskManager::getInstance();
			testTM->clearAllTasks();
			testTM->addTask("eat lunch", "08032015", "1200", "08032015", "1400");
			testTM->addTask("eat dinner", "08032015", "1900", "08032015", "2100");
			testTM->addTask("eat breakfast", "09032015", "0800", "09032015", "0900");
			results = testTM->retrieveTodaysTasks("08032015");

			Assert::AreEqual(int(results.size()), 2);
			Assert::AreEqual(testTM->_tasks[0].getTaskName(), string("eat lunch"));
		}

		TEST_METHOD(SortByAlphabetTest1) {
			TaskManager* testTM = TaskManager::getInstance();
			testTM->clearAllTasks();
			testTM->addTask("eat lunch", "08032015", "1200", "08032015", "1400");
			testTM->addTask("eat dinner", "08032015", "1900", "08032015", "2100");
			testTM->addTask("eat breakfast", "09032015", "0800", "09032015", "0900");
			testTM->sortTasksByAscendingAlphabet();

			Assert::AreEqual(testTM->_tasks[0].getTaskName(), string("eat breakfast"));
			Assert::AreEqual(testTM->_tasks[1].getTaskName(), string("eat dinner"));
			Assert::AreEqual(testTM->_tasks[2].getTaskName(), string("eat lunch"));
		}

		TEST_METHOD(SortByDeadlineTest1) {
			TaskManager* testTM = TaskManager::getInstance();
			testTM->clearAllTasks();
			testTM->addTask("eat lunch", "08032015", "1200", "08032015", "1400");
			testTM->addTask("eat dinner", "08032015", "1900", "08032015", "2100");
			testTM->addTask("eat breakfast", "08032015", "0800", "08032015", "0900");
			testTM->sortTasksByNearestDeadline();

			Assert::AreEqual(testTM->_tasks[0].getTaskName(), string("eat breakfast"));
			Assert::AreEqual(testTM->_tasks[1].getTaskName(), string("eat lunch"));
			Assert::AreEqual(testTM->_tasks[2].getTaskName(), string("eat dinner"));
		}

		TEST_METHOD(RetrieveFileNameTest) {
			TaskManager* testTM = TaskManager::getInstance();
			testTM->setFileName("testfilename.txt"); //testfilename.txt written to filename.txt
			
			string fileName; 
			fileName = testTM->retrieveFileName();

			Assert::AreEqual(fileName, string("testfilename.txt"));
		}

		//save() is called indirectly through addTask()
		TEST_METHOD(SaveTest1) { 
			TaskManager* testTM = TaskManager::getInstance();
			testTM->clearAllTasks();
			testTM->addTask("eat lunch", "08032015", "1200", "08032015", "1400");
			testTM->addTask("eat dinner", "08032015", "1900", "08032015", "2100");

			ifstream ifs(testTM->_fileName);
			string testString1;
			getline(ifs, testString1);
			string taskID = testTM->_tasks[0].getTaskIDAsString();
			string testString2 = "eat lunch " + taskID +" timed 08032015 1200 08032015 1400 undone";			

			Assert::AreEqual(testString1, testString2);
		}

		TEST_METHOD(LoadTest1) {
			TaskManager* testTM = TaskManager::getInstance();
			testTM->clearAllTasks();
			testTM->addTask("eat lunch", "08032015", "1200", "08032015", "1400");
			testTM->addTask("eat dinner", "08032015", "1900", "08032015", "2100");

			testTM->load();
			string testFirstLine;
			testFirstLine = testTM->_tasks[0].getTaskName();
			string testSecondLine;
			testSecondLine = testTM->_tasks[1].getTaskName();

			Assert::AreEqual(testFirstLine, string("eat lunch"));
			Assert::AreEqual(testSecondLine, string("eat dinner"));
		}
	};
}