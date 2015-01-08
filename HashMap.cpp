#include<iostream>

using namespace std;

#define MAX 10

class HashEntry{
	
	private:
		int key;
		int value;
		
	public:
		HashEntry(int key, int value);
		int getKey();
		int getValue();
		
};

HashEntry::HashEntry(int key, int value){
	
	this->key = key; this->value = value;
	
}

int HashEntry::getKey(){
	
	return key;
	
}

int HashEntry::getValue(){
	
	return value;
	
}


//Class - Hash Map

class HashMap{
	
	private:
		HashEntry **map;
	public:
		HashMap();
		~HashMap();
		int get(int key);
		void put(int key, int value);
		
};

HashMap::HashMap(){
	
	map = new HashEntry*[MAX];
	for(int i=0; i< MAX; i++){
		map[i] = NULL;
	}
	
}

int HashMap::get(int key){
	
	int hash = key % MAX;
	
	while(map[hash] != NULL && map[hash]->getKey() != key)
		hash = (hash+1) % MAX;
		
	if(map[hash] == NULL)
		return -1;
	else
		return map[hash]->getValue();
		
}

void HashMap::put(int key, int value){
	
	int hash = key % MAX;
	
	while(map[hash] != NULL && map[hash]->getKey() != key)
		hash = (hash+1) % MAX;
		
	if(map[hash] != NULL)
		delete map[hash];
	map[hash] = new HashEntry(key, value);
}

HashMap::~HashMap(){
	
	for(int i=0; i<MAX; i++){
		if(map[i]!=NULL)
			delete map[i];
	}
	
	delete[] map;
}

int main(){
	
	cout << "This program implements a Hash Map" << endl;
	
	HashMap mymap;
	
	mymap.put(5,11);
	mymap.put(6,13);
	mymap.put(15,33);
	mymap.put(7,19);
	
	cout << "Value with key:5 " << mymap.get(5) << endl; //Stores in mymap[5]
	cout << "Value with key:6 " << mymap.get(6) << endl; //Stores in mymap[6]
	cout << "Value with key:15 " << mymap.get(15) << endl; //Stores in mymap[7]
	cout << "Value with key:7 " << mymap.get(7) << endl; //Stores in mymap[8]

	return 0;
	
}
	
