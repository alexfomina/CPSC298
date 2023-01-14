#include <iostream>
#include <string>
#include <cstring>
using namespace std;
// input each single character from the message code & compare it to ECA (hardcoded)
// if all of the characters are true, pint "Message is authentic"
int main(){
    // part one, defining auth code on card
    // const char TrueChar1[] = "E";
    // const char TrueChar2[] = "C";
    // const char TrueChar3[] = "A";
    const char TrueChar1 = 'E';
    const char TrueChar2 = 'C';
    const char TrueChar3 = 'A';
    string Auth_Code = "";
    string Message = "";
    
    char Char1;
    cout << "Enter the first character of the message code ";
    cin >> Char1;

    char Char2;
    cout << "Enter the second character of the message code ";
    cin >> Char2;

    char Char3;
    cout << "Enter the third character of the message code ";
    cin >> Char3;

    Auth_Code += TrueChar1;
    Auth_Code += TrueChar2;
    Auth_Code += TrueChar3;
    cout << "Authenticator code: " << Auth_Code << endl;
    Message += Char1;
    Message += Char2;
    Message += Char3;
    cout << "Message Code: " << Message << endl;

    //part 2, comparing each character
    if (TrueChar1 == Char1 && TrueChar2 == Char2 && TrueChar3 == Char3)
    {
        cout << "Message is authentic." << endl;
    }
    else{
        cout << "Message is invalid." << endl;
    }
    //part 3, comparing the strings for concurrence
    if(Auth_Code == Message){
        cout << "Concurrence: message is authentic" << endl;
    }
    else{
        cout << "Concurrence: message is invalid" << endl;
    }
    //part 4

    cout << "Characterization of Message Code" << endl;
    cout << "--------------------------------" << endl;
    cout << "ASCII Values of Message Code Character: " << int(Char1)<< ", "<< int(Char2) << ", " << int(Char3) << endl;
    cout << "Sum of ASCII values for Message Code Characters:" << int(Char1) + int(Char2) + int(Char3) << endl;

    const int ValidCodeChecksum = 5;
    int messageCheckSum;
    messageCheckSum = (int(Char1) + int(Char2) + int(Char3)) % 7;
    if (messageCheckSum == ValidCodeChecksum)
    {
        cout << "Message Code Checksum is valid: " << messageCheckSum << endl;
    }
    else{
        cout << "Message Code Checksum is invalid: " << messageCheckSum << "; expected: " << ValidCodeChecksum << endl;
    }

    //printing which characters are wrong if any
    if (Char1 != TrueChar1){
        cout << "First characters do not match: Message: " << Char1 << "; Authenticator: " << TrueChar1 << endl;
    }
    if (Char2 != TrueChar2){
        cout << "Second characters do not match: Message: " << Char2 << "; Authenticator: " << TrueChar2 << endl;
    }
    if (Char3 != TrueChar3){
        cout << "Third characters do not match: Message: " << Char3 << "; Authenticator: " << TrueChar3 << endl;
    }

    //comparing message code lexicographically
    if (Message < Auth_Code == true){
        cout << "Message Code (" << Message << ") is lexicographically less than Authenticator code (" << Auth_Code <<")" << endl;

    }
    else if(Message > Auth_Code == true){
        cout << "Message code (" << Message << ") is lexicographically less than Authenticator code (" << Auth_Code << ")" << endl;
    }



}