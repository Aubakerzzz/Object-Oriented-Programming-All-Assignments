#include <iostream>
using namespace std;

void createPolybiusSquare(char**& array){
    char temp = 65;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            array[i][j] = temp++; 
        }
        if(i == 1)
            temp++;
    }
}

void initializeWithNull(char*& res){
    for(int i = 0; i < 100; i++){
        res[i] = '\0';
    }
}

void settingInput(char*& input){
    for(int i = 0; input[i] != '\0'; i++){
        input[i] -= 32;
        if(input[i] == 'K')
            input[i] = 'C';
    }
}


char* convertToTapCode(char* input){
    
    settingInput(input);
    
    char* resultant = new char[100];
    initializeWithNull(resultant);
    
    char** polybiusSquare = new char*[5];
    for(int i = 0; i < 5; i++){
        polybiusSquare[i] = new char[5];
    }
    
    createPolybiusSquare(polybiusSquare);
    
    int counter = 0;
    
    for(int i = 0; input[i] != '\0'; i++){
        int t1 = 0;
        int t2 = 0;
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                if(input[i] == polybiusSquare[j][k]){
                    t1 = j + 1;
                    t2 = k + 1;
                }
            }
        }
        for(int z = 0; z < t1; z++){
            resultant[z + counter] = '.';
        }
        counter = counter + t1;
        resultant[counter++] = 32;
        for(int z = 0; z < t2; z++){
            resultant[z + counter] = '.';
        }
        counter = counter + t2;
        resultant[counter++] = 32;
        resultant[counter++] = 32;
    }
    
    for(int i = 0; i < 5; i++){
    	delete[] polybiusSquare[i];
	}
	delete[] polybiusSquare;
    
    return resultant;
}


char* convertToString(char* input){
	char* resultant = new char[100];
	initializeWithNull(resultant);
    
    char** polybiusSquare = new char*[5];
    for(int i = 0; i < 5; i++){
        polybiusSquare[i] = new char[5];
    }
    
    createPolybiusSquare(polybiusSquare);
    
    int resCounter = 0;
    int counter = 0;
    int t1 = 0;
    int t2 = 0;
    
    for(int i = 0; input[i] != '\0'; i++){
    	if((input[i] == 32 && input[i + 1] == 32) || input[i + 1] == '\0'){
    		if(input[i + 1] != '\0')
				i++;
			if(input[i + 1] == '\0')
				counter++;
				
			t2 = counter;
    		counter = 0;
    		
			resultant[resCounter++] = polybiusSquare[t1 - 1][t2 - 1] + 32;
		}
		else if(input[i] == 32){
			t1 = counter;
			counter = 0;
		}
		else if(input[i] == '.'){
			counter++;
		}
	}   
	
	for(int i = 0; i < 5; i++){
    	delete[] polybiusSquare[i];
	}
	delete[] polybiusSquare;
	    
    return resultant;
	
}

int main() {
    
//    char t1[] = "bottle";
//	char t1[]="coding";	
//    cout << convertToTapCode(t1) << endl;
	
//	char t2[] = ". ..  ... ....  .... ....  .... ....  ... .  . .....";
//	char t1[] = ". ...  .. ....  ... .....  .. ...  . .....  .... ..";
//	char t1[] = ". ....  . .....  . ...  ... ....  . ....  . .....";
//	cout << convertToString() << endl;
	
    return 0;
}


