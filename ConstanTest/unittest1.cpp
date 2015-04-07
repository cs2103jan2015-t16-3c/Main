#include "stdafx.h"
#include "CppUnitTest.h"
#include "Task.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConstanTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Task task ("meeting",  "07042015",  "1100",  "07042015",  "1200",  "timed");
//			Task task;
			Assert::AreEqual(string("meetinga"), task.getTaskName()); 
			// TODO: Your test code here
		}

	};
}