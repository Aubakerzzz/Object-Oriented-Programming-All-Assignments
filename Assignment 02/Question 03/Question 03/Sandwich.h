#pragma once
class Sandwich {
private:
	char* name;
	char* filling;
	char* size;
	bool is_ready;
	double price;
public:

	Sandwich();
	Sandwich(char* fillingVal, double priceVal);
	Sandwich(char* fillingVal, double priceVal, char* nameVal, char* sizeVal, bool	ready_status);
	Sandwich(const Sandwich& sandwich);
	void setFilling(char* fillingVal);
	void setPrice(double priceVal);
	void setName(char* nameVal);
	void setSize(char* sizeVal);
	bool isSmall(char* str);	// function for checking size if it is small 
	bool isMedium(char* str);	// function for checking size if it is medium
	bool isLarge(char* str);	// function for checking size if it is large
	char* getFilling();
	double getPrice();
	char* getName();
	char* getSize();
	void makeSandwich();
	bool check_status();


};



