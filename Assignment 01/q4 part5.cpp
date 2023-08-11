#include<iostream>
using namespace std;

void fun1_51(int k, int i){
	if(k == i)
		return;
	cout << " ";
	fun1_51(++k, i);
}

void fun1_52(int j, int temp){
	if(j == temp)
		return;
		
	cout << "*";
	fun1_52(++j, temp);
}


void fun1_5(int i, int counter){
	if(i == 0)
		return;
	fun1_51(1, i);
	int temp = 2 * counter + 1;
	fun1_52(0, temp);
	cout << endl;
	fun1_5(--i, ++counter);
}

void fun2_5(int i, int c, int counter){
	if(i == c)
		return;
	fun1_51(1, i+1);
	int temp = 2 * counter + 1;
	fun1_52(0, temp);
	cout << endl;
	fun2_5(++i, c, --counter);
}

void PrintPattern2(int a, int b, int c){
	int counter = 0;
	fun1_5(a, counter);
	counter = c - 2;
	fun2_5(1, c, counter);
}


int main(){

	PrintPattern2(5,1,5);	
}


