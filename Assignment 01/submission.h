/*
    Name:Abubaker
    Roll Number:i211379
    Assignment:01
*/
#pragma once
#include<iostream>
using namespace std;


//-------------------Question No 1-----------------
void createPolybiusSquare(char**& array) {
    char temp = 65;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            array[i][j] = temp++;
        }
        if (i == 1)
            temp++;
    }
}

void initializeWithNull(char*& res) {
    for (int i = 0; i < 100; i++) {
        res[i] = '\0';
    }
}

void settingInput(char*& input) {
    for (int i = 0; input[i] != '\0'; i++) {
        input[i] -= 32;
        if (input[i] == 'K')
            input[i] = 'C';
    }
}


char* convertToTapCode(char* str) {

    settingInput(str);

    char* resultant = new char[100];
    initializeWithNull(resultant);

    char** polybiusSquare = new char* [5];
    for (int i = 0; i < 5; i++) {
        polybiusSquare[i] = new char[5];
    }

    createPolybiusSquare(polybiusSquare);

    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        int t1 = 0;
        int t2 = 0;
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (str[i] == polybiusSquare[j][k]) {
                    t1 = j + 1;
                    t2 = k + 1;
                }
            }
        }
        for (int z = 0; z < t1; z++) {
            resultant[z + counter] = '.';
        }
        counter = counter + t1;
        resultant[counter++] = 32;
        for (int z = 0; z < t2; z++) {
            resultant[z + counter] = '.';
        }
        counter = counter + t2;
        if (str[i + 1] != '\0') {
            resultant[counter++] = 32;
            resultant[counter++] = 32;
        }
    }

    for (int i = 0; i < 5; i++) {
        delete[] polybiusSquare[i];
    }
    delete[] polybiusSquare;

    return resultant;
}

char* convertToString(char* str) {

    char* resultant = new char[100];
    initializeWithNull(resultant);

    char** polybiusSquare = new char* [5];
    for (int i = 0; i < 5; i++) {
        polybiusSquare[i] = new char[5];
    }

    createPolybiusSquare(polybiusSquare);

    int resCounter = 0;
    int counter = 0;
    int t1 = 0;
    int t2 = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == 32 && str[i + 1] == 32) || str[i + 1] == '\0') {
            if (str[i + 1] != '\0')
                i++;
            if (str[i + 1] == '\0')
                counter++;

            t2 = counter;
            counter = 0;

            resultant[resCounter++] = polybiusSquare[t1 - 1][t2 - 1] + 32;
        }
        else if (str[i] == 32) {
            t1 = counter;
            counter = 0;
        }
        else if (str[i] == '.') {
            counter++;
        }
    }

    for (int i = 0; i < 5; i++) {
        delete[] polybiusSquare[i];
    }
    delete[] polybiusSquare;

    return resultant;

}

//------------QUESTION:02---PART-A---------

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

int getLength_B(char* arr){
    int counter = 0;
    while(arr[counter] != '\0'){
        counter++;
    }
    return counter;
}

long long int convertToInt_B(char* arr){
    int len =  getLength_B(arr);
    long long res = 0;
    long long int num = 1;
    for(int i = len - 1; i >= 0; i--){
        res += (arr[i] - 48) * num;
        num *= 10;
    }
    return res;
}

int getLengthOfResult_B(long long int num){
    long long int quotient = 1;
    int len = 0;
    do{
        quotient = num / 10;
        num = quotient;
        len++;
    }while(quotient != 0);
    
    return len;
}

