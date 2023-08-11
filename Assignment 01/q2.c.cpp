int getLength_C(char* arr){
    int counter = 0;
    while(arr[counter] != '\0'){
        counter++;
    }
    return counter;
}

long long int convertToInt_C(char* arr){
    int len =  getLength_C(arr);
    long long res = 0;
    long long int num = 1;
    for(int i = len - 1; i >= 0; i--){
        res += (arr[i] - 48) * num;
        num *= 10;
    }
    return res;
}

int getLengthofResult_C(long long int num){
    long long int quotient = 1;
    int len = 0;
    do{
        quotient = num / 10;
        num = quotient;
        len++;
    }while(quotient != 0);
    
    return len;
}

void convertToChar_C(long long int num, char*& arr, int len){
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


char* multiplicationOfBigInteger(char * Num1, char* Num2){
    long long int n1 = convertToInt_C(Num1);
    long long int n2 = convertToInt_C(Num2);
    long long res = n1 * n2;
    
    int size = getLengthofResult_C(res);

    char* resultant = new char[size];
    
    convertToChar_C(res, resultant, size);
    
    return resultant;
}
