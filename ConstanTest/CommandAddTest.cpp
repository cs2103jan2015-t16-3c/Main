#include "stdafx.h"
#include "CppUnitTest.h"
#include "CommandAdd.h"
#include "Logic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConstanTest
{
	TEST_CLASS(CommandAddTest)
	{
	public:
		
		TEST_METHOD(CommandAdd_GetInverseCommand)
		{
			vector<Task>* _currentDisplay = new vector<Task>;
			Command* cmd = new CommandAdd ("dinner", "11042015", "1000", "11042015", "1100", 1, _currentDisplay);
			Command* invCommand = cmd->getInverseCommand();
			CommandDelete* inv2 = dynamic_cast<CommandDelete*>(invCommand);
			Assert::IsNotNull(inv2);// assert that invCommand is of type CommandDelete
			
		}

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
			Assert::AreEqual(string("task1"), displayVector->at(0).getTaskName());
			Assert::AreEqual(string("13042015"), displayVector->at(0).getStartDate());
			Assert::AreEqual(string("1000"), displayVector->at(0).getStartTime());
			Assert::AreEqual(string("13042015"), displayVector->at(0).getEndDate());
			Assert::AreEqual(string("1100"), displayVector->at(0).getEndTime());
		}
		
		TEST_METHOD(CommandAdd_UpdateDisplayIndicator)
		{
			Logic logic;
			string displayIndicator;
			logic.processCommand("add -t task1 -s 13042015 1000 -e 13042015 1100");
			displayIndicator = logic.getCurrentDisplayIndicator();
			Assert::AreEqual(string("13042015"), displayIndicator);
		}

	};
}