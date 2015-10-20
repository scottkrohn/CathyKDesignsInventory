#include "InventoryWin.h"
#include "ViewStockWin.h"
#include "AddStockWin.h"

InventoryWin::InventoryWin(const Point &topLeft, int w, int h, 
						   const std::string &title, const std::string &filename)
	:Window(topLeft, w, h, title),
	inv(filename),
	mainx(w),
	mainy(h),
	quitButton(Point(w*.5-50,h*.8), 100, 30, "Quit", cb_quit),
	addButton(Point(w*.1, h*.3), 200, 40, "Add New Stock", cb_add),
	subtractButton(Point(w*.55, h*.3), 200, 40, "Subtract Stock", cb_subtract),
	viewButton(Point(w*.5-100, h*.50), 200, 40, "View Stock", cb_view),
	titleLabel(Point(w*.5-145, h*.2), "Inventory Manager")
{
	titleLabel.set_font_size(35);

	attach(quitButton);
	attach(addButton);
	attach(subtractButton);
	attach(viewButton);

	attach(titleLabel);
}

void InventoryWin::add()
{
	AddStockWin addWindow(Point(mainx, mainy), 700, 700, "Add Stock", inv);
	Fl::run();
}

void InventoryWin::subtract()
{
}

void InventoryWin::view()
{
	StockWin stockWindow(Point(mainx, mainy), 700, 700, "View Stock", inv);
	Fl::run();
}