#include "KitchenUI.h"

KitchenUI::KitchenUI() {}

//TODO: Only allow certain workplaces and let the user pick from that
void KitchenUI::kitchenMenu() {
	char input;
	while (true) {
		try {
 			vector<Location> locations = service.getLocations();
			cout << "Choose the location of your workplace" << endl;
			for (size_t i = 0; i < locations.size(); ++i) {
				cout << i + 1 << ": " << locations.at(i).getAddress() << endl;
			}
			cout << "0: Go back" << endl;
			cout << "Input: ";
			cin >> input;
			if (input == '0') {
				return;
			}
			else {
				try {
					vector<Pizza> pizzas = service.getPizzas(locations.at((int)input - 49));
					while (true) {
						for (size_t i = 0; i < pizzas.size(); ++i) {
							cout << i + 1 << ": " << showPizzaInfoShort(pizzas.at(i)) << endl;
						}
						cout << "0: Go back" << endl;
						cout << "Input: ";
						cin >> input;
						if (input == '0') {
							return;
						}
						else {
							try {
								while (true) {
									int pizzanr = (int)input - 49;
									cout << showPizzaInfo(pizzas.at(pizzanr)) << endl;
									cout << "1: Set as Baking" << endl;
									cout << "2: Set as Ready" << endl;
									cout << "3: Go Back" << endl;
									cout << "Input: ";
									cin >> input;
									if (input == '1') {
										service.setOrderAsBaking(pizzas.at(pizzanr).getID());
									}
									else if (input == '2') {
										service.setOrderAsReady(pizzas.at(pizzanr).getID());
									}
									else if (input == '3') {
										break;
									}
									else {
										cout << "Invalid input.";
									}
								}
							}
							catch (out_of_range) {
								cout << "Invalid index." << endl;
							}
						}
					}
				}
				catch (out_of_range) {
					cout << "Invalid index." << endl;
				}
				catch (EmptyVector) {
					cout << "No pizzas available for this location." << endl;
				}
				catch (FailedOpenFile) {
					cout << "Failed to open file." << endl;
				}
			}
		}
		catch (EmptyVector) {
			cout << "No locations available." << endl;
			break;
		}
		catch (FailedOpenFile) {
			cout << "Failed to open file." << endl;
			break;
		}
	}
}

string KitchenUI::showPizzaInfo(const Pizza& pizza) const {
	string info = "A ";
	info += pizza.getPizzaSize().getName() + " pizza with ";
	if (pizza.getToppings().size() == 0) {
		info += "no toppings, ";
	}
	else {
		for (size_t i = 0; i < pizza.getToppings().size(); ++i) {
			info += pizza.getToppings().at(i).getName() + ", ";
		}
	}
	info += pizza.getCrust().getName() + " crust.";
	info += " It is currently ";
	if (pizza.getPhase() == PREPERATION) {
		info += " in preperation.";
	}
	else if (pizza.getPhase() == BAKING) {
		info += " baking.";
	}
	return info;
}

string KitchenUI::showPizzaInfoShort(const Pizza& pizza) const {
	string info = "";
	info += pizza.getID() + " - ";
	info += pizza.getToppings().size() + " toppings, ";
	info += pizza.getPizzaSize().getName() + " ";
	info += pizza.getCrust().getName() + " pizza - ";
	if (pizza.getPhase() == PREPERATION) {
		info += "in preperation";
	}
	else if (pizza.getPhase() == BAKING) {
		info += "baking";
	}
	return info;
}