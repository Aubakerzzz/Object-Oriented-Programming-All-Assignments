#include<iostream>
using namespace std;

void function11(int i){
	
	if(i==0){
		return;
	}
	cout << " ";
	
	function11(i-1);
	
}
	
void functionMidLine(int temp){
	
	if(temp==0)
		return;
	cout <<" ";
	
	functionMidLine(temp-1);
	
}

void function1(int i, int j){
	
	if(i==j/2){
		return;
	}
	function11(i);
	cout << "-";
	cout << endl;
	function1(++i,j);

}
void function21(int temp){
	
	if(temp==1)
		return;
	cout <<" ";
	
	function21(--temp);
}

void function2(int i,int temp){
	if(i==temp){
		return;
	}
	function21(temp);
	cout << "-";
	cout << endl;
	function2(i,--temp);
	
}


void PrintPattern1(int i , int j){
	
	
	function1(i,j);
	int temp = (j/2);	
	functionMidLine(temp);
	cout << "-";
	cout << endl;
	function2(i,temp);	
		
}

int main(){
	
	PrintPattern1(1,14);	
	
}
