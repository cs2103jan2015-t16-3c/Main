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
	TEST_CLASS(LoggerTest) {
	public:
		TEST_METHOD(LogTest) {
			TaskManager* testTM = TaskManager::getInstance();
			testTM->clearAllTasks();
			testTM->addTask("eat lunch", "08032015", "1200", "08032015", "1400");

			ifstream ifs(LOG_FILE_NAME);
			string testString1;
			getline(ifs, testString1);
			string testString2;
			getline(ifs, testString2);

			Assert::AreEqual(testString1, TASK_DELETED_ALL);
			Assert::AreEqual(testString2, TASK_ADDED);
		}
	};
}