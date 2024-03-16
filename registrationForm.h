//---------------------------------------------------------------------------

#ifndef registrationFormH
#define registrationFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TmyRegistrationForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *nameEdit;
	TLabel *Label2;
	TEdit *ageEdit;
	TLabel *Label4;
	TEdit *emailEdit;
	TLabel *Label5;
	TLabel *Label3;
	TEdit *usernameEdit;
	TLabel *Label6;
	TEdit *retypePasswordEdit;
	TButton *registrationButton;
	TLabel *Label7;
	TEdit *passwordEdit;
	TLabel *warningLabel;
	void __fastcall registrationButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TmyRegistrationForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmyRegistrationForm *myRegistrationForm;
//---------------------------------------------------------------------------
#endif
