#include "ViewStockWin.h"
#include <sstream>

StockWin::StockWin(const Point &topLeft, int w, int h, const std::string &title,
				   const Inventory &i)
	:Window(topLeft, w, h, title),
	thisx(w),
	thisy(h),
	inv(i),
	backButton(Point(w*.5-75, h-40), 150, 30, "Back", cb_back),
	allButton(Point(w*.1, h*.09), 250, 40, "View All Stock", cb_viewall),
	specificButton(Point(w*.55, h*.09), 250, 40, "View Specific Stock", cb_viewspecific),
	titleLabel(Point(w*.5-150, h*.06), "View Current Stock"),
	stockNameBox(Point(w*.6, h*.15), 200, 30, "Item Name: "),
	totalValueBox(Point(w*.15, h*.15), 200, 30, "Total Value:"),
	outputBox(Point(w*.05, h*.20), w*.9, h*.7, "", cb_nothing)
{
	titleLabel.set_font_size(35);

	attach(backButton);
	attach(allButton);
	attach(specificButton);

	attach(titleLabel);

	attach(stockNameBox);
	attach(totalValueBox);

	std::ostringstream totalValueOSS;
	totalValueOSS << "$" << inv.totalValue();
	totalValueBox.put(totalValueOSS.str());

	attach(outputBox);
}

void StockWin::viewAll()
{
	outputBox.clear();
	std::vector<Stock> allStock = inv.getAllStock();
	for(std::vector<Stock>::const_iterator i = allStock.begin(); i != allStock.end(); ++i)
	{
		std::ostringstream lineOne;
		lineOne << "Fabric: [" << i->name << "]" << std::endl;
		std::ostringstream lineTwo;
		lineTwo << "\tQuantity: " << i->itm.yards() << " yards." << std::endl;
		std::ostringstream lineThree;
		lineThree << "\tValue:  $"  << i->itm.total() << std::endl;
		outputBox.add(lineOne.str().c_str());
		outputBox.add(lineTwo.str().c_str());
		outputBox.add(lineThree.str().c_str());
	}
	redraw();
}

void StockWin::viewSpecific()
{
	outputBox.clear();
	std::string stockName = stockNameBox.get_string();
	if(!inv.inInventory(stockName))
	{
		if(stockName == "") stockName = "blank";
		std::string notFound("No stock found for name: [" + stockName + "]");
		outputBox.add(notFound.c_str());
	}
	else
	{
		Stock foundStock(inv.getStock(stockName));
		std::vector<std::pair<double,double> > purchaseData(foundStock.itm.getAll());
		std::vector<std::string> purchases;

		std::ostringstream totalYds;
		totalYds << "TOTAL YARDS: " << foundStock.itm.yards();
		outputBox.add(totalYds.str().c_str());

		std::ostringstream perYdAvg;
		perYdAvg.setf(ios::fixed);
		perYdAvg.precision(2);
		perYdAvg << "Average cost/yd: $" << foundStock.itm.costPerYard();
		outputBox.add(perYdAvg.str().c_str());

		std::ostringstream perInAvg;
		perInAvg.setf(ios::fixed);
		perInAvg.precision(3);
		perInAvg << "Average cost/in: $" << foundStock.itm.costPerInch();
		outputBox.add(perInAvg.str().c_str());

		std::ostringstream totalCost;
		totalCost.setf(ios::fixed);
		totalCost.precision(2);
		totalCost << "Total cost: $" << foundStock.itm.total();
		outputBox.add(totalCost.str().c_str());

		outputBox.add("");
		outputBox.add("** Unused Inventory Purchase History **");

		int count = 1;
		for(std::vector<std::pair<double,double> >::const_iterator i = purchaseData.begin();
			i != purchaseData.end(); ++i)
		{
			std::ostringstream quantities;
			quantities << count++ << ") Qty: " << i->first << " @ " << i->second << "/yd";
			outputBox.add(quantities.str().c_str());
		}
	}
	redraw();
}
