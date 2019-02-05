#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "Caesar_Cipher.h"

using namespace std;

string plain{}, cipher{}, alphabet {"abcdefghijklmnopqrstuvwxyz"};;
int key {};



Caesar::Caesar(string text, int k){
    plain = text;
    key = k;
}

void Caesar::encrypt(){
    int ch{}, letter{};
    for(unsigned int i=0; i<plain.length(); i++){
        if(isspace(plain[i]))
            cipher += plain[i];
        else{
            while(plain[i] != alphabet[i]){
                letter++;
            }
            ch = (((letter+1)+key) % 26 );
            cipher += alphabet[ch];
        }
    }
    plain="";
}

void Caesar::decrypt(){
    int ch{}, letter{};
    for(unsigned int i=0; i<cipher.length(); i++){
        if(isspace(cipher[i]))
            plain += cipher[i];
        else{
            while(cipher[i] != alphabet[i]){
                letter++;
            }
            ch = ((cipher[i]-key) % 26 );
            plain += alphabet[ch];
        }
    }
    cipher="";
}

string Caesar::enc_msg(){
    return plain;
}

string Caesar::dec_msg(){
    return cipher;
}


