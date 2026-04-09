

#include <iostream>
#include<vector>
#include<string>


using namespace std;

struct sDate {
    short Year;
    short Month;
    short Day;
};
struct stPeriod {
    sDate StartDate;
    sDate EndDate;
};

short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}
short ReadMonth() {
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}
short ReadYear() {
    short Year;
    cout << "\nPlease enter a Year? ";
    cin >> Year;
    return Year;
}
sDate ReadFullDate() {
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

vector<string> SplitString(string S1, string Delim) {
    int pos = 0;

    string SWord;

    vector<string>VString;
    while ((pos = S1.find(Delim)) != std::string::npos) {
        SWord = S1.substr(0, pos);
        if (SWord != " ") {
            VString.push_back(SWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "") {
        VString.push_back(S1);
    }
    return VString;
}
string JoinString(vector<string>VString, string Delim) {
    if (VString.empty()) return"";

    string S1;
    for (string& s : VString) {
        S1 = S1 + s + Delim;
    }
    return S1.substr(0, S1.length() - Delim.length());
}
string ReplaceWordInString(string S1, string StringToReplace, string sReplaceTo) {

    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos) {
        S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
        pos = S1.find(StringToReplace);
    }
    return S1;
}

string FormateDate(sDate Date, string DateFormat = "dd/mm/yyyy") {

    string DateString;
    DateString += ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
    DateString += ReplaceWordInString(DateFormat, "mm", to_string(Date.Month));
    DateString += ReplaceWordInString(DateFormat, "yyyy", to_string(Date.Year));
    return DateString;
}


sDate StringToDateStructure(string DateString) {
    sDate Date;
    vector<string>VDate = SplitString(DateString, "/");

    Date.Day = stoi(VDate[0]);
    Date.Month = stoi(VDate[1]);
    Date.Year = stoi(VDate[2]);

    return Date;

}
string DateStructureToString(sDate Date) {
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}


int main()
{
    std::cout << "Hello World!\n";
}

