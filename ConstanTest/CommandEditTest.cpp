//@author A0116661J
#include "stdafx.h"
#include "CppUnitTest.h"
#include "CommandEdit.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConstanTest
{
	TEST_CLASS(CommandEditTest)
	{
	public:
		
		TEST_METHOD(InverseCommandEdit)
		{
			vector<Task>* _currentDisplay = new vector<Task>;
			string _currentDisplayIndicator;
			Command* cmd = new CommandEdit (1, "dinner", "11042015", "1000", "11042015", "1100", _currentDisplay, _currentDisplayIndicator);
			Command* invCommand = cmd->getInverseCommand();
			CommandInverseEdit* inv2 = dynamic_cast<CommandInverseEdit*>(invCommand);
			Assert::IsNotNull(inv2);// assert that invCommand is of type CommandInverseEdit
		}

	};
}