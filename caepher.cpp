#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

//function prototypes
void file_prompt(string& i, string& o);
char encrypt(char pch);
char decrypt(char cch);
// void add_words();

//containers for words
vector<string> enc_vec;
vector<string> input; 

//declaration and initialise variables
string p = "";
string c = "";
int key{};
string alphabet{"abcdefghijklmnopqrstuvwxyz"};
string line;

// main function
int main(){
	string in, out;

	file_prompt(in, out); 
	ifstream infile(in);	// file to read from
	ofstream outfile(out); // file to write to	

	//	input key for encryption
	cout << "Enter a key: ";
	cin >> key;

	cout << "\n";

	//	check if file is ok 
	if( infile.good() == false){
		cout << "Unable to open plaintext file\n";
		exit(1);
	}

	cout << "Reading plaintext file\n";

	//	read file contents and store in container
	while( !infile.eof() ){
		getline(infile, line);
		input.push_back(line);
	}

	//	perform Ceaser encryption and store results in container
	for(unsigned int j=0; j<input.size(); j++){
		p = input[j];
		for(unsigned int i=0; i<p.length(); i++){	
			c += encrypt(p[i]);
		}
			enc_vec.push_back(c);
			p = "";
			c = "";
	}

	cout << "Writing encrypted words to file\n";

	//	write encrypted contents to file
	for(string s: enc_vec){
		outfile << s << endl;
	}

/*
	for(unsigned int j=0; j<enc_vec.size(); j++){
		p = enc_vec[j];
		for(unsigned int i=0; i<p.length(); i++){	
			c += decrypt(p[i]);
		}
			outfile << c << endl;
			p = "";
			c = "";
	}
*/

	return 0;
}

void file_prompt(string& i, string& o){
	cout << "Please enter a filename to read from: ";
	cin >> i;
	cin.clear();
	cin.ignore(1000, '\n');
	 
	cout << "Now enter a filename to write to: ";
	cin >> o;
	cin.clear();
	cin.ignore(1000, '\n'); 
}


char encrypt( char pch ){
    int letter {0}, ch{};
	
	if( isalpha( pch ) ){
		while( pch != alphabet[ letter ]){
			letter++;
		}
		ch = ( letter+key ) % 26;
		return alphabet[ch];    	
	}else if( isspace( pch ) ){
		char s = ' ';
		return s;
	}else{
		return pch;
	}	
}

/*
char decrypt(char cch){
   int letter {0}, ch{};
    while(cch != alphabet[letter]){
        letter++;
    }
    ch = (letter-key) % 26;
    return alphabet[ch];  
}

void add_words(){
	cout << "Enter a word(s) to be encrypted: ";
	cin >> p;
	cin.clear();
	cin.ignore(1000, '\n');
} */
