#include "myGUI.h"
#include <cstdlib>
#include <ctime>

using namespace System;
using namespace System::Windows::Forms;

using std::time;
using std::srand;

[STAThreadAttribute]
void MainGUI(array<String^>^ args) {
	srand(time(nullptr));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DES_GUI::myGUI form;
	Application::Run(% form);
}
