#include <iostream>

#include "Data.h"

using namespace std;
#include "MainUI.h"
//#include <cstdlib>
//#include <time.h>

#include "SalesmanService.h"


Data repo;

/*void addTopping();
void addCrust();
void addSize();
void addSide();
void addLocation();
void addOrder();*/

/*long lrand()
{
	if (sizeof(int) < sizeof(unsigned long))
		return (static_cast<unsigned long>(rand()) << (sizeof(unsigned int) * 8)) |
		rand();

	return rand();
}*/
/*unsigned long long ullRandGen() {
	unsigned long long n = abs(rand());
	return (n << (sizeof(int) * 8)) | abs(rand());
}*/

int main()
{
	MainUI mainUI;
	mainUI.startUI();

<<<<<<< HEAD
	/*SalesmanService ss;
=======
	/*
	SalesmanService ss;
>>>>>>> 6177b8759bcad99d275921beae3fee898a4fb313
	Order o;
	Pizza p;
	PizzaCrust pc;
	PizzaSize ps;
	// Pizza crust
	pc.setName("Normal");
	pc.setPrice(250);

	// Set crust on pizza
	p.setCrust(pc);
	p.setPhase(PREPERATION);

	// Pizza size
	ps.setName("Medium");
	ps.setPriceMod(1.5);
	// Set size on pizza
	p.setPizzaSize(ps);

	// Creating toppings (these will be retrieved from file)
	Topping t1;
	t1.setName("Ham");
	t1.setPrice(350);
	Topping t2;
	t2.setName("Pineapple");
	t2.setPrice(400);
	// Put toppings in vector 
	vector<Topping> toppings;
	toppings.push_back(t1);
	toppings.push_back(t2);

	// Set toppings on pizza
	p.setToppings(toppings);

	// Create vector of pizzas
	vector<Pizza> pizzas;
	pizzas.push_back(p);

	// add pizza to order
	o.setPizzas(pizzas);
	// set delivery method to order
	o.setDeliveryMethod(PICKUP);
	// test comment
	o.setComment("This is a comment");

	// create location for pizza place
	Location l;
	l.setAddress("Hraunbaer 121, 110 Rvk");
	// set location on order
	o.setLocation(l);

	try {
		//ss.registerNewOrder(o);
		cout << "File before modification:" << endl << endl;
		vector<Order> orders = ss.getAllOrders();
		for (int i = 0; i < orders.size(); i++) {
			cout << orders[i] << endl;
		}

		cout << endl << endl << endl;
		cout << "File after modification: " << endl << endl;

		ss.appendToOrder(orders[0], o);

		orders = ss.getAllOrders();
		for (int i = 0; i < orders.size(); i++) {
			cout << orders[i] << endl;
		}
	}
	catch (InvalidOrder) {
		cout << "Invalid order";
	}

<<<<<<< HEAD
	system("PAUSE");*/
=======
	system("PAUSE");
	*/
>>>>>>> 6177b8759bcad99d275921beae3fee898a4fb313
	return 0;
}
	
	/*string input;

	MainUI mainUI;
	mainUI.startUI();
	/*string input;
	do {
		cout << "1. Add topping" << endl;
		cout << "2. Add crust" << endl;
		cout << "3. Add size" << endl;
		cout << "4. Add side" << endl;
		cout << "5. Add location" << endl;
		cout << "6. Create order" << endl;
		cout << "q. Quit" << endl;
		cout << "Input: ";
		cin >> input;
		if (input == "1") {
			addTopping();
		}
		else if (input == "2") {
			addCrust();
		}
		else if (input == "3") {
			addSize();
		}
		else if (input == "4") {
			addSide();
		}
		else if (input == "5") {
			addLocation();
		}
		else if (input == "6") {
			addOrder();
		}
	} while (input != "q");*/
/*void addTopping() {
	cout << "Creating a new Topping" << endl;
	cout << "Name: ";
	string name;
	cin >> name;
	cout << "Price: ";
	double price;
	cin >> price;
	repo.WriteToFile(Topping(name, price));
}

void addCrust() {
	cout << "Creating a new Crust" << endl;
	cout << "Name: ";
	string name;
	cin >> name;
	cout << "Price: ";
	double price;
	cin >> price;
	repo.WriteToFile(PizzaCrust(name, price));
}

void addSize() {
	cout << "Creating a new Size" << endl;
	cout << "Name: ";
	string name;
	cin >> name;
	cout << "Mod: ";
	double mod;
	cin >> mod;
	repo.WriteToFile(PizzaSize(name, mod));
}

void addSide() {
	cout << "Creating a new Side" << endl;
	cout << "Name: ";
	string name;
	cin >> name;
	cout << "Price: ";
	double price;
	cin >> price;
	repo.WriteToFile(SideOrder(name, price));
}

void addLocation() {
	cout << "Creating a new Location" << endl;
	cout << "Name: ";
	string name;
	cin >> name;
	repo.WriteToFile(Location(name));
}

void addOrder() {
	string input;
	vector<Topping> toppings;
	vector<SideOrder> sides;
	vector<Pizza> pizzas;
	PizzaCrust crust;
	PizzaSize size;
	Location location;
	do {
		cout << "1. Add topping" << endl;
		cout << "2. Choose crust" << endl;
		cout << "3. Choose size" << endl;
		cout << "4. Add side" << endl;
		cout << "5. Choose location" << endl;
		cout << "6. Complete" << endl;
		cout << "q. Quit" << endl;
		cout << "Input: ";
		cin >> input;
		if (input == "1") {
			vector<Topping> tops = repo.RetrieveAllFromFile<Topping>();
			cout << "Choose a topping" << endl;
			for (int i = 0; i < tops.size(); ++i) {
				cout << i << " " << tops.at(i) << endl;
			}
			int inp;
			cin >> inp;
			toppings.push_back(tops.at(inp));
		}
		else if (input == "2") {
			vector<PizzaCrust> crusts = repo.RetrieveAllFromFile<PizzaCrust>();
			cout << "Choose a crust" << endl;
			for (int i = 0; i < crusts.size(); ++i) {
				cout << i << " " << crusts.at(i) << endl;
			}
			int inp;
			cin >> inp;
			crust = crusts.at(inp);
		}
		else if (input == "3") {
			vector<PizzaSize> sizes = repo.RetrieveAllFromFile<PizzaSize>();
			cout << "Choose a crust" << endl;
			for (int i = 0; i < sizes.size(); ++i) {
				cout << i << " " << sizes.at(i) << endl;
			}
			int inp;
			cin >> inp;
			size = sizes.at(inp);
		}
		else if (input == "4") {
			vector<SideOrder> sds = repo.RetrieveAllFromFile<SideOrder>();
			cout << "Choose a topping" << endl;
			for (int i = 0; i < sds.size(); ++i) {
				cout << i << " " << sds.at(i) << endl;
			}
			int inp;
			cin >> inp;
			sides.push_back(sds.at(inp));
		}
		else if (input == "5") {
			vector<Location> locs = repo.RetrieveAllFromFile<Location>();
			cout << "Choose a location" << endl;
			for (int i = 0; i < locs.size(); ++i) {
				cout << i << " " << locs.at(i) << endl;
			}
			int inp;
			cin >> inp;
			location = locs.at(inp);
		}
		else if (input == "6") {
			string comment, address;
			cout << "Comment: ";
			cin >> comment;
			cout << "Address: ";
			cin >> address;
			pizzas.push_back(Pizza(toppings, crust, size));
			//repo.WriteToFile(Order(pizzas, sides, 0, 0, location, comment, address));
		}
	} while (input != "q");
}*/