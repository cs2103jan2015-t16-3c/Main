//@author A0116661J
#include "stdafx.h"
#include "CppUnitTest.h"
#include "CommandDelete.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConstanTest
{
	TEST_CLASS(CommandDeleteTest)
	{
	public:
		
		TEST_METHOD(InverseCommandDelete)
		{
			vector<Task>* _currentDisplay = new vector<Task>;
			string _currentDisplayIndicator;
			Command* cmd = new CommandDelete (1, _currentDisplay,_currentDisplayIndicator);
			Command* invCommand = cmd->getInverseCommand();
			CommandAdd* inv2 = dynamic_cast<CommandAdd*>(invCommand);
			Assert::IsNotNull(inv2);// assert that invCommand is of type CommandAdd
		}

	};
}