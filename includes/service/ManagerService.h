#pragma once

#include "Data.h"
<<<<<<< HEAD
#include "NumberInString.h";
#include "InvalidPrice.h";
#include "Offer.h"
=======
#include "NumberInString.h"
#include "InvalidPrice.h"
>>>>>>> e432685ca5359894d276928a795c4a5b12183e4c

class ManagerService
{
private:
	Data repo;
public:
	ManagerService();
	void addTopping(const Topping& topping);
	void addSideOrder(const SideOrder& side);
	void addSpecialOrder(string ordername, const Order& order);
	void addDeliveryPlace(string place);

	vector<Topping> getToppings();
private:
	bool containsOnlyAlpha(string s);
	bool validPrice(double p);
};

