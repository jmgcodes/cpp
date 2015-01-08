/*
 * Program: Count zeros in sorted array of 1s and 0s
 * 
 * Author: Jwala Mohith Girisha
 * 
 */

#include<iostream>

using namespace std;

void fn_iterative(int arr[], int size);
void fn_recursive(int arr[], int size);
int count_zero(int arr[],int position, int size);

int main(){
	
	cout << "This program counts the number of zeros" << endl;

	int arr[] = {0,0,0,0,0};
	int size = sizeof(arr)/sizeof(arr[0]);
	int option;
	
	cout << "Select mode: \n" << "1. Iterative\n" << "2. Recursive\n" << "Your choice: ";
	cin >> option;
	
	cout << endl;
	
	switch(option){
		
		case 1:
			fn_iterative(arr,size);
			break;
		case 2:
			fn_recursive(arr,size);
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
	}
	
	return 0;
	
}

void fn_iterative(int arr[], int size){
	
	int count = 0;
	
	for(int i=0; i<size; i++){
		
		if(arr[i]==0)			
			count++;
		else
			break;
	}
	
	cout << "Number of zeros: " << count << endl;
}

void fn_recursive(int arr[], int size){
	
	int count = 0;
	
	count = count_zero(arr, 0, size);
	
	cout << "Number of zeros: " << count << endl;
	
}

int count_zero(int arr[],int position, int size){
	
	if(position < size){
		if(arr[position+1]==0)
			return 1+count_zero(arr, position+1, size);
		else
			return 1;
	}
	else
		return 0;
}
			
	
