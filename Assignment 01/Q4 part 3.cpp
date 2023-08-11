#include<iostream>
using namespace std;


void sumRow(int ** array, int row, int column, int& evenSum, int& oddSum){
	if(column - 1 >= 0){
		if(array[row - 1][column - 1] % 2 == 0)
			evenSum += array[row - 1][column - 1];
		else
			oddSum += array[row - 1][column - 1];
		sumRow(array, row, --column, evenSum, oddSum);
	}
}


int sum(int **array, int row, int column, int &evenSum, int &oddSum){
	if(row - 1 >= 0){
		sumRow(array, row, column, evenSum, oddSum);
		sum(array, --row, column, evenSum, oddSum);
	}			
}

int main(){
	
	int **arr=new int*[3];
	for(int i=0;i<3;i++){
		arr[i] = new int[2];
	}
	arr[0][0]=20;
	arr[0][1]=5;

	arr[1][0]=10;
	arr[1][1]=2;

	arr[2][0]=7;
	arr[2][1]=9;

	int evenSum=0;
	int oddSum=0;

	sum(arr,3,2,evenSum,oddSum);
	
	cout << evenSum << endl;
	cout << oddSum << endl;
	
	return 0;
}

