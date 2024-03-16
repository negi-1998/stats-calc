//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include <fstream>
#include <string>
#include "loginForm.h"
#include <vector>
#include <sstream>
#include "quizForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TmyLoginForm *myLoginForm;
//---------------------------------------------------------------------------
__fastcall TmyLoginForm::TmyLoginForm(TComponent* Owner)
	: TForm(Owner)
{
}

std::vector<std::string> parseCommaDelimitedString(std::string line){
	std::vector<std::string> result;
	std::stringstream s_stream(line);

	while(s_stream.good()){
		std::string substr;
		getline(s_stream, substr, ',');
		result.push_back(substr);
	}
    return result;
}

//---------------------------------------------------------------------------
void __fastcall TmyLoginForm::loginButtonClick(TObject *Sender)
{
	fstream myFile;
	myFile.open("registeredUsers.txt", ios::in);

	if(myFile.is_open()){
		std::string line;

		while(getline(myFile, line)){
			std::vector<std::string> parsedLine = parseCommaDelimitedString(line);
			const char* username = parsedLine.at(3).c_str();

			AnsiString editUsername = usernameEdit->Text;
			const char* usernameString = editUsername.c_str();

			if(std::strcmp(username, usernameString)==0){
				const char* password = parsedLine.at(4).c_str();

				AnsiString editPassword = passwordEdit->Text;
				const char* passwordString = editPassword.c_str();

				if(std::strcmp(password, passwordString)==0){
					myQuizForm->Show();
				}
				else{
                    messageLabel->Text="Incorrect Password";
				}
			}
		}
	}
}
//---------------------------------------------------------------------------

