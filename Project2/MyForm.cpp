#include "MyForm.h"
using namespace Project2;
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
	return 0;
}
