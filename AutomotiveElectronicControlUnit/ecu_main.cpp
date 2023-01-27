#include "ecu.h"

int main(){
    ElectronicControlUnit ECU;
    ElectronicControlUnit();
    char cCommand;
    ECU.Initialize();
    cout << "Press X to turn off ignition or enter a steering wheel button (A, B, or E) " << endl;
    cout <<"               (A)            "<< endl;
    cout <<"    (F)        (G)        (B) " << endl;
    cout<<"     (E)                   (C) " << endl;
    cout << "              (D)            " << endl;
    cin >> cCommand;

    while (cCommand != 'X')
    {
        ECU.handleCommand(cCommand);
        cout <<"               (A)            "<< endl;
        cout <<"    (F)        (G)        (B) " << endl;
        cout<<"     (E)                   (C) " << endl;
        cout << "              (D)            " << endl;
        cin >> cCommand;                  
    }

    return 0;
}
