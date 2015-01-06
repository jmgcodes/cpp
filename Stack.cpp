/*
 * Program: Stack implementation
 * 
 * Author: Jwala Mohith Girisha
 * 
 */
 
 
#include<iostream>

using namespace std;

#define MAX 10

class stack{
	
	private:
		int sarray[MAX];
		int top;
		
	public:
		stack(){
			top = -1;
		};
		void push(int value);
		int pop();
		
};
		
void stack::push(int value){
	
	if(top<MAX){
		
		top++;
		sarray[top] = value;
		
		cout << "Pushed: " << value << endl;
	}
	else{
		
		cout << "Stack full" << endl;
		top--;
		
	}
}

int stack::pop(){
	
	if(top == -1){
		
		cout << "Stack empty" << endl;
		return NULL;
		
	}
	else{
		
		int value = sarray[top];
		sarray[top] = NULL;
		top--;
		return value;
	}
		
	return NULL;
	
}


int main(){
	
	cout << "This program implements a stack\n\n";
	
	stack mystack;
	
	mystack.push(3);
	mystack.push(9);
	mystack.push(4);
	
	cout << endl;
	
	cout << "Popped: " << mystack.pop() << endl;
	cout << "Popped: " << mystack.pop() << endl;
	cout << "Popped: " << mystack.pop() << endl;
	
	return 0;
	
}
