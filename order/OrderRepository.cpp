#include <fstream>
#include "OrderRepository.h"

OrderRepository::OrderRepository() {
    this->file = "orders.dat";
}

/*
	todo: Do the storing and retrieving of orders
*/

void OrderRepository::storeOrder(const Order &order) const {
    ofstream fout;
    fout.open(this->file, ios::binary | ios::app);
    //order.write(fout);
    fout.close();
}

Order OrderRepository::retrieveOrder() const {
    ifstream fin;
    Order order;
    fin.open(this->file, ios::binary);
    //order.read();
    fin.close();
    return order;
}