//---------------------------------------------------------------------------

#ifndef modeFormH
#define modeFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
//---------------------------------------------------------------------------
class TmymodeForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TEdit *ungroupedDataEdit;
	TLabel *Label3;
	TEdit *ungroupedOpEdit;
	TButton *ungroupedOkButton;
	TButton *ungroupedCalcButton;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *startEdit;
	TLabel *Label6;
	TEdit *endEdit;
	TLabel *Label7;
	TEdit *rangeEdit;
	TLabel *Label8;
	TEdit *groupedOpEdit;
	TLabel *Label9;
	TEdit *frequencyEdit;
	TButton *groupedCalcButton;
	TLabel *errorLabel;
	TButton *groupedOkButton;
	void __fastcall ungroupedOkButtonClick(TObject *Sender);
	void __fastcall ungroupedCalcButtonClick(TObject *Sender);
	void __fastcall groupedOkButtonClick(TObject *Sender);
	void __fastcall groupedCalcButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TmymodeForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmymodeForm *mymodeForm;
//---------------------------------------------------------------------------
#endif
