#pragma once

#include<iostream>
#include"clsDate.h"
#include"clsUtil.h"

using namespace std;

class clsInputValidate
{
public: 

	static bool IsDateBetween(clsDate Date, clsDate DateFrom,clsDate DateTo) {

		if (clsDate::IsDate1BeforeDate2(DateTo, DateFrom)) {
			clsDate::SwapDates(DateTo, DateFrom);
		}

		if (clsDate::IsDate1BeforeDate2(Date, DateFrom) || clsDate::IsDate1AfterDate2(Date, DateTo)) {
			return false;
		}
		else {
			return true;
		}

	}

	template<typename T>
	static  bool IsNumberBetween(T Number, T From, T To)
	{
		if (To < From) {
			clsUtil::Swap(From, To);
		}

		return !(Number<From || Number>To);
	}

	template<typename T>
	static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
		
	template<typename T>
	static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again:\n"){

		T Number = ReadIntNumber();
		
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;

	}

	static bool IsValideDate(clsDate Date) {
		return	clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}


};

