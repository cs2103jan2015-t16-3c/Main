//@author A0116180R
#include "stdafx.h"
#include "CppUnitTest.h"
#include "Parser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConstanTest
{
	TEST_CLASS(ParserTest)
	{
	public:
		
		TEST_METHOD(TestreadDate1)
		{
			Parser p;
			Assert::AreEqual(string("10102015"), p.readDate("10102015"));
			// TODO: Your test code here
		}
		TEST_METHOD(TestreadDate2)
		{
			Parser p;
			time_t t = time(0); 
			char tmp[64]; 
			strftime( tmp, sizeof(tmp), "%d%m%Y",localtime(&t) );  
			Assert::AreEqual(string(tmp), p.readDate("today"));
		}
		TEST_METHOD(TestprocessDate1)
		{
			Parser p;
			Assert::AreEqual(string("01012015"), p.processDate("01 Jan 2015"));
		}
		TEST_METHOD(TestprocessDateIncorrect)
		{
			Parser p;
			Assert::AreEqual(string("01022015"), p.processDate("01 Jan 2015"));
		}
	};
}