#include <iostream>
using namespace std;

//function to get the length of the string
int getLength(char*& str){
    int counter = 0;
    for(int i = 0; str[i] != '\0'; i++){
        counter++;
    }
    return counter;
}

//function to check the uniqueness of the characters
bool checkForUniqueness(char*& arr, char& currChar){
  	int size = getLength(str);
    //looping through the array and checks if the character matches or not
    for(int i = 0; i < size; i++){
        //if character matches it means it is not unique
        if(currChar == arr[i])
            return false;
    }
    return true;
}

void getTotalUniqueCharacters(char* str, char*& arr, int& size){
    
    //get the length of the given string
    int length = getLength(str);
    int counter = 0;
    for(int i = 0; i < length; i++){
        //if the character is unique
        if(checkForUniqueness(arr, str[i])){
            //store the character in the array
            arr[counter++] = str[i];
        }
    }
    size = counter;
}

int getFrequency(char* str, char& currChar){
    int counter = 0;
    for(int i = 0; i < getLength(str); i++){
        if(currChar == str[i])
            counter++;
    }
    return counter;
}

void getTheFrequencies(char* str, int*& array, char*& arr, int& size){
    for(int i = 0; i < size; i++){
        array[i] = getFrequency(str, arr[i]);
    }
}

void countLetters(char* str, int*& array, int & size){
    
    //get the length of the given string
    int length = getLength(str);
    
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

int main() {
    // Write C++ code here
    char t1[] = "Find Frequency";
    int* arr;
    int size = 0;
    
    countLetters(t1, arr,size);
    
    cout << size << endl;
    cout << arr[2] << endl;
    
    return 0;
}
