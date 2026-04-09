
#include <iostream>

using namespace std;

class clsPerson {
private:

    int _ID = 0;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:

    clsPerson(string FirstName, string LastName, string Email, string Phone, int ID = 0) {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }

    void setEmail(string Email) {
        _Email = Email;
    }

    void setFirstName(string FirstName) {
        _FirstName = FirstName;
    }

    void setLastName(string LastName) {
        _LastName = LastName;
    }

    void setPhone(string Phone) { 
        _Phone = Phone;
    }


    int ID(){
        return _ID;
    }

    string FirstName() {
        return _FirstName;
    }

    string LastName() {
        return _LastName;
    }

    string Email() {
        return _Email;
    }

    string Phone() {
        return _Phone;
    }

    void Print() {
        cout << "\nInfo:";
        cout << "\n_____________________________";
        cout << "\nID         : " << _ID;
        cout << "\nFirst Name : " << _FirstName;
        cout << "\nLast Name  : " << _LastName;
        cout << "\nEmail      : " << _Email;
        cout << "\nPhone      : " << _Phone;
        cout << "\n_____________________________\n";
    }

    void SendSMS(string TextMessage) {
        cout << "\nThe following SMS sent successfuly to phone : " << _Phone;
        cout << "\n" << TextMessage << endl;
    }

    void SendEmail(string Subject,string Body) {
        cout << "\nThe following message sent successfuly to email : " << _Email;
        cout << "\nSubject : " << Subject;
        cout << "\nBody : " << Body << endl;
    }


};
    
int main()
{
    clsPerson Person( "Ahmad", "Shaker", "Ahamdshh@gmail.com", "0956872241",18);
    Person.Print();

    Person.SendSMS("How are you ?");
    Person.SendEmail("Hi", "Where are you ?");

    system("pause>0");
}

