/*Abubaker
* 21I-1379
    Assignment# 03
*/

#ifndef BinaryStore_H_
#define BinaryStore_H_
#include <iostream>
using namespace std;

class Byte {
public:
    char* value;
    Byte();
    Byte(const char*);
    Byte(const Byte&);
   // Byte& operator()(const char*);
    char* getByte();

    Byte operator+(Byte&);
    Byte operator-(Byte&);

    bool operator==(Byte&);
    Byte operator&&(Byte&);
    Byte operator||(Byte&);

    ~Byte();
};
class BinaryStore {
    int size;
    char** address;
    Byte b[20];
    int count;
public:

    BinaryStore(int = 0);
    BinaryStore(BinaryStore&);

    void operator+=(const char*);

    void Add(const char*,Byte&);
    Byte& Get(const char*);
    void setSize(int i);

    char* get(int i);
    friend ostream& operator<<(ostream& output, const BinaryStore&);
    ~BinaryStore(); // destructor...
};

ostream& operator<<(ostream& output, const BinaryStore&);

#endif /* BinaryStore_H_ */
