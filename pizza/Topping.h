#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Topping
{
private:
	string name;
	double price;
public:
	Topping(string name, double price);
	Topping();

	vector<Topping> getAllToppings();
	void write(ofstream& fout) const;
	void read(ifstream& fin);
	double getPrice();

	friend ostream& operator << (ostream& out, const Topping topping);
	friend bool operator == (const Topping& left, const Topping& right);
};