void convertToChar_B(long long int num, char*& arr, int len){
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


char* subtractionOfBigInteger(char * Num1, char* Num2){
    long long int n1 = convertToInt_B(Num1);
    long long int n2 = convertToInt_B(Num2);
    long long res = n1 - n2;
    
    int size = getLengthOfResult_B(res);
    
    if(n2 > n1){
        size += 1;
        res *= -1;
    }

    char* resultant = new char[size];
    
    convertToChar_B(res, resultant, size);
    
    if(n2 > n1){
        resultant[0] = '-';
    }
    
    return resultant;
}

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

//-------------------Question No 3--- PART A --------------


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

//-------------------Question No 3--- PART B--------------

//function to get the length of the string
int getLength_1(char*& str) {
    int counter = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        counter++;
    }
    return counter;
}

//function to check the uniqueness of the characters
bool checkForUniqueness(char*& arr, char& currChar) {
    int size = getLength_1(arr);
    //looping through the array and checks if the character matches or not
    for (int i = 0; i < size; i++) {
        //if character matches it means it is not unique
        if (currChar == arr[i])
            return false;
    }
    return true;
}

void getTotalUniqueCharacters(char* str, char*& arr, int& size) {

    //get the length of the given string
    int length = getLength_1(str);
    int counter = 0;
    for (int i = 0; i < length; i++) {
        //if the character is unique
        if (checkForUniqueness(arr, str[i])) {
            //store the character in the array
            arr[counter++] = str[i];
        }
    }
    size = counter;
}

int getFrequency(char* str, char& currChar) {
    int counter = 0;
    for (int i = 0; i < getLength_1(str); i++) {
        if (currChar == str[i])
            counter++;
    }
    return counter;
}

void getTheFrequencies(char* str, int*& array, char*& arr, int& size) {
    for (int i = 0; i < size; i++) {
        array[i] = getFrequency(str, arr[i]);
    }
}

void countLetters(char* str, int*& array, int& size) {

    //get the length of the given string
    int length = getLength_1(str);

    //declaring the space for array
    array = new int[length];

    //decalring the characters array for storing unique characters
    char* arr = new char[length];

    //function call to get all the unique characters
    getTotalUniqueCharacters(str, arr, size);

    //function call to get all the frequencies of all the unique characters
    getTheFrequencies(str, array, arr, size);

    //releasing the temporary memory
    delete[] arr;

}
//-------------------Question No 4--- PART A--------------

bool isprimeNumber(int n, int i) {
    if (n == 0 || n == 1)
        return false;			// 0 & 1 are not prime numbers


    else if (i == n)
        return true;		 	// 2 is prime number so returning true 

    else if (n % i == 0)
        return false; 			// number divided my other than 0,1 & its self is not a prime number so returning false 

    return isprimeNumber(n, i + 1);
}
//-------------------Question No 4--- PART B--------------

char findUppercase(char* str) {

    if (str[0] != '\0') {
        if (*(str) >= 'A') {
            if (*(str) <= 'Z') {
                return *(str);		// if letter is greater than A and smaller than Z return that letter from A to Z
            }
        }
    }
    return findUppercase((str + 1));
}

//-------------------Question No 4--- PART C--------------

void sumRow(int** array, int row, int column, int& evenSum, int& oddSum) {
    if (column - 1 >= 0) {
        if (array[row - 1][column - 1] % 2 == 0)
            evenSum += array[row - 1][column - 1];
        else
            oddSum += array[row - 1][column - 1];
        sumRow(array, row, --column, evenSum, oddSum);
    }
}


int sum(int** array, int row, int column, int& evenSum, int& oddSum) {
    if (row - 1 >= 0) {
        sumRow(array, row, column, evenSum, oddSum);
        sum(array, --row, column, evenSum, oddSum);
    }
    return 0;
}

//-------------------Question No 4--- PART D--------------


void function11(int i) {

    if (i == 0) {
        return;
    }
    cout << " ";

    function11(i - 1);

}

void functionMidLine(int temp) {

    if (temp == 0)
        return;
    cout << " ";

    functionMidLine(temp - 1);

}

void function1(int i, int j) {

    if (i == j / 2) {
        return;
    }
    function11(i);
    cout << "-";
    cout << endl;
    function1(++i, j);

}
void function21(int temp) {

    if (temp == 1)
        return;
    cout << " ";

    function21(--temp);
}

