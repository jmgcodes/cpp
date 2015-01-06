/*
 * Program: Stack implementation using Linked list
 * 
 * Author: Jwala Mohith Girisha
 * 
 */

#include<iostream>

#define MAX 10

using namespace std;

struct node{
	
	int data;
	node* next;
	
};

class stack{
	
	private:
		node* head;
		int count;
		
	public:
		stack(){
			head = NULL;
			count = 0;
		};
		
		void push(int value);
		int pop();
		void display();
		
};

void stack::push(int value){
	
	if(head == NULL){
		
		head = new node;
		head->data = value;
		head->next = NULL;
		count++;
	}
	else{
		
		if(count<=MAX){
			node *new_node = new node;
			new_node->data = value;
			new_node->next = head;
		
			head = new_node;
			count++;
		}
		else{
			cout << "Stack full"<< endl;
		}
	}
	
}


int stack::pop(){
	
	if(head==NULL)
		cout << "Stack empty" << endl;
	else{
		int value = head->data;
		head = head->next;
		
		count--;
		
		return value;
	}
	
	return NULL;
}

void stack::display(){
	
	node *q = head;
	
	cout << "Linked list: ";
	
	while(q!=NULL){
		
		cout << q->data << "\t";
		q = q->next;
	}
	cout<<endl;
}
		
	
int main(){
	
	stack mystack;
	
	mystack.push(2);
	mystack.push(7);
	mystack.push(0);
	mystack.push(4);
	mystack.push(7);



	mystack.display();
	
	mystack.pop();

	mystack.display();
	
	return 0;
}	
		
