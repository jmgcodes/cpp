/*
 * Program: Quick sort
 * 
 * Author: Jwala Mohith Girisha
 * 
 */


#include<iostream>

using namespace std;

void quick_sort(int arr[], int left, int right);

int main(){
	
	int arr[] = {1, 6, 4, 0, 4, -2};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	quick_sort(arr,0, size-1);
	
	cout << "Sorted array: ";
	
	for(int i=0; i< size; i++)
		cout << arr[i] << " ";
	
	return 0;
}

void quick_sort(int arr[], int left, int right){
	
	int i=left;
	int j=right;
	int tmp;
	
	int pivot = arr[(left+right)/2];
	
	while(i<=j){
		
		while(arr[i] < pivot)
			i++;
		while(arr[j] > pivot)
			j--;
			
		if(i<=j){
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			
			i++;
			j--;
		}
	}
	
	if(left<j)
		quick_sort(arr, left, j);
	if(right>i)
		quick_sort(arr,i,right);
}
