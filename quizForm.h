//---------------------------------------------------------------------------

#ifndef quizFormH
#define quizFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TmyQuizForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *questionLabel;
	TRadioButton *answer1Button;
	TRadioButton *answer2Button;
	TRadioButton *answer3Button;
	TButton *confirmButton;
	TLabel *Label3;
	TLabel *pointsLabel;
	void __fastcall answer1ButtonChange(TObject *Sender);
	void __fastcall answer2ButtonChange(TObject *Sender);
	void __fastcall answer3ButtonChange(TObject *Sender);
	void __fastcall confirmButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TmyQuizForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmyQuizForm *myQuizForm;
//---------------------------------------------------------------------------
#endif
