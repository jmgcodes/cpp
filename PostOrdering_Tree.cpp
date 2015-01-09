/*
 * Program: Print post-order from pre-order and in-order
 * 
 * Author: Jwala Mohith Girisha
 * 
 */


#include<iostream>

using namespace std;

void print_array(int arr[], int n);
int search(int arr[], int root, int n);
void print_post(int in[], int pre[], int size);

int main(){
	
	cout << "This program prints post-ordering of tree from pre and in-order sets" << endl;
	
	int pre[] = {9,4,2,6,15,12,17};
	int in[] = {2,4,6,9,12,15,17};
	
	int size = sizeof(pre)/sizeof(pre[0]);
	
	cout << endl << "Pre-order: ";print_array(pre, size);
	cout << endl << "In-Order: ";print_array(in, size);
	cout<< endl << endl << "Post-order: ";
	print_post(in, pre, size);
	
	return 0;
	
}

void print_array(int arr[], int n){
	
	for(int i=0; i<n; i++){
		cout << *(arr+i) << " ";
	}
}

int search(int arr[], int root, int n){
	
	for(int i=0; i<n; i++){
		if(arr[i]==root)
			return i;
	}
	return -1;
}

void print_post(int in[], int pre[], int size){
	
	int root = search(in, pre[0], size);
	
	if(root != 0)
		print_post(in,pre+1,root);
	
	if(root != size-1)
		print_post(in+root+1,pre+root+1,size-root-1);
		
	cout << pre[0] << " ";
	
}
	
