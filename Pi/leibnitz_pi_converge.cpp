#include <iostream>
#include <cmath>
#include <iomanip> // defines set::precision
#include <cfloat>
using namespace std;


int main (){
    // start with an outter loop that runs from 2 until n = 2*20, the value of n doubles each itteration. then you pass
    // that value of n into the inner loop which calculates the current value of pi and prints it out, along with n

    double piOver4 = 0.0;
    double pi = 0.0;
    cout << setprecision(DBL_DIG);
    for (int n = 2; n <= 1048576; n = n * 2){
        for (int k = 0; k <= n; k++){
            piOver4 = (pow(-1.0, k) / ((2*k) + 1));
            pi += 4 * piOver4;
        }
        cout << fixed;
        cout << "PI: " << pi << "; N: " << n << endl;
        pi = 0.0;

    }

    return 0;

}