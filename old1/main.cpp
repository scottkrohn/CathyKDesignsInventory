#include <iostream>
#include <stdexcept>
#include "item.h"
#include <utility>
#include <vector>
#include "inventory.h"
#include <fstream>
#include <string>

int main()
{
	try
	{
		Inventory inv;

		inv.addNewStock(Stock(std::string("Peacock"), Item(25,8.99)));
		inv.addNewStock(Stock(std::string("Chevron"), Item(17, 6.99)));
		inv.addNewStock(Stock(std::string("Batman"), Item(10,12.99)));

		std::cout << "Press enter to continue:";
		std::cin.get();

		inv.addStock(Stock(std::string("chevron"), Item(7,7.99)));
		inv.addStock(Stock(std::string("batman"), Item(10,12.99)));
		inv.addStock(Stock(std::string("batman"), Item(10, 9.99)));
		inv.addStock(Stock(std::string("PEACOCK"), Item(10, 3.99)));

		std::cout << "Press enter to continue:";
		std::cin.get();

		inv.subtractStock("peacock", 26);

		//inv.print();
		//inv.printBreakdown(std::string("peacock"));
		//inv.printBreakdown(std::string("chevron"));
		//inv.printBreakdown(std::string("batman"));

		std::vector<Stock> stocks(inv.getAllStock());
		for(std::vector<Stock>::const_iterator i = stocks.begin();
			i != stocks.end(); ++i)
		{
			std::cout << i->name << std::endl;
		}
		Stock s(inv.getStock(std::string("batman")));
		std::cout << "-----" << std::endl;
		std::cout << s.name << std::endl;
		return 0;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
