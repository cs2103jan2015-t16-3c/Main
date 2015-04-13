#include "stdafx.h"
#include "CppUnitTest.h"
#include "Logic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConstanTest
{
	TEST_CLASS(LogicTest)
	{
	public:
		
		TEST_METHOD(CommandAdd_GetFeedback)
		{
			Logic logic;
			vector<string>* feedback;
			logic.processCommand("add -t task1 -s 13042015 1000 -e 13042015 1100");
			feedback = logic.getFeedback();
			Assert::AreEqual(string("add"), feedback->at(0));
			Assert::AreEqual(string("successful"), feedback->at(1));
			Assert::AreEqual(string("task1"), feedback->at(2));
			Assert::AreEqual(string("13042015"), feedback->at(3));
			Assert::AreEqual(string("1000"), feedback->at(4));
			Assert::AreEqual(string("13042015"), feedback->at(5));
			Assert::AreEqual(string("1100"), feedback->at(6));
		}

		TEST_METHOD(CommandAdd_GetDisplayVector)
		{
			Logic logic;
			vector<Task>* displayVector;
			logic.processCommand("add -t task1 -s 13042015 1000 -e 13042015 1100");
			displayVector = logic.getDisplayVector();
			Task* expectedTask = new Task("task1", "13042015", "1000", "13042015", "1100", "timed");
			Assert::AreEqual(string("task1"), displayVector->at(0).getTaskName());
			Assert::AreEqual(string("13042015"), displayVector->at(0).getStartDate());
			Assert::AreEqual(string("1000"), displayVector->at(0).getStartTime());
			Assert::AreEqual(string("13042015"), displayVector->at(0).getEndDate());
			Assert::AreEqual(string("1100"), displayVector->at(0).getEndTime());
		}


	};
}