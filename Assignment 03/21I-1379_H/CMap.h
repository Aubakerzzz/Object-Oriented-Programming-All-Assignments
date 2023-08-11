/* Abubaker
* 21I1379
    Assignment# 03
*/

#ifndef CMap_H_
#define CMap_H_
#include <iostream>
using namespace std;


class Key {
public:
    char** array;
    int ele;
    bool key_flag;

    Key();

    void operator=(const char* str);
    void operator+=(char* str);
    void operator-=(const char* str);

    ~Key();
};

class CMap {
    Key k[30];
    int count;
    int c;
public:
   
    CMap(); 
    CMap(const CMap&); // copy constructor

    Key& operator[](const char* str);
    const CMap& operator=(const CMap&); 
    CMap operator+(const CMap&);
   
    string toString();
    ~CMap(); 
};

int DrExistCheck(Key&, const char*);

#endif /* CMap_H_ */
