#include "stdafx.h"
#include "CppUnitTest.h"
#include "CommandAdd.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConstanTest
{
	TEST_CLASS(CommandAddTest)
	{
	public:
		
		TEST_METHOD(InveseCommandTest)
		{
			vector<Task>* _currentDisplay = new vector<Task>;
			Command* cmd = new CommandAdd ("dinner", "11042015", "1000", "11042015", "1100", 1, _currentDisplay);
			Command* invCommand = cmd->getInverseCommand();
			CommandDelete* inv2 = dynamic_cast<CommandDelete*>(invCommand);
			Assert::IsNotNull(inv2);// assert that invCommand is of type CommandDelete
			
		}

	};
}