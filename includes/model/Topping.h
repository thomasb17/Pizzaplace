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
	//change price to an int
	double price;

public:
	Topping();
	Topping(string name, double price);
	vector<Topping> getAllToppings();
	Topping self();
	void write(ofstream& fout) const;
	void read(ifstream& fin);
	double getPrice();
	friend istream& operator >> (istream& in, Topping& topping);
	friend ostream& operator << (ostream& out, const Topping& topping);
	friend bool operator == (const Topping& left, const Topping& right);
};