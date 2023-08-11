/*
Name: Abubaker
Roll# :21I-1379
Sec-H
*/

#include "pch.h"
#include "Rational.h"

int get_max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

Rational::Rational() {
	this->numerator = 0;
	this->denominator = 1;
}

Rational::Rational(int n, int d) {
	this->numerator = n;
	this->denominator = d;
	//now simply the fraction
	int n1 = get_max(this->numerator, this->denominator);
	bool check = true;
	while (check) {
		check = false;
		for (int i = 2; i <= n1; i++) {
			if (this->numerator % i == 0 && this->denominator % i == 0) {
				check = true;
				this->numerator /= i;
				this->denominator /= i;
			}
		}
		n1 = get_max(this->numerator, this->denominator);
	}
}

Rational::Rational(const Rational& copy) {
	this->numerator = copy.numerator;
	this->denominator = copy.denominator;
}

Rational Rational::operator = (const Rational& x)  {

	this->numerator = x.numerator;
	this->denominator = x.denominator;
	return *this;
}

Rational Rational::operator + (const Rational& x) const {

	Rational temp;
	// if the denominators are same simply add the numerators
	if (x.denominator == this->denominator) {
		temp.denominator = this->denominator;
		temp.numerator = this->numerator + x.numerator;
	}
	//if the denominators are different
	//multiply the denominators to get the resultant denominator
	//to get the numerator add multiply the first numerator by the second denominator and add
	//it with the resultant of the multiplication of first denominator by the second numerator
	else {
		temp.denominator = this->denominator * x.denominator;
		temp.numerator = (this->numerator * x.denominator) + (x.numerator * this->denominator);
	}
	//now simply the fraction
	int n = get_max(temp.numerator, temp.denominator);
	bool check = true;
	while (check) {
		check = false;
		for (int i = 2; i <= n; i++) {
			if (temp.numerator % i == 0 && temp.denominator % i == 0) {
				check = true;
				temp.numerator /= i;
				temp.denominator /= i;
			}
		}
		n = get_max(temp.numerator, temp.denominator);
	}
	return temp;
}

Rational Rational::operator - (const Rational& x) const {
	Rational temp;
	// if the denominators are same simply add the numerators
	if (x.denominator == this->denominator) {
		temp.denominator = this->denominator;
		temp.numerator = this->numerator - x.numerator;
	}
	//if the denominators are different
	//multiply the denominators to get the resultant denominator
	//to get the numerator add multiply the first numerator by the second denominator and add
	//it with the resultant of the multiplication of first denominator by the second numerator
	else {
		temp.denominator = this->denominator * x.denominator;
		temp.numerator = (this->numerator * x.denominator) - (x.numerator * this->denominator);
	}
	//now simply the fraction
	int n = get_max(temp.numerator, temp.denominator);
	bool check = true;
	while (check) {
		check = false;
		for (int i = 2; i <= n; i++) {
			if (temp.numerator % i == 0 && temp.denominator % i == 0) {
				check = true;
				temp.numerator /= i;
				temp.denominator /= i;
			}
		}
		n = get_max(temp.numerator, temp.denominator);
	}
	return temp;
}

Rational Rational::operator * (const Rational& x) const {
	Rational temp;	
	temp.denominator = this->denominator * x.denominator;
	temp.numerator	 = this->numerator * x.numerator;

	//now simply the fraction
	int n = get_max(temp.numerator, temp.denominator);
	bool check = true;
	while (check) {
		check = false;
		for (int i = 2; i <= n; i++) {
			if (temp.numerator % i == 0 && temp.denominator % i == 0) {
				check = true;
				temp.numerator /= i;
				temp.denominator /= i;
			}
		}
		n = get_max(temp.numerator, temp.denominator);
	}
	return temp;
}

Rational Rational::operator / (const Rational& x) const {

	Rational temp;
	temp.numerator = this->numerator * x.denominator;
	temp.denominator = this->denominator * x.numerator;

	//now simply the fraction
	int n = get_max(temp.numerator, temp.denominator);
	bool check = true;
	while (check) {
		check = false;
		for (int i = 2; i <= n; i++) {
			if (temp.numerator % i == 0 && temp.denominator % i == 0) {
				check = true;
				temp.numerator /= i;
				temp.denominator /= i;
			}
		}
		n = get_max(temp.numerator, temp.denominator);
	}
	return temp;
}

