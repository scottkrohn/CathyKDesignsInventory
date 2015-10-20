#ifndef INVENTORY_GUARD
#define INVENTORY_GUARD
#include <string>
#include <vector>
#include "item.h"
#include <fstream>

// Stock is used to store the name of an inventory item & information about that item.
struct Stock
{
	Stock(const std::string &n, const Item &newItem);
	Stock(const Stock &s): name(s.name), itm(s.itm) {}
	std::string name;
	Item itm;
	bool operator==(const Stock &s) {return name == s.name;}
	bool operator!=(const Stock &s) {return name != s.name;}
	bool operator==(const Stock &s) const {return name == s.name;}
	bool operator!=(const Stock &s) const {return name == s.name;}
};

// Inventory keeps track of a variety of Item obejects. These Item objects
// are what is in stock. It allows for the insertion and removal of Item
// objects, as well as get information on the current inventory.

class Inventory
{
public:
	// Constructors
	Inventory():filename("inventory.txt") {};	// Default constructor, inventory starts empty.
	Inventory(const Item &item);	// Start inventory with 1st item.

	// Add a new Stock object, doesn't add a new entry if the item is already in items.
	bool addNewStock(const Stock &newStock);
	// Add additional stock to an already existing Inventory item.
	bool addStock(const Stock &additionalStock);
	// Subtract a portion of existing stock from the inventory
	bool subtractStock(const std::string &name, double amt);
	// Completley rmove an item from the Inventory.
	void removeStock(const std::string &name);
	// Display the current items in stock with their quantities.
	void print() const;
	void printBreakdown(const std::string &name) const;

	// Functions to return a specific inventory information
	const std::vector<Stock> & getAllStock() const {return items;}
	Stock getStock(const std::string &name) const;

private:
	std::vector<Stock> items;
	std::string filename;
	bool inInventory(const Stock &newStock) const;
	bool inInventory(const std::string &name) const;
	void outputToFile() const;
};

class stockByName
{
public:
	stockByName(const std::string &n): name(n) {}

	bool operator()(const Stock &stk) {return name == stk.name;}
private:
	std::string name;
};

std::ofstream & operator<<(std::ofstream &outfile, const Stock &stk);
#endif
