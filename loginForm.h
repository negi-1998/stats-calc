//---------------------------------------------------------------------------

#ifndef loginFormH
#define loginFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TmyLoginForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TEdit *usernameEdit;
	TLabel *Label3;
	TEdit *passwordEdit;
	TButton *loginButton;
	TLabel *messageLabel;
	void __fastcall loginButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TmyLoginForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmyLoginForm *myLoginForm;
//---------------------------------------------------------------------------
#endif
