#include <iostream>
#include <string>
#include <cmath>
#include "MusicalNoteApi.h"
using namespace std;

double computeFrequency(int nu, int k)
{
    double f = -1.0; 

    if ( (k >= 0) && (k < k_nHalfTonesInOctave) && (nu >=0) ){
        double Two_to_Twelfth = 1.059463094359;
        f = k_dFrequencyRef * pow(2, nu) * pow(Two_to_Twelfth, k);
    }
    else
    {
        cerr << "ERROR: computeFrequency preconditions not satisfied ; dFrequencyHz nu (" << nu << ") or k (" << k << ") invalid" << endl;
    }
    return f;
}

double computeWavelengthInCm(double dFrequencyHz)
{
    double dWavelengthCm = -1.0; 
    if ((dFrequencyHz < 0.0) || (!isfinite(dFrequencyHz)) || (FP_ZERO == fpclassify(dFrequencyHz)))
    {
        dWavelengthCm = -1.0; // Indicate Error
        cerr << "ERROR: computeWavelengthInCm preconditions not satisfied; dFrequencyHz invalid: " << dFrequencyHz << endl;
    }
    else 
    {
        dWavelengthCm = k_dSpeedOfSoundCmPerSecond / dFrequencyHz;
    }
    return dWavelengthCm;
}

const string getNoteName(int nu, int k)
{
    const static string a_strNotePrefix[] = {
    "C", "C#", "D","D#", "E", "F", "F#", "G", "G#", "A", "A#", "B",
    };
    string strNote = "UNK";
    string nu_as_a_string;

    if ((k >= 0) && (k < k_nHalfTonesInOctave) && (nu >= 0))
    {
        for (int i = 0; i < 12; ++i ){
            if(i == k){
                strNote = a_strNotePrefix[i];
            }
        }
        nu_as_a_string = to_string(nu);
        strNote = strNote + nu_as_a_string;
    }
    return strNote;
}

int main()
{
    int nOctaves = 11; 
    for (int nu = 0; nu < nOctaves; nu++)
    {
        for (int k = 0; k < k_nHalfTonesInOctave; k++)
        {
            double f;
            f = computeFrequency(nu, k);
            double dWavelengthCentimeters;
            dWavelengthCentimeters = computeWavelengthInCm(f);
            string strNote;
            strNote = getNoteName(nu, k);

            cout << "Note: " << strNote << "; nu: " << nu << "; k: " << k << "; frequency: " << f << " Hz; wavelength: " << dWavelengthCentimeters << " cm" << endl;
        }
    }

    cout << endl << endl;
    cout << "------------------------------------------------ CHECK ERROR // HANDLING ---------------------------------------------------------------" << endl;
    double f = computeFrequency(-1, -1);
    double dWavelengthCentimeters = computeWavelengthInCm(-16.35);
    string strNote = getNoteName(-1, -1);
    cout << "Note: " << strNote << "; nu: -1; k: -1; frequency: " << f << " Hz; wavelength: " << dWavelengthCentimeters << " cm" << endl;

    return 0;
}