Rational Rational::operator += (const Rational & x) {

	// if the denominators are same simply add the numerators
	if (x.denominator == this->denominator) {
		this->denominator = this->denominator;
		this->numerator = this->numerator + x.numerator;
	}
	//if the denominators are different
	//multiply the denominators to get the resultant denominator
	//to get the numerator add multiply the first numerator by the second denominator and add
	//it with the resultant of the multiplication of first denominator by the second numerator
	else {
		this->denominator = this->denominator * x.denominator;
		this->numerator = (this->numerator * x.denominator) + (x.numerator * this->denominator);
	}
	//now simply the fraction
	int n = get_max(this->numerator, this->denominator);
	bool check = true;
	while (check) {
		check = false;
		for (int i = 2; i <= n; i++) {
			if (this->numerator % i == 0 && this->denominator % i == 0) {
				check = true;
				this->numerator /= i;
				this->denominator /= i;
			}
		}
		n = get_max(this->numerator, this->denominator);
	}
	return *this;
}

Rational Rational::operator -= (const Rational& x) {
	// if the denominators are same simply add the numerators
	if (x.denominator == this->denominator) {
		this->denominator = this->denominator;
		this->numerator = this->numerator - x.numerator;
	}
	//if the denominators are different
	//multiply the denominators to get the resultant denominator
	//to get the numerator add multiply the first numerator by the second denominator and add
	//it with the resultant of the multiplication of first denominator by the second numerator
	else {
		this->denominator = this->denominator * x.denominator;
		this->numerator = (this->numerator * x.denominator) - (x.numerator * this->denominator);
	}
	//now simply the fraction
	int n = get_max(this->numerator, this->denominator);
	bool check = true;
	while (check) {
		check = false;
		for (int i = 2; i <= n; i++) {
			if (this->numerator % i == 0 && this->denominator % i == 0) {
				check = true;
				this->numerator /= i;
				this->denominator /= i;
			}
		}
		n = get_max(this->numerator, this->denominator);
	}
	return *this;
}

Rational Rational::operator *= (const Rational& x) {
	
	this->denominator = this->denominator * x.denominator;
	this->numerator = this->numerator * x.numerator;

	//now simply the fraction
	int n = get_max(this->numerator, this->denominator);
	bool check = true;
	while (check) {
		check = false;
		for (int i = 2; i <= n; i++) {
			if (this->numerator % i == 0 && this->denominator % i == 0) {
				check = true;
				this->numerator /= i;
				this->denominator /= i;
			}
		}
		n = get_max(this->numerator, this->denominator);
	}
	return *this;
}

Rational Rational::operator /= (const Rational& x) {
	this->numerator = this->numerator * x.denominator;
	this->denominator = this->denominator * x.numerator;

	//now simply the fraction
	int n = get_max(this->numerator, this->denominator);
	bool check = true;
	while (check) {
		check = false;
		for (int i = 2; i <= n; i++) {
			if (this->numerator % i == 0 && this->denominator % i == 0) {
				check = true;
				this->numerator /= i;
				this->denominator /= i;
			}
		}
		n = get_max(this->numerator, this->denominator);
	}
	return *this;
}

bool Rational::operator == (const Rational& other) const {

	if (this->denominator == other.denominator)
		if(this->numerator==other.numerator)
			return true;
	return false;

}

bool Rational::operator < (const Rational& other) const {
	Rational temp = *this - other;
	if (temp.numerator < 0) {
		return true;
	}
	return false;
}
bool Rational::operator > (const Rational& other) const {
	Rational temp = *this - other;
	if (temp.numerator > 0) {
		return true;
	}
	return false;
}
bool Rational::operator <=(const Rational& other) const {
	Rational temp = *this - other;
	if (temp.numerator <= 0) {
		return true;
	}
	return false;
}
bool Rational::operator >=(const Rational& other) const {
	Rational temp = *this - other;
	if (temp.numerator >= 0) {
		return true;
	}
	return false;
}

Rational::operator string() const {
	string return_val = "";
	if (this->denominator == 1) {
		return_val = to_string(this->numerator);
	}
	else {
		return_val += to_string(this->numerator);
		return_val += "/";
		return_val += to_string(this->denominator);
	}
	return return_val;
}

ostream& operator<<(ostream& output, const Rational& b) {
	
	output << (string)b << endl;
	return output;
}

istream& operator>>(istream& input, Rational& c) {

	cout << "Enter Input" << endl;
	cout << "Enter numerator: ";
	input >> c.numerator;
	cout << "Enter Denominator: ";
	input>>c.denominator;
	//now simply the fraction
	int n = get_max(c.numerator, c.denominator);
	bool check = true;
	while (check) {
		check = false;
		for (int i = 2; i <= n; i++) {
			if (c.numerator % i == 0 && c.denominator % i == 0) {
				check = true;
				c.numerator /= i;
				c.denominator /= i;
			}
		}
		n = get_max(c.numerator, c.denominator);
	}
	return input;
}
Rational::~Rational() {

	numerator = 0;
	denominator = 0;
}
