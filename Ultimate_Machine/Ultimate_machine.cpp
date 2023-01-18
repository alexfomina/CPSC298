#include <iostream>
using namespace std;

class CUltimateMachine
{

public:
    CUltimateMachine(): m_bState(false)
    {
        cout << "CUltimateMachine constructor (ctor) called" << endl;

    }

    ~CUltimateMachine()
    {
        cout << "CUltimateMachine destructor (dtor) called" << endl;
    }

    void displayState()
    {
        switch (m_bState) {
        case true:
            cout << "Ultimate Machine is ON" << endl;
            break;
        case false:
            cout << "Ultimate Machine is OFF" << endl;
            break;
        }
        
    }

    void turnOn()
    {
        m_bState = true;
        displayState();
        if (true == m_bState)
        {
            m_bState = false;
        }
        displayState();
    }
private:
    bool m_bState; // true ON, false OFF
};

int main()
{
    cout << "The Ultimate Machine Simulation" << endl;
    CUltimateMachine ultmach;
    ultmach.displayState();
    ultmach.turnOn();
}