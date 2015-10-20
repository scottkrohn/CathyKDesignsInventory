#include <iostream>
#include <stdexcept>
#include "item.h"
#include <utility>
#include <vector>
#include "inventory.h"
#include <fstream>
#include <string>
#include "InventoryWin.h"

int main()
{
	try
	{
		/*Inventory inv("inventory.txt");
		inv.print();*/
		//Inventory inv;

		//inv.addNewStock(Stock(std::string("Peacock"), Item(25, 8.99)));
		//inv.addNewStock(Stock(std::string("Chevron"), Item(17, 6.99)));
		//inv.addNewStock(Stock(std::string("Batman"), Item(10, 12.99)));
		//inv.addNewStock(Stock(std::string("dandelion"), Item(4, 6.99)));
		//inv.addNewStock(Stock(std::string("critters"), Item(10, 3.99)));

		//std::cout << "Press enter to continue:";
		//std::cin.get();

		//inv.addStock(Stock(std::string("chevron"), Item(7, 7.99)));
		//inv.addStock(Stock(std::string("chevron"), Item(10, 6.49)));
		//inv.addStock(Stock(std::string("chevron"), Item(5, 8.79)));

		//inv.addStock(Stock(std::string("batman"), Item(10, 10.99)));
		//inv.addStock(Stock(std::string("batman"), Item(4, 14.99)));
		//inv.addStock(Stock(std::string("batman"), Item(15, 6.99)));

		//inv.addStock(Stock(std::string("peacock"), Item(3, 10.99)));
		//inv.addStock(Stock(std::string("peacock"), Item(15, 5.99)));
		//inv.addStock(Stock(std::string("peacock"), Item(3, 7.99)));

		//inv.addStock(Stock(std::string("dandelion"), Item(5, 8.99)));
		//inv.addStock(Stock(std::string("dandelion"), Item(4, 10.99)));

		//inv.addStock(Stock(std::string("critters"), Item(4, 4.99)));
		//inv.addStock(Stock(std::string("critters"), Item(2, 5.99)));
		//inv.addStock(Stock(std::string("critters"), Item(6, 3.99)));

		//std::cout << "Press enter to continue:";
		//std::cin.get();

		//inv.subtractStock("peacock", 15);

		//inv.print();
		//inv.printBreakdown(std::string("peacock"));
		//inv.printBreakdown(std::string("chevron"));
		//inv.printBreakdown(std::string("batman"));

		//std::vector<Stock> stocks(inv.getAllStock());
		//for(std::vector<Stock>::const_iterator i = stocks.begin();
		//	i != stocks.end(); ++i)
		//{
		//	std::cout << i->name << std::endl;
		//}
		//Stock s(inv.getStock(std::string("batman")));
		//std::cout << "-----" << std::endl;
		//std::cout << s.name << std::endl;
		
		InventoryWin iw(Point(500,400), 550, 300, "Inventory Manager 1.0", "inventory.txt");
		return gui_main();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cin.get();
	}
}
