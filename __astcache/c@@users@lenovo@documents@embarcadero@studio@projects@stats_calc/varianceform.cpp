﻿//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "varianceForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TmyvarianceForm *myvarianceForm;
//---------------------------------------------------------------------------
__fastcall TmyvarianceForm::TmyvarianceForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
std::vector<float> ungroupedData;
void __fastcall TmyvarianceForm::ungroupedOkButtonClick(TObject *Sender)
{
    String AnsiData = ungroupedEdit->Text;
	float floatData = StrToFloat(AnsiData);
	ungroupedData.push_back(floatData);
	ungroupedEdit->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TmyvarianceForm::ungroupedCalcButtonClick(TObject *Sender)
{
    int totalUngroupedData = ungroupedData.size();
	float sum=0, stdDevNumerator=0, result=0;

	for(int i=0; i<ungroupedData.size(); i++){
		sum += ungroupedData[i];
	}
	float mean = sum/totalUngroupedData;

	for(int i=0 ; i<ungroupedData.size(); i++){
		stdDevNumerator += pow(ungroupedData[i]-mean, 2);
	}

	result = (stdDevNumerator/ungroupedData.size());

	String formattedUngroupedOp = FormatFloat("0.000", result);
	ungroupedOpEdit->Text =   formattedUngroupedOp;
	ungroupedData.clear();
}
//---------------------------------------------------------------------------

bool dataInserted = false;
std::vector<float> frequency;
float startData, endData, rangeData, freqData;

void __fastcall TmyvarianceForm::groupedOkButtonClick(TObject *Sender)
{
    if(dataInserted==false){
		/*orderedDataMap["initialData"].push_back(startData);
		orderedDataMap["finalData"].push_back(endData);
		orderedDataMap["range"].push_back(rangeData);
		dataInserted=true;  */
		String startEditString = startEdit->Text;
		startData = StrToFloat(startEditString);

		String endEditString = endEdit->Text;
		endData = StrToFloat(endEditString);

		String rangeEditString = rangeEdit->Text;
		rangeData = StrToFloat(rangeEditString);

		dataInserted = true;
	}

	String freqEditString = freqEdit->Text;
	freqData = StrToFloat(freqEditString);

	frequency.push_back(freqData);
	freqEdit->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TmyvarianceForm::groupedCalcButtonClick(TObject *Sender)
{
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

	float classStart = startData, classEnd = startData + rangeData, classMid, total_freq=0;
	int i=0, sum=0;
	while(classEnd <= endData){
		classMid = (classStart + classEnd)/2.0;
		sum  += (classMid*frequency[i]);
		i++;
		classStart = classEnd;
		classEnd = classStart + rangeData;
		total_freq += frequency[i];
	}

	float groupedMean = sum/total_freq;
	classStart = startData;
	classEnd = startData+rangeData;
	float stdDevNumerator=0;
	while(classEnd <= endData){
		classMid = (classStart+classEnd)/2.0;
		stdDevNumerator += (classMid-groupedMean);
	}

	float result = stdDevNumerator/total_freq;
	String formattedGroupedOp = FormatFloat("0.000", result);
	groupedOpEdit->Text =   formattedGroupedOp;
	frequency.clear();
}
//---------------------------------------------------------------------------

