#include "myGUI.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void MainGUI(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//WinformCDemo is your project name
	DES_GUI::myGUI form;
	Application::Run(% form);
}
