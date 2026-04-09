

#include <iostream>
using namespace std;
enum enWeeekDay { sun=1,mon=2,tus=3,wen=4,thu=5,fri=6,sat=7 };
void showWeekDayMenu() {
    cout << "********************************" << endl;
    cout << "          Week days             " << endl;
    cout << "********************************" << endl;
    cout<<"1: Sunday"<<endl;
    cout<<"2: Monday"<<endl;
    cout<<"3: Tuesday"<<endl;
    cout<<"4: Wednesday"<<endl;
    cout<<"5: Thursday"<<endl;
    cout<<"6: Friday"<<endl;
    cout<<"7: Saturday"<<endl;
    cout << "********************************" << endl;
    cout << "Please enter the number of day :";

}
enWeeekDay ReadWeekDay() {
    int n;
    cin >> n;
    return (enWeeekDay)n;
}
string GetWeekDay(enWeeekDay WeekDay) {
    switch (WeekDay) {
    case enWeeekDay::sun:
        return "Sunday";
        break;
    case enWeeekDay::mon:
        return "Monday";
        break;
    case enWeeekDay::tus:
        return "Tuesday";
        break;
    case enWeeekDay::wen:
        return "Wednesday";
        break;
    case enWeeekDay::thu:
        return "ThursDay";
        break;
    case enWeeekDay::fri:
        return "Friday";;
        break;
    case enWeeekDay::sat:
        return "Saturday";
        break;
    default: 
        return "Not a week day";
     }

}
int main()
{
    /*int D;
    cout << " Enter the number of day :";
    cin >> D;
    switch (D) {
         case 1:
             cout << "The day is Saturday";
             break;
         case 2:
     
             cout << " The day is Sunday ";
             break;
         case 3:
     
             cout << " The day is Monday "; 
             break;
         case 4:
     
             cout << " The day is Tuesday ";
             break;
         case 5:
     
           cout << " The day is Wednesday ";
           break;
         case 6:
     
            cout << " The day is Thursday ";
            break;
         case 7:
     
              cout << " The day is Friday ";
              break;
         default:  
             cout << " Wrong.";
    }*/
    showWeekDayMenu();
    cout << "Today is "<< GetWeekDay(ReadWeekDay()) << endl;
    return 0;
}