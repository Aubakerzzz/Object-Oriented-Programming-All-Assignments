#include <iostream>
#include <cstring>
using namespace std;

int getLength_A(char* arr){
    int counter = 0;
    while(arr[counter] != '\0'){
        counter++;
    }
    return counter;
}


long long int convertToInt_A(char* arr){
    int len =  getLength_A(arr);
    long long res = 0;
    long long int num = 1;
    for(int i = len - 1; i >= 0; i--){
        res += (arr[i] - 48) * num;
        num *= 10;
    }
    return res;
}

int getLengthOfResult_A(long long int num){
    long long int quotient = 1;
    int len = 0;
    do{
        quotient = num / 10;
        num = quotient;
        len++;
    }while(quotient != 0);
    
    return len;
}

void convertToChar_A(long long int num, char*& arr, int len){
    long long int quotient = 1;
    long long int remainder = 0;
    int index = len - 1; 
    do{
        quotient = num / 10;
        remainder = num % 10;
        arr[index--] = remainder + 48;
        num = quotient;
    }while(quotient != 0);
}


char* additionOfBigInteger(char * Num1, char* Num2){
    long long int n1 = convertToInt_A(Num1);
    long long int n2 = convertToInt_A(Num2);
    long long res = n1 + n2;
    
    int size = getLengthOfResult_A(res);

    char* resultant = new char[size];
    
    convertToChar_A(res, resultant, size);
    
    return resultant;
    
}

int main(){
	char t1[] = "1234567891011";
	char t2[] = "1110987654321";
	cout << strcmp("2345555545332", additionOfBigInteger(t1, t2)) << endl;
}

