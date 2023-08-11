#include<iostream>
using namespace std;

char findUppercase(char *str){
	
	if(str[0] != '\0'){
		if(*(str) >= 'A' ){			
			if(*(str) <= 'Z'){
				return *(str);		// if letter is greater than A and smaller than Z return that letter from A to Z
			}
		}
	}
	return findUppercase((str+1));	
}

int main(){
	
	const int LENGTH =100;
	char str[LENGTH] = {'\0'};
	cout << "Enter The string"<< endl;
	cin.getline(str, LENGTH);		
	cout << findUppercase(str);
	
}
	
	
/*
char findUppercase(char *str){
	
	for(int i=0 ; *str!='\0' ; i++){
		if(*(str+i)>='A'){
			if(*(str+i)<='Z'){
				return *(str+i);	
			}
		}
	}

}
*/
