#include<iostream>
#include<string.h>

using namespace std;

int main(){
	
	string str = "hi mohith!";
	
	int size = str.length();
	
	string strtemp;
	for(int i=0; i<size; i++){
		
		if(str[i]>'a' && str[i]<'z')
			strtemp = str[i]-('a'-'A');
		else
			strtemp = str[i];
		cout << strtemp;
		
	}
	
	return 0;
}
