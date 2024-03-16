//---------------------------------------------------------------------------

#include <fmx.h>
#include <vector>
#include <algorithm>
#include <string>
#pragma hdrstop

#include "medianForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TmymedianForm *mymedianForm;
//---------------------------------------------------------------------------
__fastcall TmymedianForm::TmymedianForm(TComponent* Owner)
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

std::vector<float> ungroupedData;
void __fastcall TmymedianForm::ungroupedOkButtonClick(TObject *Sender)
{
	String AnsiData = ungroupedDataEdit->Text;
	if(isValid(AnsiData)==false){
		ungroupedErrorLabel->Text = "Enter input in correct format";
		ungroupedDataEdit->Text = "";
		return;
	}
	float floatData = StrToFloat(AnsiData);
	ungroupedData.push_back(floatData);
	ungroupedDataEdit->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TmymedianForm::ungroupedCalButtonClick(TObject *Sender)
{
	if(ungroupedData.size()==0){
		ungroupedOpEdit->Text = "No input provided";
		return;
	}
	else{
		int size = ungroupedData.size();
		sort(ungroupedData.begin(), ungroupedData.end());
		if(size%2==1){
			ungroupedOpEdit->Text = ungroupedData[(size/2)];
			ungroupedData.clear();
			return;
		}
		else if(size%2==0){
			ungroupedOpEdit->Text = (ungroupedData[ungroupedData.size()/2] + ungroupedData[(size/2)+1])/2;
			ungroupedData.clear();
			return;
		}
	}
}
//---------------------------------------------------------------------------

bool dataInserted = false;
std::vector<float> frequency;
float startData, endData, rangeData, freqData, total_freq=0;
void __fastcall TmymedianForm::groupedOkButtonClick(TObject *Sender)
{
	if(dataInserted==false){
		/*orderedDataMap["initialData"].push_back(startData);
		orderedDataMap["finalData"].push_back(endData);
		orderedDataMap["range"].push_back(rangeData);
		dataInserted=true;  */
		String startEditString = dataStartEdit->Text;
        if(isValid(startEditString)==false){
			errorLabel->Text = "Some input is given in an incorect format. Please check andd try again";
			dataStartEdit->Text="";
			return;
		}
		startData = StrToFloat(startEditString);

		String endEditString = dataEndEdit->Text;
		if(isValid(endEditString)==false){
			errorLabel->Text = "Some input is given in an incorect format. Please check andd try again";
			dataEndEdit->Text="";
			return;
		}
		endData = StrToFloat(endEditString);

		String rangeEditString = classIntervalEdit->Text;
		if(isValid(rangeEditString)==false){
			errorLabel->Text = "Some input is given in an incorect format. Please check andd try again";
			classIntervalEdit->Text="";
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
	total_freq += freqData;
	frequencyEdit->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TmymedianForm::groupedCalcButtonClick(TObject *Sender)
{
	float medianFreq, classStart=startData , classEnd=startData+rangeData, cf=0, medianClassFreq;

	if(startData > endData){
		errorLabel->Text = "Starting data cannot be greater than or equal to end data. Enter data correctly.";
		return;
	}

	if (std::fmod(endData - startData, rangeData) != 0.0) {
		errorLabel->Text = "Interval is not corresponding with given start and end data.";
		return;
	}

	if((int)(endData-startData)/rangeData != frequency.size()){
		errorLabel->Text = "No. are frequencies provided are incorrect";
		return;
	}
	medianFreq = total_freq/2;
	if(medianFreq <= frequency[0]){
		cf = frequency[0];
		medianClassFreq = frequency[0];
	}
	else{
		for(int i=0; i<frequency.size(); i++){
			cf+=frequency[i];
			if(cf>medianFreq){
				cf -= frequency[i];
				medianClassFreq = frequency[i];
				break;
			}
			else{
				classStart+=rangeData;
				classEnd+=rangeData;
			}
		}
	}

	float groupedMedian = classStart + rangeData*((medianFreq-cf)/medianClassFreq);
	String formattedGroupedOp = FormatFloat("0.000", groupedMedian);
	groupedOpEdit->Text = formattedGroupedOp;
	return;
}
//---------------------------------------------------------------------------

