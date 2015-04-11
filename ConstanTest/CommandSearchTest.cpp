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
			Command* cmd = new CommandSearch ("meeting");
			Command* invCommand = cmd->getInverseCommand();
			CommandSearch* inv2 = dynamic_cast<CommandSearch*>(invCommand);
			Assert::IsNull(inv2);// assert that invCommand is Null for type of CommandSearch
		}

	};
}