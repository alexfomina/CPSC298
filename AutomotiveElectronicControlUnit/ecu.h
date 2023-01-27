#if !defined(GAME_H)
#define GAME_H
/// @Alexandra Fomina fomina@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

// #include <tuple>    // defines std::tuple, std::tie
#include <iostream> // defines std::cout
#include <cstdlib>
#include <ctime>
using namespace std;

class ElectronicControlUnit
{
    public:
        ElectronicControlUnit()
        {
        };
        ~ElectronicControlUnit(){
        };
        void handleCommand(char cCommand);
        void Initialize();

    private:
        bool Activated_Hydraulic_Jacks; // Button A
        bool Activated_Belt_Tires; // Button B
        bool Activated_IR_Illumination; // Button E
        void actuateHydraulicJacks(); // for button A
        void actuateBeltTires(); /// button B
        void actuateIllumination(); //button E

};
#endif // !defined(GAME_H)