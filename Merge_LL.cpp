/*
 * Program: Merge two sorted linked lists
 * 
 * Author: Jwala Mohith Girisha
 * 
 */
 
#include<iostream>
#include<stdlib.h>
#include<cstddef>

using namespace std;

void print_array(int *ptr, int len);
void merge_arrays(int *ptr1, int len1, int *ptr2, int len2, int *ptr3);
void create_linkedlist(int *ptr, struct node **list, int len);
void print_linkedlist(struct node* list);
void merge_linkedlist(struct node* list1, struct node* list2, struct node** list3);

struct node{
	
	int data;
	struct node* next;
	
}*list1 = NULL, *list2 = NULL, *list3 = NULL;

int main(){
	
	cout << "This is a program to merge two LLs\n\n" << endl;
	
	int n1, n2, n3; 
	int array1[100], array2[100], array3[200];
	
	cout << "Enter the number of elements in 1st LL: ";
	cin >> n1;
	
	cout << "\nEnter the " << n1 << " sorted elements of the 1st LL\n";
	
	for(int i=0; i<n1 ; i++){
		
		cin >> array1[i];
		
	}
	
	cout << "Enter the number of elements in 2nd LL: ";
	cin >> n2;
	
	cout << "\nEnter the " << n2 << " sorted elements of the 2nd LL\n";
	
	for(int i=0; i<n2 ; i++){
		
		cin >> array2[i];
		
	}
	
	cout << "LLs to be merged\n";
	
	print_array(array1,n1);
	print_array(array2,n2);
	
	create_linkedlist(array1, &list1, n1);
	create_linkedlist(array2, &list2, n2);
	
	cout << "Linked lists created\n";
	
	print_linkedlist(list1);
	
	cout << "\n";
	
	print_linkedlist(list2);
	
	merge_linkedlist(list1,list2,&list3);
	
	cout << "\nMerged LL\n";
	print_linkedlist(list3);
	
	/*
	merge_arrays(array1,n1,array2,n2,array3);
	
	cout << "\nMerged array\n";
	
	n3 = n1 + n2;
	
	print_array(array3, n3);
	*/
	return 0;
	
}

//Create Linked List
void create_linkedlist(int *ptr, struct node **list, int len){
	
			struct node* new_node, *current_node;

	int i=0;
	while(i!=len){
		new_node = (struct node*) malloc(sizeof(struct node));
		new_node->data = *(ptr+i);
		new_node->next = NULL;

		if(*list == NULL){
		
			current_node = new_node;
			*list = new_node;
		
		}
		else{
		
			current_node->next = new_node;
			current_node = new_node;
		
		}
		i++;
	}
}

void print_linkedlist(struct node* list){
	
	struct node *new_node;
	new_node=list;
	
	while(new_node!=NULL){
		cout << new_node->data << " ";
		new_node=new_node->next;
   }
}

void merge_linkedlist(struct node* list1, struct node* list2, struct node** list3){
	
	struct node* temp1 = list1;
	struct node* temp2 = list2;
	struct node* temp3, *current;
	
	while(temp1 != NULL && temp2 != NULL){
		
		temp3 = (struct node*) malloc(sizeof(struct node));
		temp3->next = NULL;
		
		if(temp1->data < temp2->data){
			
			temp3->data = temp1->data;
			temp1 = temp1->next;
		}
		else{
			temp3->data = temp2->data;
			temp2 = temp2->next;
		}
		
		if(*list3 == NULL){
			
			*list3 = temp3;
		}
		else{
			
			current->next = temp3;
		}
		current = temp3;		
	}
	
	if(temp1==NULL){
		current->next = temp2;
	}
	else{
		current->next = temp1;
	}
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
