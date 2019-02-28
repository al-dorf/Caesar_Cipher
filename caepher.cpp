#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

char encrypt(char pch);

char decrypt(char cch);

// void add_words();

vector<string> enc_vec;
vector<string> input; 

string p = "";
string c = "";
int key{};
string alphabet{"abcdefghijklmnopqrstuvwxyz"};


int main(){
	ifstream infile("plain.dat");
	ofstream outfile("cipher.dat");
	string line;
	vector<string> input; 

	cout << "Enter a key: ";
	cin >> key;

	cout << "\n";

	if( infile.good() == false){
		cout << "Unable to open plaintext file\n";
		exit(1);
	}

	cout << "Reading plaintext file\n";

	while( !infile.eof() ){
		getline(infile, line);
		input.push_back(line);
	}

	for(unsigned int j=0; j<input.size(); j++){
		p = input[j];
		for(unsigned int i=0; i<p.length(); i++){	
			c += encrypt(p[i]);
		}
			enc_vec.push_back(c);
			p = "";
			c = "";
	}

	cout << "Writing encryted words to file\n";

	for(unsigned int j=0; j<enc_vec.size(); j++){
		p = enc_vec[j];
		for(unsigned int i=0; i<c.length(); i++){	
			p += decrypt(c[i]);
		}
			outfile << p << endl;
			p = "";
			c = "";
	}

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
/*
void add_words(){
	cout << "Enter a word(s) to be encrypted: ";
	cin >> p;
	cin.clear();
	cin.ignore(1000, '\n');
} */
