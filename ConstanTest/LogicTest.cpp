//@author A0116661J
#include "stdafx.h"
#include "CppUnitTest.h"
#include "Logic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConstanTest
{
	TEST_CLASS(LogicTest)
	{
	public:
		
		TEST_METHOD(GetFeedback)
		{
			Logic logic;
			vector<string>* feedback;
			logic.processCommand("add -t assignment submission -e 14042015 1200");
			feedback = logic.getFeedback();
			Assert::AreEqual(string("add"), feedback->at(0));
			Assert::AreEqual(string("successful"), feedback->at(1));
			Assert::AreEqual(string("assignment submission"), feedback->at(2));
			Assert::AreEqual(string("NULL"), feedback->at(3));
			Assert::AreEqual(string("NULL"), feedback->at(4));
			Assert::AreEqual(string("14042015"), feedback->at(5));
			Assert::AreEqual(string("1200"), feedback->at(6));
		}
		
		TEST_METHOD(UpdateDisplayIndicator)
		{
			Logic logic;
			string displayIndicator;
			logic.processCommand("add -t task1 -s 20 Mar 2015 1000 -e 20 Mar 2015 1100");
			displayIndicator = logic.getCurrentDisplayIndicator();
			Assert::AreEqual(string("20032015"), displayIndicator);
		}



	};
}