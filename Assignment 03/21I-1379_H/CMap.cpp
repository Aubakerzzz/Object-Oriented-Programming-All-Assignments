/* Abubaker
	21I-1379
   Assignment# 03
*/

#include "CMap.h"
#include "String.h"

int DrExistCheck(Key& k, const char* str) {
	bool flag = 0;
	int i, j;
	for (i = 1; i <= k.ele && !flag;i++) {

		for (j = 0;k.array[i][j] != '\0';j++)
			if (k.array[i][j] == str[j])
				flag = 1;
			else
				flag = 0;
		if (flag)
			return i;
	}
	return -1;
}

//------------------------CMap Class---------------------------------------

CMap::CMap() {
	this->count = 30;
	c = 0;
}
CMap::CMap(const CMap& copy) {// copy constructor 
	this->c = copy.c;
	int a;
	for (int i = 0;i < c;i++) {
		k[i].ele = copy.k[i].ele;
		for (int n = 0;n <= k[i].ele;n++) {
			for (a = 0;copy.k[i].array[n][a] != '\0';a++)
				k[i].array[n][a] = copy.k[i].array[n][a];
			k[i].array[n][a] = '\0';
		}
	}
}
Key& CMap::operator[](const char* str) {
	int a;
	for (int i = 0;i <= c;i++)
		if (k[i].array[0][0] == str[0]) {
			if (k[i].array[0][1] == str[1])
				if (k[i].array[0][2] == str[2])
					return k[i];
		}


	for (a = 0;str[a] != '\0';a++)
		k[c].array[0][a] = str[a];
	k[c].array[0][a] = '\0';
	k[c].ele++;
	c++;
	return k[c - 1];

}

const CMap& CMap::operator=(const CMap& copy ) {
	this->c = copy.c;
	int a;
	for (int i = 0;i < c;i++) {
		k[i].ele = copy.k[i].ele;
		for (int n = 0;n <= k[i].ele;n++) {
			for (a = 0;copy.k[i].array[n][a] != '\0';a++)
				k[i].array[n][a] = copy.k[i].array[n][a];
			k[i].array[n][a] = '\0';
		}
	}
	//k[i].ele = copy.k[i].ele;
	
	return *this;
}

CMap CMap::operator+(const CMap& copy) {
	CMap temp;
	temp.c = this->c + copy.c;
	int b = this->c;
	int a;
	for (int i = 0;i < this->c;i++) {
		temp.k[i].ele = this->k[i].ele;
		for (int n = 0;n <= temp.k[i].ele;n++) {
			for (a = 0;this->k[i].array[n][a] != '\0';a++)
				temp.k[i].array[n][a] = this->k[i].array[n][a];
			temp.k[i].array[n][a] = '\0';
		}
	}
	for (int i = 0;i < copy.c;i++) {
		temp.k[i+b].ele = copy.k[i].ele;
		for (int n = 0;n <= temp.k[i+b].ele;n++) {
			for (a = 0;copy.k[i].array[n][a] != '\0';a++)
				temp.k[i+b].array[n][a] = copy.k[i].array[n][a];
			temp.k[i+b].array[n][a] = '\0';
		}
	}
	
	return temp;
}

string CMap::toString() {
	char fstr[1000]={};
	int i = 0;
	fstr[i++] = '[';
	fstr[i++] = ' ';
	for (int a = 0;a <= c; a++) {
		if (k[a].ele == 0)
			a++;
		else
		{
			for (int b = 0;k[a].array[0][b] != '\0';b++)
				fstr[i++] = k[a].array[0][b];
			fstr[i++] = ' ';
			fstr[i++] = ':';
			fstr[i++] = ' ';
			fstr[i++] = '{';
			fstr[i++] = ' ';
			for (int n = 1;n <= k[a].ele;n++) {
				if (k[a].array[n][0] != '\0') {
					
					if (n!=1 && k[a].array[n - 1][0] != '\0' ) {
						fstr[i++] = ',';
						fstr[i++] = ' ';
					}
					
					for (int b = 0;k[a].array[n][b] != '\0';b++)
						fstr[i++] = k[a].array[n][b];
					if ( n < k[a].ele)
						if(n+1!= k[a].ele)
							if (k[a].array[n + 1][0] == '\0') {
								fstr[i++] = ',';
								fstr[i++] = ' ';
							}
				}
			}
			fstr[i++] = ' ';
			fstr[i++] = '}';

		}
		if (a < c-1) {
			fstr[i++] = ',';
			fstr[i++] = ' ';
		}
	
		
	}
	fstr[i++] = ' ';
	fstr[i++] = ']';
	cout << i-1 << endl;
	return fstr;
}
CMap::~CMap() {

}

//------------------------Key Class---------------------------------------

Key::Key() {
	array = new char* [7];
	for (int i=0;i < 7;i++)
		array[i] = new char[30];
	ele = 0;
	key_flag = 0;
}

void Key::operator=(const char* str) {
	ele = 1;
	int i;
	for (i = 0;str[i] != '\0';i++)
		this->array[1][i] = str[i];
	this->array[1][i] = '\0';
	key_flag = 1;
	
}

void Key::operator+=(char*  str) {
	int check;
	if (key_flag) {
		check=DrExistCheck(*this, str);
		if (check == -1) {
			ele++;
			int i;
			for (i = 0;str[i] != '\0';i++)
				this->array[ele][i] = str[i];
			this->array[ele][i] = '\0';
			}
		
	}
	else {
		ele = 1;
		int i;
		for (i = 0;str[i] != '\0';i++)
			this->array[1][i] = str[i];
		this->array[1][i] = '\0';
		key_flag = 1;
	}
	
}
void Key::operator-=(const char* str) {
	int check;
	check = DrExistCheck(*this, str);
	if (check != -1) {
		this->array[check][0] = '\0';
	}
}

Key::~Key() {

}