void function2(int i, int temp) {
    if (i == temp) {
        return;
    }
    function21(temp);
    cout << "-";
    cout << endl;
    function2(i, --temp);

}


void PrintPattern1(int i, int j) {


    function1(i, j);
    int temp = (j / 2);
    functionMidLine(temp);
    cout << "-";
    cout << endl;
    function2(i, temp);

}


//-------------------Question No 4--- PART E--------------




void fun1_51(int k, int i) {
    if (k == i)
        return;
    cout << " ";
    fun1_51(++k, i);
}

void fun1_52(int j, int temp) {
    if (j == temp)
        return;

    cout << "*";
    fun1_52(++j, temp);
}


void fun1_5(int i, int counter) {
    if (i == 0)
        return;
    fun1_51(1, i);
    int temp = 2 * counter + 1;
    fun1_52(0, temp);
    cout << endl;
    fun1_5(--i, ++counter);
}

void fun2_5(int i, int c, int counter) {
    if (i == c)
        return;
    fun1_51(1, i + 1);
    int temp = 2 * counter + 1;
    fun1_52(0, temp);
    cout << endl;
    fun2_5(++i, c, --counter);
}

void PrintPattern2(int a, int b, int c) {
    int counter = 0;
    fun1_5(a, counter);
    counter = c - 2;
    fun2_5(1, c, counter);
}


//-------------------Question No 4--- PART F --------------




void function1_611(int k) {	//Upper Left Triangle Column Loop

    if (k == 0)
        return;

    cout << " ";

    function1_611(k - 1);


}

void function1_612(int k) {	//Upper Mid Triangle Column Loop

    if (k == 0)
        return;

    cout << " ";

    function1_612(k - 1);


}

void function1_613(int k, int o) {		// Right Triangle
    if (o == 0)
        return;
    cout << "*";

    function1_613(k, o - 1);

}

void function1_61(int temp, int counter) {  // Upper Row Loop 

    if (temp == 0) {
        return;
    }
    function1_611(temp);					// LEft S1de Of Upper S1de
    cout << "|";
    function1_612(temp);

    int o = 2 * counter;

    function1_613(temp, o);
    cout << "|";


    function1_613(temp, o);		//Right Side Of Upper S1de
    function1_612(temp);
    cout << "|";

    cout << endl;

    counter++;
    function1_61(temp - 1, counter);



}

void function1_6(int temp, int j) {			// Upper LEft & Right S1de Pattern

    int counter = 0;
    function1_61(temp, counter);

}

void function2_61(int j) {			//Mid Line Stars

    if (j == 0)
        return;
    cout << "*";

    function2_61(j - 1);
}

void function2_6(int j) {				//Mid Line


    cout << "|";
    function2_61(j);
    cout << "|";
    function2_61(j);
    cout << "|";

}

void function3_61(int temp, int counter, int tempCounter, int l, int h) {

    if (temp == 0)
        return;

    function1_611(tempCounter);
    cout << "|";
    function1_612(++l);

    int o = 2 * counter;
    function1_613(temp, o);
    cout << "|";
    function1_613(temp, o);
    function1_612(++h);
    cout << "|";
    cout << endl;
    counter--;
    function3_61(--temp, counter, ++tempCounter, l, h);

}

void function3_6(int temp, int j, int k) {			// Lower LEft & Right S1de Pattern
    int l = 0;
    int h = 0;
    int counter = temp - 1;
    int tempCounter = 1;
    function3_61(temp, counter, tempCounter, l, h);

}



void PrintPattern3(int i, int j, int k) {

    int temp = i - 1;
    function1_6(temp, j);		//Upper S1de

    j = (k + i) - 2;
    function2_6(j);      //Mid Line 
    cout << endl;
    function3_6(temp, j, k);			//Lower S1de

}




