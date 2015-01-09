/*
 * Program: Encrypt and Decrypt
 * 
 * Author: Jwala Mohith Girisha
 * 
 */


#include<iostream>
#include<string.h>
#include<fstream>
#include<sstream>

using namespace std;

int main(){
	
	cout << "This program read a file, encrypts the data and writes to another file. Decryption is also handled." << endl << endl;
	
	string alpha;
	fstream myfile ("string.txt");
	
	if(myfile.is_open()){
		cout << "String to encrypt: ";
		while( getline(myfile, alpha)){
			cout << alpha << endl;
			break;
		}
		myfile.close();
	}
	
	int len = alpha.length();
	
	cout << "Length: " << len << endl;
	
	fstream enc;
	enc.open("encrypt.txt", ios::out | ios::in | ios::trunc);
	if(enc.is_open()){
		for(int i=0; i<len; i++){
			int ch = alpha[i]-62;
			enc << ch;
		}
		enc.close();
	}
	
	string encstr;
	enc.open("encrypt.txt", ios::in);

	cout<< "Encrypted: ";
	if(enc.is_open()){
		
		while( getline(enc, encstr)){
			cout << encstr << endl;
		}
		enc.close();
	}
	
	int enclen = encstr.length();
	
	cout << "Decrypted: ";
	for(int i=0; i<enclen;){
		
		string dec;
		if(encstr[i] == '1' || encstr[i] == '2'){
			dec = encstr[i];
			dec += encstr[i+1];

			int value;
			stringstream convert(dec);
			if ( !(convert >> value) )
					value = 0;
					
			dec = value + 62;
			i++;
		}
		else{
			dec = encstr[i];

			int value;
			stringstream convert(dec);
			if ( !(convert >> value) )
					value = 0;
					
			dec = value + 62;
		}
		i++;
		cout << dec;
	}
	
	
	return 0;
	
}
