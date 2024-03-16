//---------------------------------------------------------------------------

#ifndef medianFormH
#define medianFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
//---------------------------------------------------------------------------
class TmymedianForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TEdit *ungroupedDataEdit;
	TLabel *Label3;
	TEdit *ungroupedOpEdit;
	TButton *ungroupedOkButton;
	TButton *ungroupedCalButton;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *dataStartEdit;
	TEdit *dataEndEdit;
	TLabel *Label7;
	TLabel *Label8;
	TEdit *classIntervalEdit;
	TEdit *groupedOpEdit;
	TLabel *Label9;
	TEdit *frequencyEdit;
	TButton *groupedOkButton;
	TButton *groupedCalcButton;
	TLabel *errorLabel;
	void __fastcall ungroupedOkButtonClick(TObject *Sender);
	void __fastcall ungroupedCalButtonClick(TObject *Sender);
	void __fastcall groupedOkButtonClick(TObject *Sender);
	void __fastcall groupedCalcButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TmymedianForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmymedianForm *mymedianForm;
//---------------------------------------------------------------------------
#endif