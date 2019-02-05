#include <iostream>
#include <string>
#include "Caesar_Cipher.h"

using namespace std;

int main(){
    string msg {};
    int k {};

    cout << "Please enter a message: ";
    cin >> msg;
    cin.clear();
    // cin.ignore(1000,'\n');
    cout << "\n";
    cout << "Please enter a number for the key, between 1 and 26: ";
    cin >> k;

    cout << "\n";

    cout << "Plaintext: " << msg << endl;
    cout << "Key: " << k << endl; 
    
    cout << "\n";

    Caesar one(msg, k);
    cout << "Class plaintext before encrpyt: " << one.enc_msg() << endl;
    
    one.encrypt();
    cout << "Class plaintext after encrpyt: " << one.enc_msg() << endl;

    one.decrypt();
    cout << "Decrypted msg: " << one.dec_msg() << endl;
    
    cout << "Tenikiu!\n";
    return 0;
}
