#pragma once

#include "ManagerService.h"
#include "CommonUI.h"
#include "Canceled.h"

using namespace std;

class ManagerUI: public CommonUI
{
private:
	ManagerService service;
	//Toppings
	void showToppingsMenu();
	void showToppingCreationMenu();
	void showToppingDeleteMenu();
	void showToppingViewMenu();
	void editTopping(int index);
	//Locations
	void showLocationsMenu();
	void showLocationCreationMenu();
	void showLocationDeleteMenu();
	void showLocationViewMenu();
	//Sizes
	void showSizeMenu();
	void showSizeCreationMenu();
	void showSizesDeleteMenu();
	void showSizeViewMenu();
	//Crust
	void showCrustMenu();
	void showCrustCreationMenu();
	void showCrustDeleteMenu();
	void showCrustViewMenu();
	//Sides
	void showSidesMenu();
	void showSidesCreationMenu();
	void showSidesDeleteMenu();
	void showSidesViewMenu();
	//offers
	void showOffersMenu();
	void showOfferCreationMenu();
	void showOfferViewMenu();
	void showOfferDeleteMenu();
	void showCreatePizzaMenu(Pizza& pizza);
	void pizzaOption();
	void toppingOption();
	void priceOption();
	void locationOption();
	void sideOrderOption();
	//Orders
	void showOrders();
public:
	ManagerUI();
	void showMainMenu();
	void managerMenu();
};

