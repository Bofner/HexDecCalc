#include "MyForm.h"
#include <string>
#include <msclr\marshal_cppstd.h>



using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    HexDecCalc::MyForm form;
    Application::Run(% form);
};

