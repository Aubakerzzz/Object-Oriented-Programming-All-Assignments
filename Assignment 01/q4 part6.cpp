#include<iostream>
using namespace std;

void function1_611(int k){	//Upper Left Triangle Column Loop
			
	if(k==0)
		return;
	
	cout << " ";
	
	function1_611(k-1);
	
	
}

void function1_612(int k){	//Upper Mid Triangle Column Loop
			
	if(k==0)
		return;
	
	cout << " ";
	
	function1_612(k-1);
	
	
}

void function1_613(int k, int o){		// Right Triangle
	if(o==0)
		return;
	cout <<"*";
	
	function1_613(k,o-1);
	
}

void function1_61(int temp, int counter){  // Upper Row Loop 
	
	if(temp==0){
		return;		
	}	
	function1_611(temp);					// LEft S1de Of Upper S1de
	cout << "|";
	function1_612(temp);
	
	int o = 2*counter;

	function1_613(temp,o);	
	cout <<"|";
	
	
	function1_613(temp,o);		//Right Side Of Upper S1de
	function1_612(temp);
	cout << "|";
	
	cout << endl;
	
	counter++;
	function1_61(temp-1,counter);


	
}

void function1_6(int temp, int j){			// Upper LEft & Right S1de Pattern
	
	int counter=0;
	function1_61(temp,counter);

}

void function2_61(int j){			//Mid Line Stars
	
	if(j==0)
		return;
	cout << "*";
	
	function2_61(j-1);		
}

void function2_6(int j){				//Mid Line
	

	cout << "|";	
	function2_61(j);
	cout << "|";
	function2_61(j);
	cout << "|";
	
}

void function3_61(int temp , int counter, int tempCounter, int l, int h){
		
	if(temp == 0)
		return;
	
	function1_611(tempCounter);
	cout << "|";
	function1_612(++l);
	
	int o = 2*counter;
	function1_613(temp,o);	
	cout <<"|";
	function1_613(temp,o);
	function1_612(++h);
	cout <<"|";
	cout << endl;
	counter--;
	function3_61(--temp, counter, ++tempCounter,l,h);
	
}

void function3_6(int temp, int j, int k){			// Lower LEft & Right S1de Pattern
	int l=0;
	int h=0;
	int counter=temp-1;
	int tempCounter = 1;
	function3_61(temp,counter, tempCounter,l,h);

}


	
void PrintPattern3(int i , int j , int k){
	
	int temp = i-1;
	function1_6(temp,j);		//Upper S1de
 
 	j = (k+i)-2;					
 	function2_6(j);      //Mid Line 
 	cout << endl;
   function3_6(temp,j,k);			//Lower S1de
	
}

int main(){
	
	PrintPattern3(5,1,5);
}



