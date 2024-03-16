//---------------------------------------------------------------------------

#ifndef mainFormH
#define mainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TButton *meanButton;
	TButton *medianButton;
	TButton *modeButton;
	TButton *stdDevButton;
	TButton *varianceButton;
	TButton *Button6;
	void __fastcall meanButtonClick(TObject *Sender);
	void __fastcall medianButtonClick(TObject *Sender);
	void __fastcall modeButtonClick(TObject *Sender);
	void __fastcall stdDevButtonClick(TObject *Sender);
	void __fastcall varianceButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
