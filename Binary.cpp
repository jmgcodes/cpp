/*
 * Program: Binary Number
 * 
 * Author: Jwala Mohith Girisha
 * 
 */


#include<iostream>

using namespace std;

int main(){
	
	cout << "This prints the binary representation of a number." << endl;
	
	int num;
	int arr[8] = {0,0,0,0,0,0,0,0};
	cout << "Enter a number: ";
	
	cin >> num;
	
	int temp = num;
	int i=0;
	
	
	while(temp){
		
		arr[i] = temp%2;
		temp /= 2;
		i++;
		
	}
	
	cout << endl << "Binary number: ";

	for(int j=i-1; j>=0; j--){
		
		cout<<arr[j];
		
	}
	
	cout << endl << "Gray number: ";
	
	cout << arr[i-1];
	for(int j=i-1; j>0; j--){
		
		int tmp = (arr[j])==(arr[j-1])?0:1;
		cout << tmp;
	
	}
	
	
	return 0;
}
		
