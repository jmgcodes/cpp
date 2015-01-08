/*
 * Program: Array basics
 * 
 * Author: Jwala Mohith Girisha
 * 
 */

#include<iostream>

using namespace std;

void print_array(int arr[], int size);

int main(){
	
	int arr[] = {1, 2, 3, 4, 5}; //Array
	
	int size = sizeof(arr)/sizeof(arr[0]); //Size of array
	cout << "Size: " << size << endl; 
	
	print_array(arr,size); //Function call to print array

	return 0;
}

void print_array(int arr[], int size){ //Function to print array
	
	cout << "Array: ";
	
	for(int i=0; i<size; i++){
		cout << arr[i] << "\t";
	}
	
	//NOTE: This wont work here. "arr" is a pointer and not really an array.
	/*
	int size_arr = sizeof(arr)/sizeof(arr[0]); //Size of array
	cout << "Size: " << size_arr << endl; 
	*/
}
