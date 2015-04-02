#include "stdafx.h"
#include "CppUnitTest.h"
#include "Command.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
	TEST_CLASS(TestDisplay)
	{
	public:
		
		TEST_METHOD(TestCase)
		{
			
			string parse("add -t lunch with bob -s 01012015 1000 -e 01012015 1200");
			Assert::AreEqual("lunch with bob", _taskname);
			Assert::AreEqual("01012015",_startDate);
			Assert::AreEqual("1000", _startTime);
			Assert::AreEqual("01012015", _endDate);
			Assert::AreEqual("1200", _endTime);
			// testcase 
			// Assert::AreEqual(1,1);

		}

	};
}