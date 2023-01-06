//
//  main.cpp
//  hellocin
//
//  Created by Alexandra Fomina on 1/5/23.
//@file hello_cin.cpp
// @brief Outputs a string entered by the user to standard output.
// @author Alexandra Fomina fomina@chapman.edu

#include <iostream>
#include <string>
using namespace std;
int main() {
    // insert code here...
    string strMessage;
    cout << "Please type a single word message" << endl;
    cin >> strMessage;
    cout << "Message: " << strMessage << endl;
    return 0;
}
