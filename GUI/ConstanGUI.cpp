#include "ConstanGUI.h"

using namespace System; 
using namespace System::Windows::Forms;

[STAThread] 

int main(array<String^>^ argv) { 
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	GUIProject::ConstanGUI mainWindow; 
	Application::Run(%mainWindow); 

	return 0;

}

