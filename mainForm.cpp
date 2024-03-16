//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "mainForm.h"
#include "meanForm.h"
#include "medianForm.h"
#include "modeForm.h"
#include "stdDevForm.h"
#include "varianceForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::meanButtonClick(TObject *Sender)
{
    mymeanForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::medianButtonClick(TObject *Sender)
{
    mymedianForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::modeButtonClick(TObject *Sender)
{
    mymodeForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::stdDevButtonClick(TObject *Sender)
{
    mystdDevForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::varianceButtonClick(TObject *Sender)
{
    myvarianceForm->Show();
}
//---------------------------------------------------------------------------
