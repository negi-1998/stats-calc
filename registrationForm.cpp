//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include <fstream>
#include "registrationForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TmyRegistrationForm *myRegistrationForm;
//---------------------------------------------------------------------------
__fastcall TmyRegistrationForm::TmyRegistrationForm(TComponent* Owner)
	: TForm(Owner)
{

}

//---------------------------------------------------------------------------
void __fastcall TmyRegistrationForm::registrationButtonClick(TObject *Sender)
{
	fstream myFile;
	myFile.open("registeredUsers.txt", ios::app);
	if(myFile.is_open()){
		AnsiString name = nameEdit->Text;
		AnsiString age = ageEdit->Text;
		AnsiString email = emailEdit->Text;
		AnsiString username = usernameEdit->Text;
		AnsiString password = passwordEdit->Text;
		AnsiString repassword = retypePasswordEdit->Text;

		char* passwordString = password.c_str();
		char* repasswordString = repassword.c_str();

		if(strcmp(passwordString, repasswordString)==0){
			myFile<<name<<","<<age<<","<<email<<","<<username<<","<<password<<"end_of_record";
			myFile.close();
			this->Close();
		}

		else{
			warningLabel->Text = "Passwords do not match !! Type the passwords again.";
		}

	}
}
//---------------------------------------------------------------------------

