#pragma once

#include "KitchenService.h"
#include "CommonUI.h"

class KitchenUI: public CommonUI
{
private: 
	KitchenService service;
public:
	KitchenUI();
	void showMainMenu();
	string showPizzaInfo(const Pizza& pizza) const;
	string showPizzaInfoShort(const Pizza& pizza) const;
};

