/*
 * Program: Heap implementation using array
 * 
 * Author: Jwala Mohith Girisha
 * 
 */


#include<iostream>

using namespace std;

class HeapMin{
	
	private:
		int* data;
		int heapcount;
		int arraycount;
		
		int getparentindex(int index){
			return (index-1)/2;
		}
		
		int getleftindex(int index){
			return 2*index + 1;
		}
		
		int getrightindex(int index){
			return 2*index + 2;
		}
		
		void shiftup(int index){
			
			int parentindex, tmp;
			
			if(index !=0){
				
				parentindex = getparentindex(index);
				
				if(data[parentindex] > data[index]){
					
					tmp = data[parentindex];
					data[parentindex] = data[index];
					data[index] = tmp;
					shiftup(parentindex);
					
				}
			}
		}
		
		
		void shiftdown(int index){
			
			int minindex, tmp;
			
			if(getrightindex(index) >= heapcount){
				if(getleftindex(index) >= heapcount)
					return;
				else
					minindex = getleftindex(index);
			}
			else{
				if(getleftindex(index) >= heapcount)
					minindex = getrightindex(index);
				else{
					if(data[getleftindex(index)] <= data[getrightindex(index)])
						minindex = getleftindex(index);
					else
						minindex = getrightindex(index);
				}
				
				if(data[minindex] < data[index]){
					
					tmp = data[index];
					data[index] = data[minindex];
					data[minindex] = tmp;
					shiftdown(minindex);
					
				}
			}
		}				
			
			
		
	public:
		HeapMin(int size){
			data = new int[size];
			heapcount = 0;
			arraycount = size;
		}
		
		int getminimum(){
			if(heapcount == 0)
				cout << "Heap empty" << endl;
			else
				return data[0];
			
			return -999;
		}
		
		bool isempty(){
			if(heapcount == 0)
				return true;
			else
				return false;
		}
		
		~HeapMin(){
			delete[] data;
		}
		
		
		
		
		void add(int value){
			
			if(heapcount == arraycount)
				throw string("Heap full. Beyond bounds.\n");
			
			heapcount++;
			data[heapcount-1] = value;
			shiftup(heapcount-1);
		}
		
		void removemin(){
			
			if(heapcount==0)
				throw string("Heap empty\n");
				
			cout << "Min data being removed: " << data[0] << endl;;

			data[0] = data[heapcount-1];
			heapcount--;
			shiftdown(0);
		}
			
		
};

int main(){
	
	cout << "This program implements min heap\n";
	
	HeapMin myheap(10);
	
	myheap.add(1);
	myheap.add(3);
	myheap.add(6);
	myheap.add(5);
	myheap.add(9);
	myheap.add(8);
	
	myheap.removemin();
	
	cout << endl << "Min: " << myheap.getminimum();
	
	myheap.add(2);
	
	cout << endl << "Min: " << myheap.getminimum();

		
	return 0;
}
	
