#pragma once
class String {
private:
	char* data;
	int length;
public:
	String();
	String(int size);
	String(char* str);
	String(const String& str);
	~String();
	int strLength();
	void clear();
	bool empty();
	int charAt(char c);
	char* getdata();
	bool equals(char* str);
	bool equalsIgnoreCase(char* str);
	char* substring(char* substr, int startIndex);
	char* substring(char* substr, int startIndex, int endIndex);
	void print()const;


};



