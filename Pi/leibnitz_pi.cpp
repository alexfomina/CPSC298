
#include <iostream>
#include <cmath>
#include <iomanip> // defines set::precision
#include <cfloat>
using namespace std;


int main (){
    int n;
    cout << "Please enter a non-negative integer upper limit of summation for the Leibonitz formula for computing pi:" << endl;
    cin >> n;
    double piOver4 = 0.0;
    double pi = 0.0;
    cout << setprecision(DBL_DIG);
    for (int k = 0; k <= n; k++){
        piOver4 = (pow(-1.0, k) / ((2*k) + 1));
        pi += 4 * piOver4;
    }
    cout << fixed;
    cout << "PI (approx): " << pi << "; n: " << setw(7) << n << endl;
    cout << "PI (actual): " <<"3.141592653589793" << endl;
    cout << "Decimal digits of precision: " << DBL_DIG << endl;
    cout << "Number of base 2 mantissa difits of double precision floating point value: " << DBL_MANT_DIG << endl;
    cout << "Next representable number from 3.141592653589793: " << nextafter(3.141592653589793, 3.14) << endl;
    return 0;

}