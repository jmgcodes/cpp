/*
 * Program: Sorted array to a BST
 * 
 * Author: Jwala Mohith Girisha
 * 
 */
 
 #include<iostream>
 #include<stdlib.h>
 
 using namespace std;
 
 struct node{
	 
	 int data;
	 struct node* left;
	 struct node* right;
	 
 };
 
 struct node* newnode(int value){
	 
	 struct node* newnode = (struct node*) malloc(sizeof(struct node*));
	 
	 newnode->data = value;
	 newnode->left = NULL;
	 newnode->right = NULL;
	 
	 return newnode;
	 
 }
 
 struct node* array_bst(int arr[], int start, int end){
	 
	 if(start>end)
		return NULL;
	
	int mid = (start+end)/2;
	
	struct node* root = newnode(arr[mid]);
	
	root->left = array_bst(arr, start, mid-1);
	root->right = array_bst(arr, mid+1, end);
	
	return root;
	
}

void printPreorder(struct node* root){
		
	if(root==NULL)
		return;
	
	cout << root->data << " ";
	printPreorder(root->left);
	printPreorder(root->right);
	
}

int main(){
	
	int arr[] = {1,2,3,4};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	struct node* root = array_bst(arr, 0, size-1);
	
	cout << "Printing the BST in preorder" <<endl;

	printPreorder(root);
	
	return 0;
}
