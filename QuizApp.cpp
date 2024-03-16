//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("quizForm.cpp", myQuizForm);
USEFORM("registrationForm.cpp", myRegistrationForm);
USEFORM("loginForm.cpp", myLoginForm);
USEFORM("mainForm.cpp", myMainForm);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TmyMainForm), &myMainForm);
		Application->CreateForm(__classid(TmyQuizForm), &myQuizForm);
		Application->CreateForm(__classid(TmyLoginForm), &myLoginForm);
		Application->CreateForm(__classid(TmyRegistrationForm), &myRegistrationForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
