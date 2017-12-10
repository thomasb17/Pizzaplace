#include "SalesmanService.h"


SalesmanService::SalesmanService()
{
	_repo = Data();
}

void SalesmanService::registerNewOrder(Order& order)
{
	if (validateOrder(order)) {
		_repo.WriteToFile(order);
	}
	else {
		throw InvalidOrder();
	}
}

void SalesmanService::appendToOrder(Order& firstOrder, Order& secondOrder)
{
	//validate
	if (validateOrder(firstOrder) && validateOrder(secondOrder)) {
		//grab all orders from file
		vector<Order> orders = _repo.RetrieveAllFromFile<Order>();
		for (int i = 0; i < orders.size(); i++) {
			//find the order to append to
			if (orders[i] == firstOrder) {
				//append the second order to first
				firstOrder = firstOrder + secondOrder;
				//override in file
				overrideOrder(i, firstOrder);
				break;
			}
		}
	}
	else {
		throw InvalidOrder();
	}
}

int SalesmanService::getPriceOfOrder(Order& order)
{
	int price = calculateCost(order);
	return price;
}

void SalesmanService::assignHomeAddress(Order& order, string address)
{
	//address must contain at least one character and one number
	//ex. of address: 'Menntavegur 1' or 'Skogarstigur 12'
	//
	//address can be empty if deliverymethod is pickup
	bool containsCharacter = false;
	bool containsNumber = false;
	if (address == "" && order.getDeliveryMethod() == PICKUP) {
		order.setHomeAddress(address);
	}
	else
	{
		for (int i = 0; i < address.length(); i++) {
			if (isalpha(address[i]) && !containsCharacter) {
				containsCharacter = true;
			}
			if (isalnum(address[i]) && !containsNumber) {
				containsNumber = true;
			}
		}
		if (containsCharacter && containsNumber) {
			order.setHomeAddress(address);
		}
		else {
			throw InvalidAddress();
		}
	}
}

void SalesmanService::setOrderToDelivery(Order& order) {
	order.setDeliveryMethod(SEND);
}

void SalesmanService::setOrderToPickUp(Order& order) {
	order.setDeliveryMethod(PICKUP);
}

void SalesmanService::setOrderAsPaid(Order& order){
	order.setOrderAsPaidFor(true);
}

void SalesmanService::setComments(Order& order, string comment){
	order.setComment(comment);
}

vector<Order> SalesmanService::getAllOrders()
{
	return _repo.RetrieveAllFromFile<Order>();
}


/*

	PRIVATE FUNCTIONS

*/


/*			Returns total cost for the order		*/
int SalesmanService::calculateCost(const Order& order) {
	int total = 0;
	size_t numberOfPizzas = order.getPizzas().size();
	// Pizza cost
	for (size_t i = 0; i < numberOfPizzas; ++i) {
		int temptotal = 0;
		size_t numberOfToppingsOnPizza = order.getPizzas().at(i).getToppings().size();
		for (size_t j = 0; j < numberOfToppingsOnPizza; ++j) {
			temptotal += order.getPizzas().at(i).getToppings().at(j).getPrice(); // Add each topping to price
		}
		temptotal += order.getPizzas().at(i).getCrust().getPrice(); // Add type of crust to price
		temptotal *= order.getPizzas().at(i).getPizzaSize().getPriceMod(); // Add the pizza size to price
		total += temptotal;
	}
	// Side orders cost
	for (int i = 0; i < order.getSides().size(); ++i) {
		total += order.getSides().at(i).getPrice();

	}
	return total;
}

/*			Validate the Order			*/
bool SalesmanService::validateOrder(Order order) {
	// Just check if both pizzas and sides vectors are emtpy
	if (order.getPizzas().empty() && order.getSides().empty()) {
		return false;
	}
	return true;
}

void SalesmanService::overrideOrder(int index, Order edit) {
	_repo.ModifyFileAtIndex<Order>(index, edit);
}