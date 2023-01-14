#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
// f = fr * 2^v * (2^1/12)^k

double Frequency(int v, int k){
    double Two_to_Twelfth = 1.059463094359;
    return 16.35 * pow(2, v) * pow(Two_to_Twelfth, k);
}

double WaveLength(int c, double F){
    return (c * 100) / F;
}

int main(){
    cout << "Reference Frequency: 16.35 Hz" << endl;
    cout << "Speed of Sound: 345 m/s" << endl;
    // first note
    double F;
    double W;
    F = Frequency(0,0);
    W = WaveLength(345, F);
    cout << "Note: CO; nu: 0: k: 0; frequency: " << F << "Hz; wavelength: " << W << " cm" << endl;

    F = Frequency(0,1);
    W = WaveLength(345, F);
    cout << "Note: C#O; nu: 0: k: 1; frequency: " << F << "Hz; wavelength: " << W << " cm"<< endl;

    F = Frequency(0,2);
    W = WaveLength(345, F);
    cout << "Note: DO; nu: 0: k: 2; frequency: " << F << "Hz; wavelength: " << W << " cm"<< endl;

    F = Frequency(4,0);
    W = WaveLength(345, F);
    cout << "Note: C4; nu: 4: k: 0; frequency: " << F << "Hz; wavelength: " << W << " cm"<< endl;

    F = Frequency(7,3);
    W = WaveLength(345, F);
    cout << "Note: D#7; nu: 7: k: 3; frequency: " << F << "Hz; wavelength: " << W << " cm"<< endl;

    F = Frequency(8,0);
    W = WaveLength(345, F);
    cout << "Note: C8; nu: 8: k: 0; frequency: " << F << "Hz; wavelength: " << W << " cm"<< endl;
}