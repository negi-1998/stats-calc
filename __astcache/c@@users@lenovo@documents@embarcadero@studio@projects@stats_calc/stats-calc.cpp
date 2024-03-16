//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("mainForm.cpp", Form1);
USEFORM("meanForm.cpp", mymeanForm);
USEFORM("medianForm.cpp", mymedianForm);
USEFORM("modeForm.cpp", mymodeForm);
USEFORM("stdDevForm.cpp", mystdDevForm);
USEFORM("varianceForm.cpp", myvarianceForm);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TmymeanForm), &mymeanForm);
		Application->CreateForm(__classid(TmymedianForm), &mymedianForm);
		Application->CreateForm(__classid(TmymodeForm), &mymodeForm);
		Application->CreateForm(__classid(TmystdDevForm), &mystdDevForm);
		Application->CreateForm(__classid(TmyvarianceForm), &myvarianceForm);
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
