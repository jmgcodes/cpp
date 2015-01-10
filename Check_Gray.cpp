/*
 * Program: Check if two bytes are gray codes
 * 10001000, 10001001
 * 
 * Author: Jwala Mohith Girisha
 * 
 */


#include<iostream>
#include<string>
#include<cmath>

using namespace std;

long long int bin_gray(string s);

int main(){
	
	cout << "This program checks if 2 bytes are consecutive in gray code\n\n";
	
	string s1, s2;
	
	cout << "First byte: ";
	cin >> s1;
	
	cout << "Second byte: ";
	cin >> s2;
	
	long long int b1, b2;
	
	b1 = bin_gray(s1);
	b2 = bin_gray(s2);
	
	if(b1 == b2+1 || b2 == b1+1)
		cout << "Gray numbers";
	else
		cout << "Not gray numbers";
		
	return 0;
}

long long int bin_gray(string s){
	
	long long int gray = 0;
	
	
	
	for(int i=s.length()-1;i>0;i--){
		
		gray += (((s[i]-'0')^(s[i-1]-'0'))*(pow(2,s.length()-1-i)));
		
	}
	
	gray += ((s[0]-'0')*(pow(2,s.length()-1)));
	
	return gray;
}
