#ifndef ITEM_GUARD
#define ITEM_GUARD
#include <vector>
#include <utility>

/* An Item can be constructed by passing
*/

class Item
{
public:
	Item();
	Item(const std::vector<std::pair<double,double> > &cpp);
	Item(double sqtotalYards, double cost);

	void add(const std::pair<double,double> newAmt);
	void subtract(int amt);

	double costPerYard() const {return totalCost/totalYards;}
	double costPerInch() const {return totalCost/(totalYards*1296);}
	double total() const {return totalCost;}
	double yards() const {return totalYards;}

	const std::vector<std::pair<double,double> > & getAll() const {return costPerPurch;}
	void printAll() const;
private:
	double totalCost;
	double totalYards;
	// first = yards, second = cost per yard
	std::vector<std::pair<double,double> > costPerPurch;
	void setTotals();
};

#endif
