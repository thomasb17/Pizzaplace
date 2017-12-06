#include "MainUI.h"
#include "DeliveryUI.h"
#include "ManagerUI.h"
#include "SalesmanUI.h"
#include "KitchenUI.h"
//#include "Menu.h"

void MainUI::startUI()
{
	char input;
	//Menu menu;
	while (true)
	{
		cout << "\nPlease Pick one of the following jobs:\n"
			//<< menu.printMenu({ "Manager", "Salesman", "Kitchen", "Delivery" })
			<< "Press 'q' to Quit\n"
			<< "Job: ";

		cin >> input;

		switch (input)
		{
		case '1':
		{
			ManagerUI managerUI;
			managerUI.managerMenu();
			break;
		}
		case '2':
		{
			SalesmanUI salesmanUI;
			salesmanUI.salesmanMenu();
			break;
		}
		case '3':
		{
			KitchenUI kitchenUI;
			kitchenUI.kitchenMenu();
			break;
		}
		case '4':
		{
			DeliveryUI deliveryUI;
			deliveryUI.deliveryMenu();
			break;
		}
		case 'q':
		case 'Q':
			exit(1);
		default:
			cout << "Not a valid option." << endl;
		}
	}
}

/*string MainUI::printMenu(vector<string> options)
{
	string biggestString = "";
	for (unsigned int i = 0; i < options.size(); i++)
	{
		if (biggestString.size() < options.at(i).size())
		{
			biggestString = options.at(i);
		}
	}
	string output = "";
	for (unsigned int i = 0; i < options.size(); i++)
	{
		output += printLines(biggestString.size());
		output += "\t| ";
		output += to_string(i + 1);
		output += ". ";
		output += options.at(i);
		for (unsigned int j = 0; j < (biggestString.size() - options.at(i).size()); j++)
		{
			output += " ";
		}
		output += " | ";
		i++;
		
		//if there is an odd number of options, then the last box needs to be empty
		if (options.size() == i)
		{
			output += "   ";
			for (unsigned int j = 0; j < biggestString.size(); j++)
			{
				output += " ";
			}
		}
		else
		{
			output += to_string(i + 1);
			output += ". ";
			output += options.at(i);
			for (unsigned int j = 0; j < (biggestString.size() - options.at(i).size()); j++)
			{
				output += " ";
			}
		}
		output += " |\n";
	}
	output += printLines(biggestString.size());
	return output;
}

//print out minus signs (for lines)
string MainUI::printLines(unsigned int size)
{
	string output = "";
	output += "\t";
	for (unsigned int i = 0; i < size * 2; i++)
	{
		output += "-";
	}
	output += "-------------\n";
return output;
}*/