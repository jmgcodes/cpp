/*
 * Program: Queue implementation
 * 
 * Author: Jwala Mohith Girisha
 * 
 */

#include<iostream>

#define MAX 10

using namespace std;

class queue{
	
	private:
		int qarray[MAX];
		int front;
		int back;
		
	public:
		queue(){
			front = -1;
			back = -1;
		};
		
		void add(int value);
		int remove();
		void display();
		
};

void queue::add(int value){
	
	if(front == -1 && back == -1){
		
		front++;
		back++;

		qarray[front] = value;
		
	}
	else{
		
		if(front<MAX){
			
			front ++;
			qarray[front] = value;
			
		}
		else{
			
			cout << "Queue full" << endl;
			
		}
	}	
	
}


int queue::remove(){
	
	if(front == -1 && back == -1){
		
		cout << "Queue empty" << endl;
		return NULL;
	}
	else{
	
		int value = qarray[0];
		
		int i=1;
		while(i<=front){
			int temp = qarray[i];
			qarray[i-1] = temp;
			i++;
		}
		qarray[front] = NULL;
		front--;
		
		if(front == -1)
			back = -1;
		else
			back = 0;
		
		return value;
	}
	return NULL;
}

void queue::display(){
	
	if(front == -1 && back == -1){
		
		cout << "Queue empty" << endl;
		
	}
	else{
		
		cout << "Queue:\t";
		
		for(int i=0; i<=front; i++){
			
			cout << qarray[i] << "\t";
			
		}
	}
	
	cout << endl;
}


int main(){
	
	cout << "This program implements queue" << endl << endl;
	
	queue myqueue;
	
	myqueue.add(2);
	myqueue.add(3);
	myqueue.add(4);
	myqueue.add(5);
	
	myqueue.display();
	
	cout << "\nRemoved: " << myqueue.remove() << endl;
	
	myqueue.display();
	
	myqueue.add(9);
	myqueue.add(0);
	
	myqueue.display();

	cout << "\nRemoved: " << myqueue.remove() << endl;
	
	myqueue.display();
	
	

	return 0;
}
