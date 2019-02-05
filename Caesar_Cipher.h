#ifndef _Caesar_Cipher_
#define _Caesar_Cipher_
#include <iostream>
#include <string>
#include <vector>
 
 class Caesar{
    public:
			Caesar(std::string text, int key);

            void encrypt();

            void decrypt();

            std::string enc_msg();

            std::string dec_msg();

    private:

    std::string plain;

    std::string cipher;

    int key {};

    std::string alphabet;
 };

 #endif