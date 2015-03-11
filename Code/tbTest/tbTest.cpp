#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tbTest
{		
	TEST_CLASS(CommandTest)
	{
	public:
		
		TEST_METHOD(SortTest) {
			TextBuddy textBuddy;

			textBuddy.addToFile("engineering");
			textBuddy.addToFile("software");
			textBuddy.addToFile("cs2103");

			textBuddy.sortFile();

			Assert::AreEqual(string("cs2103"), textBuddy.getText(0));
			Assert::AreEqual(string ("engineering"), textBuddy.getText(1));
			Assert::AreEqual(string ("software"), textBuddy.getText(2));

		}

		TEST_METHOD(SearchTest){
			TextBuddy textBuddy;

			textBuddy.addToFile("engineering");
			textBuddy.addToFile("software");
			textBuddy.addToFile("cs2103");

			Assert::AreEqual(2, textBuddy.searchFile("software"));
			Assert::AreEqual(1, textBuddy.searchFile("engineering"));

		}

	};
}