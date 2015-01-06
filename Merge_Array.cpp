/*
 * Program: Merge two sorted arrays
 * 
 * Author: Jwala Mohith Girisha
 * 
 */
 
 #include<iostream>

using namespace std;

void print_array(int *ptr, int len);
void merge_arrays(int *ptr1, int len1, int *ptr2, int len2, int *ptr3);

struct node{
	
	int data;
	struct node* next;
	
}*list1, list2;

int main(){
	
	cout << "This is a program to merge two Arrays\n\n" << endl;
	
	int n1, n2, n3; 
	int array1[100], array2[100], array3[200];
	
	cout << "Enter the number of elements in 1st array: ";
	cin >> n1;
	
	cout << "\nEnter the " << n1 << " sorted elements of the 1st array\n";
	
	for(int i=0; i<n1 ; i++){
		
		cin >> array1[i];
		
	}
	
	cout << "Enter the number of elements in 2nd array: ";
	cin >> n2;
	
	cout << "\nEnter the " << n2 << " sorted elements of the 2nd array\n";
	
	for(int i=0; i<n2 ; i++){
		
		cin >> array2[i];
		
	}
	
	cout << "Arrays to be merged\n";
	
	print_array(array1,n1);
	print_array(array2,n2);
	
	merge_arrays(array1,n1,array2,n2,array3);
	
	cout << "\nMerged array\n";
	
	n3 = n1 + n2;
	
	print_array(array3, n3);
	
	return 0;
	
}


//Print Array
void print_array(int *ptr, int len){
	
	for(int i=0; i<len; i++){
		
		cout << *(ptr+i) << " ";
		
	}
	cout << "\n";
}


//Merge arrays
void merge_arrays(int *ptr1, int len1, int *ptr2, int len2, int *ptr3){
	
	int i = 0, j = 0, k = 0;
	
	while (i<len1 && j<len2){
		
		if(*(ptr1+i)<*(ptr2+j)){
			
			*(ptr3+k) = *(ptr1+i);
			i++;
		}
		else{
			*(ptr3+k) = *(ptr2+j);
			j++;
		}
		k++;
	}
	
	if(i == len1 && j != len2){
		
		while(j!=len2){
			*(ptr3+k) = *(ptr2+j);
			j++; k++;
		}
	}
	else if (i != len1 && j == len2){
		
		while(i!=len1){
			*(ptr3+k) = *(ptr1+i);
			i++; k++;
		}
	}
	
}
