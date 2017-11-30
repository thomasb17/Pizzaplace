#include "Topping.h"

Topping::Topping(){}

void Topping::NewTopping(string name, double price)
{
	//@todo append topping to file
}

vector<Topping> Topping::getAllToppings()
{
	vector<Topping> toppings;
	return toppings;
}

void Topping::write(ofstream& fout) const {
	int len = this->name.length() + 1;
	fout.write((char*)(&len), sizeof(int));
	fout.write(this->name.c_str(), len);
	fout.write((char*)(&this->price), sizeof(double));
}

void Topping::read(ifstream& fin) {
	int len;
	this->name = "";
	fin.read((char*)(&len), sizeof(int));
	char* str = new char[len];
	fin.read(str, len);
	this->name = str;
	fin.read((char*)(&this->price), sizeof(double));
	delete[] str;
}

double Topping::getPrice() {
	return this->price;
}

ostream& operator<< (ostream& out, const Topping topping)
{
    out << topping.name << " " << topping.price;

    return out;
}