/*
 * Program: Merge sort an array
 * 
 * Author: Jwala Mohith Girisha
 * 
 */
 
 
 #include<iostream>

using namespace std;

void print_array(int *ptr, int len);
void merge_arrays(int array[], int left, int middle, int right);
void sort_array(int array[], int left, int right);


struct node{
	
	int data;
	struct node* next;
	
}*list1, list2;

int main(){
	
	cout << "This is a program to sort an array\n\n" << endl;
	
	int n1; 
	int array1[100];
	
	cout << "Enter the number of elements in the array: ";
	cin >> n1;
	
	cout << "\nEnter the " << n1 << " elements of the array\n";
	
	for(int i=0; i<n1 ; i++){
		
		cin >> array1[i];
		
	}
	
	
	cout << "Arrays to be sorted\n";
	
	print_array(array1,n1);
	
	cout << "Sorting array.....\n";
	sort_array(array1,0,n1-1);
	
	cout << "\nSorted array\n";
	print_array(array1, n1);
	
	return 0;
	
}


void sort_array(int array[], int left, int right){
	
	if(left<right){
		
		int middle = left + (right-left)/2;
		
		sort_array(array, left, middle);
		sort_array(array,middle+1,right);
		
		merge_arrays(array, left, middle, right);
		
	}
	
}


//Merge arrays
void merge_arrays(int array[], int left, int middle, int right){
	
	int i = 0, j = 0, k = 0;
	
	int len1 = middle - left + 1;
	int len2 = right - middle;
	
	int left_array[len1]; int right_array[len2];
	
	for(i=0; i<len1; i++)		
		left_array[i] = array[left+i];
		
	for(j=0; j<len2; j++)
		right_array[j] = array[middle+1+j];
		
	
	i=0; j=0; k=left;
	
	while(i<len1 && j<len2){
		
		if(left_array[i]<right_array[j]){
			
			array[k] = left_array[i];
			i++;
			
		}
		else{
			
			array[k] = right_array[j];
			j++;
			
		}
		
		k++;
	}
	
	while(i<len1){
		
		array[k] = left_array[i];
		i++;
		k++;
		
	}
	while(j<len2){
		
		array[k] = right_array[j];
		j++; k++;
		
	}
}
		
	

//Print Array
void print_array(int *ptr, int len){
	
	for(int i=0; i<len; i++){
		
		cout << *(ptr+i) << " ";
		
	}
	cout << "\n";
}

