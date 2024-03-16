//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
 #include <queue>
#include "quizForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

class Question{
	public:
		char* Text;
		char* ans1;
		char* ans2;
		char* ans3;
		int correctAns;

		Question(){};

		Question(char* text, char* answer1, char* answer2, char* answer3, int correctAnswer){
			Text = text;
			ans1 = answer1;
			ans2 = answer2;
			ans3 = answer3;
			correctAns = correctAnswer;
		}
};
std::queue<Question> loadQuestion(){
	Question q1 = Question("What is the correct way to declare a pointer to an integer in C++?", " int* ptr;","pointer int*;", "int ptr*;", 1 );
	Question q2 = Question("In C++, which keyword is used to allocate memory for dynamic arrays?", "new","malloc", "allocate", 1 );
	Question q3 = Question("What is the scope of a local variable declared inside a function in C++?", "global scope","function scope", "file scope", 2 );
	Question q4 = Question("Which C++ data type is used to store characters and represents a single 8-bit character?", "character","byte", "char", 3 );
	Question q5 = Question("What does 'endl' do in a C++ program", "Ends program","clears screen", "Moves cursor to next line", 3 );

	std::queue<Question> questions;
	questions.push(q1);
	questions.push(q2);
	questions.push(q3);
	questions.push(q4);
	questions.push(q5);
	return questions;
}

std::queue<Question> questions;
Question currentQuestion;
int selectedAnswer;
int points=0;

TmyQuizForm *myQuizForm;
//---------------------------------------------------------------------------
__fastcall TmyQuizForm::TmyQuizForm(TComponent* Owner)
	: TForm(Owner)
{
	questions = loadQuestion();
	currentQuestion = questions.front();

	questionLabel->Text = currentQuestion.Text;
	answer1Button->Text = currentQuestion.ans1;
	answer2Button->Text = currentQuestion.ans2;
	answer3Button->Text = currentQuestion.ans3;

	questions.pop();
}
//---------------------------------------------------------------------------
void __fastcall TmyQuizForm::answer1ButtonChange(TObject *Sender)
{
	selectedAnswer=1;
}
//---------------------------------------------------------------------------
void __fastcall TmyQuizForm::answer2ButtonChange(TObject *Sender)
{
	selectedAnswer=2;
}
//---------------------------------------------------------------------------
void __fastcall TmyQuizForm::answer3ButtonChange(TObject *Sender)
{
    selectedAnswer=3;
}
//---------------------------------------------------------------------------
void __fastcall TmyQuizForm::confirmButtonClick(TObject *Sender)
{
	if(selectedAnswer == currentQuestion.correctAns){
		points++;
		pointsLabel->Text = points;
	}
	else{
		pointsLabel->Text = points;
	}

	if(!questions.empty()){
		currentQuestion = questions.front();

		questionLabel->Text = currentQuestion.Text;
		answer1Button->Text = currentQuestion.ans1;
		answer2Button->Text = currentQuestion.ans2;
		answer3Button->Text = currentQuestion.ans3;

		questions.pop();

		answer1Button->IsChecked = false;
		answer2Button->IsChecked = false;
		answer3Button->IsChecked = false;
	}

	else{
		confirmButton->Enabled = false;

	}
}
//---------------------------------------------------------------------------
