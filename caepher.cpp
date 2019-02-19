#include <iostream>
#include <string>

using namespace std;

char encrypt(char pch);

char decrypt(char cch);

string p = "";
string c = "";
int key{};
string alphabet{"abcdefghijklmnopqrstuvwxyz"};


int main(){

	cout << "Enter a word(s) to be encrypted: ";
	cin >> p;
	cin.clear();
	cin.ignore(1000, '\n');

	cout << "Enter a key: ";
	cin >> key;

	cout << "\n";

	cout << "Plaintext before encryption: " << p << endl;
	for(unsigned int i=0; i<p.length(); i++){		
		c += encrypt(p[i]);
	}
	p = "";
	cout << "Plaintext after encryption: " << p << endl;

	cout << "\n";
	
	cout << "Ciphertext before decryption: " << c << endl;
	for(unsigned int i=0; i<c.length(); i++){		
		p += decrypt(c[i]);
	}
	c = "";
	cout << "Ciphertext after decryption: " << p << endl;

return 0;
}

char encrypt(char pch){
    int letter {0}, ch{};
    while(pch != alphabet[letter]){
        letter++;
    }
    ch = (letter+key) % 26;
    return alphabet[ch];
}

char decrypt(char cch){
   int letter {0}, ch{};
    while(cch != alphabet[letter]){
        letter++;
    }
    ch = (letter-key) % 26;
    return alphabet[ch];  
}

