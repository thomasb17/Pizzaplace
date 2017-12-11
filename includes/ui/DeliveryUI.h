#pragma once
#include <iostream>
#include <string>
#include "DeliveryService.h"
#include "EmptyVector.h"
using namespace std;

class DeliveryUI
{
private:
	DeliveryService service;
public:
	DeliveryUI();
	void deliveryMenu();
	void allOrdersMenu();
	void ordersMenu();
	string showPizzaInfoShort(const Pizza& pizza) const;
	string showOrderInfo(const Order& order) const;
	string showOrderInfoShort(const Order& order) const;
};

