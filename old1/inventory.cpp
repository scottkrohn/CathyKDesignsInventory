#include "inventory.h"
#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <stdexcept>

/********** STOCK CLASS DEFINITIONS **********/
Stock::Stock(const std::string &n, const Item &newItem): name(n), itm(newItem)
{
	for(std::string::iterator i = name.begin(); i != name.end(); ++i)
	{
		*i = tolower(*i);
	}
}


/********** INVENTORY CLASS DEFINITIONS **********/

// Add a new item to the inventory
bool Inventory::addNewStock(const Stock &newStock)
{
	if(inInventory(newStock))
	{
		std::cout << "The item " << newStock.name << " already exists." << std::endl;
		return false;
	}
	items.push_back(newStock);

	outputToFile();

	return true;
}

// Add stock to an item that is already in the Inventory.
bool Inventory::addStock(const Stock &additionalStock)
{
	// Is item already in the Inventory?
	if(!inInventory(additionalStock))
	{
		std::cout << "No stock in the Inventory matches \"" << additionalStock.name << "\"." << std::endl;
		return false;
	}
	// Find an iterator to the item that needs to be updated.
	std::vector<Stock>::iterator currentStock = find(items.begin(), items.end(), additionalStock);
	// Add the new stock to the current stock.
	currentStock->itm.add(std::pair<double,double>(additionalStock.itm.yards(), additionalStock.itm.costPerYard()));
	// Add the stock to the inventory.txt file.
	outputToFile();
	return true;
}

// Remove stock from the inventory, remove the item from the inventory if no stock left
bool Inventory::subtractStock(const std::string &name, double amt)
{
	if(!inInventory(name))
	{
		std::cout << "No stock in the inventory matches \"" << name << "\"" << std::endl;
		return false;
	}
	std::vector<Stock>::iterator currentStock = find_if(items.begin(), items.end(), stockByName(name));

	currentStock->itm.subtract(amt);
	if(currentStock->itm.yards() == 0)
	{
		removeStock(name);
	}
	outputToFile();
	return true;
}

// Completely remove an item from the Inventory.
void Inventory::removeStock(const std::string &name)
{
	if(!inInventory(name))
	{
		std::cout << "No stock in the inventory matches \"" << name << "\"" << std::endl;
		return;
	}
	std::vector<Stock>::iterator stockIter = find_if(items.begin(), items.end(), stockByName(name));
	items.erase(stockIter);
}

// Is this item already in the inventory?
bool Inventory::inInventory(const Stock &newStock) const
{
	std::vector<Stock>::const_iterator iter = find(items.begin(), items.end(), newStock);
	if(iter == items.end())
	{
		return false;
	}
	return true;
}

// Is any item with a specific name already in the inventory?
bool Inventory::inInventory(const std::string &name) const
{
	for(std::vector<Stock>::const_iterator i = items.begin(); i != items.end(); ++i)
	{
		if(i->name == name)
		{
			return true;
		}
	}
	return false;
}

// Display the current Inventory.
void Inventory::print() const
{
	for(std::vector<Stock>::const_iterator i = items.begin(); i != items.end(); ++i)
	{
		std::cout << "Item Name: " << i->name << " - QTY: " << i->itm.yards();
		std::cout << " -  VALUE: " << i->itm.total() << std::endl;
	}
}

// Display the qty/price breakdown for a specific item in the Inventory
void Inventory::printBreakdown(const std::string &name) const
{
	if(!inInventory(name))
	{
		std::cout << "No stock in the inventory matches \"" << name << "\"" << std::endl;
	}
	std::vector<Stock>::const_iterator stockItem = find_if(items.begin(), items.end(), stockByName(name));
	std::cout << "NAME: " << name << " --  Per Yard: " << stockItem->itm.costPerYard() << " -- ";
	std::cout << "Per Inch: " << stockItem->itm.costPerInch();
	stockItem->itm.printAll();
}

Stock Inventory::getStock(const std::string &name) const
{
	if(!inInventory(name))
	{
		throw std::runtime_error("Invalid stock name for getStock()");
	}
	std::vector<Stock>::const_iterator foundStock = find_if(items.begin(), items.end(), stockByName(name));
	return (*foundStock);
}

void Inventory::outputToFile() const
{
	std::ofstream outfile(filename.c_str());
	if(!outfile)
	{
		throw std::runtime_error("Unable to open outfile: " + filename);
	}

	for(std::vector<Stock>::const_iterator i = items.begin(); i != items.end(); ++i)
	{
		outfile << *i;
	}
}

/*******************************************************************************************/

std::ofstream & operator<<(std::ofstream &outfile, const Stock &stk)
{
	outfile << stk.name << "," << stk.itm.yards();
	for(std::vector<std::pair<double,double> >::const_iterator i = stk.itm.getAll().begin();
		i != stk.itm.getAll().end(); ++i)
	{
		outfile << ",(" << i->first << "," << i->second << ")";
	}
	outfile << ";" << std::endl;
}
