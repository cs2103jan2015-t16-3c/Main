#include "stdafx.h"
#include "CppUnitTest.h"
#include "CommandDisplay.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConstanTest
{
	TEST_CLASS(CommandDisplayTest)
	{
	public:
		
		TEST_METHOD(InverseCommandTest)
		{
			vector<Task>* _currentDisplay = new vector<Task>;
			Command* cmd = new CommandDisplay ("deadline" , _currentDisplay);
			Command* invCommand = cmd->getInverseCommand();
			CommandDisplay* invCommand2 = dynamic_cast<CommandDisplay*>(invCommand);
			Assert::IsNull(invCommand2);// assert that invCommand is Null for type of CommandDisplay
		}

	};
}