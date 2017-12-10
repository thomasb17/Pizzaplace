#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Topping
{
public:
	static const string filename;
private:
	string name;
	int price;

public:
	// Constructors
	Topping();
	Topping(string name, int price);

	// Get functions
	string getName() const;
	int getPrice() const;

	// Set functions
	void setName(const string& name);
	void setPrice(const int& price);

	// Operator overloads
	friend istream& operator >> (istream& in, Topping& topping);
	friend ostream& operator << (ostream& out, const Topping& topping);
	friend bool operator == (const Topping& left, const Topping& right);
};
