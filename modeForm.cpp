//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
 #include <unordered_map>
#include "modeForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TmymodeForm *mymodeForm;
//---------------------------------------------------------------------------
__fastcall TmymodeForm::TmymodeForm(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
bool isValid(String AnsiData) {
	if (AnsiData.IsEmpty()) {
		// Handle empty input as invalid
		return false;
	}

	int decimalCount = 0;

	for (int i = 1; i <= AnsiData.Length(); i++) {
		char c = AnsiData[i];

		if (c == '.') {
			// Check for more than one decimal point
			decimalCount++;
			if (decimalCount > 1) {
				return false;
			}
		} else if (!(c >= '0' && c <= '9')) {
			// Check if the character is not a digit (0-9) or a decimal point
			return false;
		}
	}

	// Check if the string ends with a decimal point
	if (AnsiData[AnsiData.Length()] == '.') {
		return false;
	}

	return true;
}

std::unordered_map<float, int> ungroupedData;
void __fastcall TmymodeForm::ungroupedOkButtonClick(TObject *Sender)
{
	String AnsiData = ungroupedDataEdit->Text;
	if(isValid(AnsiData)==false){
		ungroupedErrorLabel->Text = "Enter input in correct format";
		ungroupedDataEdit->Text = "";
		return;
	}
	float floatData = StrToFloat(AnsiData);
	if(ungroupedData.find(floatData)==ungroupedData.end()){
		ungroupedData.insert({floatData, 1});
	}
	else{
        ungroupedData[floatData]++;
	}
    ungroupedDataEdit->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TmymodeForm::ungroupedCalcButtonClick(TObject *Sender)
{
    if(ungroupedData.size()==0){
		ungroupedOpEdit->Text = "No input given";
		return;
	}

	int temp=0;
	float result;

	for(auto itr = ungroupedData.begin(); itr!=ungroupedData.end(); ++itr){
		if(itr->second > temp){
			result = itr->first;
			temp = itr->second;
		}
	}
	String formattedUngroupedOp = FormatFloat("0.000", result);
	ungroupedOpEdit->Text =   formattedUngroupedOp;
	ungroupedData.clear();
}
//---------------------------------------------------------------------------


bool dataInserted = false;
std::vector<float> frequency;
float startData, endData, rangeData, freqData;
void __fastcall TmymodeForm::groupedOkButtonClick(TObject *Sender)
{
    if(dataInserted==false){
		/*orderedDataMap["initialData"].push_back(startData);
		orderedDataMap["finalData"].push_back(endData);
		orderedDataMap["range"].push_back(rangeData);
		dataInserted=true;  */
		String startEditString = startEdit->Text;
			if(isValid(startEditString)==false){
			errorLabel->Text = "Some input is given in an incorect format. Please check andd try again";
			startEdit->Text="";
			return;
		}
		startData = StrToFloat(startEditString);

		String endEditString = endEdit->Text;
        	if(isValid(endEditString)==false){
			errorLabel->Text = "Some input is given in an incorect format. Please check andd try again";
			endEdit->Text="";
			return;
		}
		endData = StrToFloat(endEditString);

		String rangeEditString = rangeEdit->Text;
		if(isValid(rangeEditString)==false){
			errorLabel->Text = "Some input is given in an incorect format. Please check andd try again";
			rangeEdit->Text="";
			return;
		}
		rangeData = StrToFloat(rangeEditString);

		dataInserted = true;
	}

	String freqEditString = frequencyEdit->Text;
	if(isValid(freqEditString)==false){
		errorLabel->Text = "Some input is given in an incorect format. Please check andd try again";
		frequencyEdit->Text="";
		return;
	}
	freqData = StrToFloat(freqEditString);

	frequency.push_back(freqData);
	frequencyEdit->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TmymodeForm::groupedCalcButtonClick(TObject *Sender)
{
	float f1=frequency[0], f0=0, f2=frequency[1], lower_limit, temp = frequency[0], modeClass_start = startData;
	float class_start = startData, class_end = startData + rangeData;
	for(int i=1; i<frequency.size()-1; i++){
		class_start += rangeData;
		if(frequency[i]>temp){
			f1 = frequency[i];
			f2 = frequency[i+1];
			f0 = frequency[i-1];
			temp = frequency[i];
			modeClass_start = class_start;
			class_end+=rangeData;
		}
	}
	if(frequency[frequency.size()-1] > temp){
		f1 = frequency[frequency.size()-1];
		f0 = frequency[frequency.size()-2];
		f2 = 0;
		modeClass_start = endData - rangeData;
	}

	float mode = modeClass_start + ((f1-f0)/((2*f1)-f0-f2));
	String formattedGroupedOp = FormatFloat("0.000", mode);
	groupedOpEdit->Text =   formattedGroupedOp;
    frequency.clear();
}
//---------------------------------------------------------------------------

