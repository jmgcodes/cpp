/*
 * Program: Sorted LL to BST
 * 
 * Author: Jwala Mohith Girisha
 * 
 */
 
 
#include<iostream>
#include<stdlib.h>
#include<cstddef>

using namespace std;

struct node{
	
	int data;
	struct node* next;
	
}*list1 = NULL;

struct tnode{
	
	int data;
	struct tnode* left;
	struct tnode* right;
	
};


void print_array(int *ptr, int len);
void create_linkedlist(int *ptr, struct node** list, int len);
void print_linkedlist(struct node* list);

struct tnode* LL_BST(struct node** head, int n);
struct tnode* newnode(int value);
 void printPreorder(struct tnode* root);

int main(){
	
	cout << "This is a program to merge sort a LL\n\n" << endl;
	
	int n1; 
	int array1[100];
	
	cout << "Enter the number of nodes in the LL: ";
	cin >> n1;
	
	cout << "\nEnter the " << n1 << " data values of nodes\n";
	
	for(int i=0; i<n1 ; i++){
		
		cin >> array1[i];
		
	}
	
			
	create_linkedlist(array1, &list1, n1);
	
	cout << "Linked lists created\n";
	
	struct tnode* bst = LL_BST(&list1, n1);
	
	cout << "BST" << endl;
	
	printPreorder(bst);
	
	return 0;
	
}

struct tnode* newnode(int value){
	
	struct tnode* newnode = (struct tnode*) malloc(sizeof(struct tnode*));
	newnode->data = value;
	newnode->left = NULL;
	newnode->right = NULL;
	
	return newnode;
}

struct tnode* LL_BST(struct node** head, int n)
{
    if (n <= 0)
        return NULL;
 
    struct tnode *left = LL_BST(head, n/2);
 
    struct tnode *root = newnode((*head)->data);
    root->left = left;
 
    *head = (*head)->next;
 
    root->right = LL_BST(head, n-n/2-1);
 
    return root;
}

 void printPreorder(struct tnode* root){
		
	if(root==NULL)
		return;
	
	cout << root->data << " ";
	printPreorder(root->left);
	printPreorder(root->right);
	
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
