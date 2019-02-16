#include <iostream>
#include <string>

using namespace std;

char encrypt(char pch);

// char Caesar::decrypt(char cch)
string p{},c{};
int key{};
string alphabet{"abcdefghijklmnopqrstuvwxyz"};


int main(){

	cout << "Enter a word(s) to be encrypted: ";
	cin >> p;
	cin.clear();
	cin.ignore(1000, '\n');

	cout << "Enter a key: ";
	cin >> key;

	for(unsigned int i=0; i<p.length(); i++){		
		c += encrypt(p[i]);
	}

	cout << "Plaintext: " << p << endl;
	cout << "Cipher: " << c << endl;

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

/* char decrypt(char cch){
   int letter {0}, ch{};
    while(cch != alphabet[letter]){
        letter++
    }
    ch = ((letter+1)-key) % 26;
    return alphabet[ch];  
}
*/
