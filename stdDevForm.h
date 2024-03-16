//---------------------------------------------------------------------------

#ifndef stdDevFormH
#define stdDevFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
//---------------------------------------------------------------------------
class TmystdDevForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TEdit *ungroupedEdit;
	TLabel *Label3;
	TEdit *ungroupedOpEdit;
	TButton *ungroupedOkButton;
	TButton *ungroupedCalcButton;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *startEdit;
	TEdit *endEdit;
	TLabel *Label7;
	TEdit *rangeEdit;
	TLabel *Label6;
	TEdit *groupedOpEdit;
	TLabel *Label8;
	TLabel *Label9;
	TEdit *freqEdit;
	TButton *groupedOkButton;
	TButton *groupedCalcButton;
	TLabel *errorLabel;
	TLabel *ungroupedErrorLabel;
	void __fastcall ungroupedOkButtonClick(TObject *Sender);
	void __fastcall ungroupedCalcButtonClick(TObject *Sender);
	void __fastcall groupedOkButtonClick(TObject *Sender);
	void __fastcall groupedCalcButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TmystdDevForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmystdDevForm *mystdDevForm;
//---------------------------------------------------------------------------
#endif
