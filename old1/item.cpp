#include "item.h"
#include <iostream>
// Default constructor. Set all values to zero, leaves costPerPurch default.
Item::Item():totalCost(0), totalYards(0) {}

Item::Item(const std::vector<std::pair<double,double> > &cpp)
	:totalCost(0), totalYards(0), costPerPurch(cpp)
{
	setTotals();
}

Item::Item(double sqyds, double cost)
	:totalCost(sqyds*cost), totalYards(sqyds)
{
	costPerPurch.push_back(std::pair<double,double>(sqyds,cost));
}

void Item::add(const std::pair<double,double> newAmt)
{
	costPerPurch.push_back(newAmt);
	setTotals();
}

// Removes yards of fabric from the item. Uses the oldest (first in vector) fabric first.
void Item::subtract(int amt)
{

	std::vector<std::pair<double,double> >::iterator frontIter = costPerPurch.begin();
	while(true)
	{
		// First element has >= fabric than what is being subtracted?
		if(frontIter->first >= amt)
		{
			if(frontIter->first == amt)	// Equal to subtracted amount?
			{
				costPerPurch.erase(frontIter);	// Remove the first element.
			}
			else	// Greater than subtracted amount?
			{
				frontIter->first -= amt;	// Subtract amt from the first element.
			}
			break;
		}
		else // Less than subtracted amount?
		{
			if(totalYards < 0)
				totalYards = 0;
			amt -= frontIter->first;				// Use all the fabric from current first element.
			costPerPurch.erase(frontIter);		// Erase first element.
			frontIter = costPerPurch.begin();	// Move the :frontIter to the new first element.
		}
	}
	setTotals();
}

void Item::printAll() const
{
	for(std::vector<std::pair<double,double> >::const_iterator i = costPerPurch.begin();
		i != costPerPurch.end(); ++i)
	{
		std::cout << "\n\tQTY: " << i->first << " - COST: " << i->second;
	}
	std::cout << std::endl;
}

void Item::setTotals()
{
	totalCost = 0;
	totalYards = 0;
	for(std::vector<std::pair<double,double> >::const_iterator i = costPerPurch.begin();
		i != costPerPurch.end(); ++i)
	{
		totalCost += i->first * i->second;
		totalYards += i->first;
	}
}
