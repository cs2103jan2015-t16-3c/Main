//@author A0116661J
#include "stdafx.h"
#include "CppUnitTest.h"
#include "CommandSearch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConstanTest
{
	TEST_CLASS(CommandSearchTest)
	{
	public:
		
		TEST_METHOD(InverseCommandSearch)
		{
			string _currentDisplayIndicator;
			Command* cmd = new CommandSearch ("meeting", _currentDisplayIndicator);
			Command* invCommand = cmd->getInverseCommand();
			CommandSearch* inv2 = dynamic_cast<CommandSearch*>(invCommand);
			Assert::IsNull(inv2);// assert that invCommand is Null for type of CommandSearch
		}

	};
}