#include<iostream>
using namespace std;




void  removePunctuation(char* str) {
    char* output = new char[100];
    for (int i = 0; i < 100; i++) {
        output[i] = '\0';
    }
    int counter = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '.' && str[i] != '!' && str[i] != ',' && str[i] != ':' && str[i] != '#' && str[i] != '@' && str[i] != '?' && str[i] != '(' && str[i] != ')' && str[i] != '+' && str[i] != '-' && str[i] != '=' && str[i] != '&' && str[i] != '^' && str[i] != '"' && str[i] != ';' && str[i] != '/' && str[i] != '~' && str[i] != ':' && str[i] != '*') {
            output[counter++] = str[i];
        }
    }
    
    int temp = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        temp++;
        str[i] = '\0';
    }

    for (int i = 0; output[i] != '\0' && i <= temp; i++) {
        str[i] = output[i];
    }
}

int main(){

	char t1[] = "punctuation? needs& :to be (removed).";
	removePunctuation(t1);
}

