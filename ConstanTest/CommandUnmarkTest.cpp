#include "stdafx.h"
#include "CppUnitTest.h"
#include "CommandUnmark.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConstanTest
{
	TEST_CLASS(CommandUnmarkTest)
	{
	public:
		
		TEST_METHOD(InverseCommandUnmark)
		{
			vector<Task>* _currentDisplay = new vector<Task>;
			string _currentDisplayIndicator;
			Command* cmd = new CommandUnmark (1, _currentDisplay, _currentDisplayIndicator);
			Command* invCommand = cmd->getInverseCommand();
			CommandMark* inv2 = dynamic_cast<CommandMark*>(invCommand);
			Assert::IsNotNull(inv2);// assert that invCommand is of type CommandMark
		}

	};
}