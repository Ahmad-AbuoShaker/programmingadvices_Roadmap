

#include <iostream>
using namespace std;

enum enMonth  { jan = 1, feb = 2, mar = 3, apr = 4,
    may = 5, jun = 6, jul = 7,aug = 8, sep = 9,
    Oct = 10,  nov = 11, Dec = 12 };

int ReadNumberInRange(string Message, int From, int To) {
    int Num = 0;
    do {
        cout << Message << endl;
        cin >> Num;
    } while (Num <= From && Num >= To);
    return Num;
}

enMonth ReadMonth() {
    return (enMonth)ReadNumberInRange((" Enter a Month Number \n{ jan = 1, feb = 2, mar = 3, apr = 4,")
       +(" may = 5, jun = 6,\n jul = 7, aug = 8, sep = 9, oct = 10, nov = 11, dec = 12} : "), 1, 7);
}

string GetDayOfWeek(enMonth MonthOfYear) {
    switch (MonthOfYear)
    {
    case  jan:
        return " January";
        break;    
                  
    case feb:       
        return" February";
        break;    
                  
    case mar:       
        return " March";
        break;    
                  
    case  apr:      
        return" April";
        break;    
                  
    case may:       
        return " May";
        break;    
                  
    case jun:       
        return " June";
        break;    
                  
    case jul:       
        return " July";
        break;    
                  
    case  aug:      
        return" August";
        break;    
                  
    case sep:       
        return " September";
        break;    
                  
    case Oct:
        return " October";
        break;    
                  
    case nov:      
        return " November";
        break;    
    case Dec:      
        return " December";
        break;
    default:
        return " Wrong.";
    }


}




int main()
{
    cout << GetDayOfWeek(ReadMonth()) << endl;
}