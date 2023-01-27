#include <iostream>
#include "ecu.h"
using namespace std;

void ElectronicControlUnit::Initialize()
{
    Activated_Belt_Tires = 0;
    Activated_Hydraulic_Jacks = 0;
    Activated_IR_Illumination = 0;
}
void ElectronicControlUnit::actuateHydraulicJacks()
{
    if (Activated_Hydraulic_Jacks == 0)
    {
        cout << "Hydraulic Jacks activated" << endl;
        Activated_Hydraulic_Jacks = 1;

        if (Activated_Belt_Tires == true)
        {
            cout << "Belt Tires deactivated" << endl;
            Activated_Belt_Tires = 0;
        }
    }
    else if (Activated_Hydraulic_Jacks == 1)
    {
        cout << "Hydraulic Jacks deactivated" << endl;
        Activated_Hydraulic_Jacks = 0;

    }

}

void ElectronicControlUnit::actuateBeltTires()
{
    if (Activated_Belt_Tires == false)
    {
        cout << "Belt tires activated" << endl;
        Activated_Belt_Tires = true;
    }
    else{
        cout << "Belt tires deactivated" << endl;
        Activated_Belt_Tires = false;
    }
}

void ElectronicControlUnit::actuateIllumination()
{
    if (Activated_IR_Illumination == false)
    {
        cout << "Infared Illumination activated" << endl;
        Activated_IR_Illumination = true;
    }
    else{
        cout << "Infared Illumination deactivated" << endl;
        Activated_IR_Illumination = false;
    }
}


void ElectronicControlUnit::handleCommand(char cCommand)
{
    switch(cCommand)
    {
    case 'A':
        actuateHydraulicJacks();
        break;
    case 'a':
        actuateHydraulicJacks();
        break;
    case 'B':
        actuateBeltTires();;
        break;
    case 'b':
        actuateBeltTires();
        break;        
    case 'E':
        actuateIllumination();
        break;
    case 'e':
        actuateIllumination();
        break;
    }
}



