#include "MyForm1.h"
#include "guicon.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args)
{
#ifdef _DEBUG
	//RedirectIOToConsole();
#endif
	printf("test");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CricketSimulator::MyForm form;
	Application::Run(%form);

}

