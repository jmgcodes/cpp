/*
 * Program: Check if string is rotated version
 * 
 * Author: Jwala Mohith Girisha
 * 
 */


#include<iostream>
#include<string.h>

using namespace std;

int main(){

	string s1 = "abcde";
	string s2 = "cdeab";
	
	if(s1.length()!=s2.length() || s1==s2)
		cout << "Not a rotated version\n";
	else{
		
		s2+=s2;
		
		size_t found = s2.find(s1);
		
		if (found!=string::npos)
			cout << "True";
		else
			cout << "False";
			
		}

	return 0;
}
