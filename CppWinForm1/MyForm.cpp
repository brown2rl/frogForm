#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::SqlClient;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	CppWinForm1::MyForm form;
	
	

	Application::Run(%form);
}
