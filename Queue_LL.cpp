/*
 * Program: Queue implementation using LL
 * 
 * Author: Jwala Mohith Girisha
 * 
 */

#include<iostream>

using namespace std;

struct node{
	
	int data;
	node* next;
};

class queue{
	
	private:
		node *front, *back;
		
	public:
		queue(){
			front = NULL;
			back = NULL;
		};
		void add(int value);
		int remove();
		void display();
};

void queue::add(int value){
	
	if(front == NULL && back == NULL){
		
		node *new_node = new node;
		new_node->data = value;
		new_node->next = NULL;
		
		front = new_node;
		back = new_node;
		
	}
	else{
		
		node *new_node = new node;
		new_node->data = value;
		new_node->next = NULL;
		back->next = new_node;
		
		back = new_node;
		
	}
}

int queue::remove(){
	
	if(front == NULL && back == NULL)
		cout << "Empty queue" << endl;
	else{
		node *remove_node = front;
		int value = remove_node->data;
		front = remove_node->next;
		
		delete remove_node;
		
		if(front == NULL)
			delete back;
		
		return value;
	}

	return NULL;
}

void queue::display(){
	
	
	if(front == NULL && back == NULL)
		cout << "Empty queue" << endl;
	else{
	
		cout << endl << "Queue: ";
		
		node *current = front;
		
		while(current!=NULL){
			
			cout << current->data << "\t";
			
			current= current->next;
			
		}
	}
}
	
int main(){
	
	cout << "This program implements a queue using LL\n";
	
	queue myqueue;
	
	myqueue.add(10);
	myqueue.add(0);
	myqueue.add(4);
	
	myqueue.display();
	
	myqueue.remove();
	
	myqueue.display();
	
	return 0;
	
	
}
