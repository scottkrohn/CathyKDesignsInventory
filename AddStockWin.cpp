#include "AddStockWin.h"

AddStockWin::AddStockWin(const Point &topLeft, int w, int h, const std::string &title, Inventory &i)
	:Window(topLeft, w, h, title),
	backButton(Point(w*.5-75, h-40), 150, 30, "Back", cb_back),
	titleLabel(Point(w*.5-85, h*.06), "Add Stock"),
	newCheck(Point(w*.5+50, h*.11), 20, 20, "New", cb_nothing),
	existingCheck(Point(w*.5-100, h*.11), 20, 20, "Existing", cb_nothing),
	outputBox(Point(w*.05, h*.4), w*.9, h*.5, "", cb_nothing),
	nameInputBox(Point(w*.5-150, h*.2), 300, 20, "Fabric name:"),
	qtyInputBox(Point(w*.5-150, h*.25), 300, 20, "Quantity in yds:"),
	costInputBox(Point(w*.5-150, h*.3), 300, 20, "Cost per yd:")
{
	titleLabel.set_font_size(35);
	attach(titleLabel);
	attach(newCheck);
	attach(existingCheck);
	attach(backButton);
	attach(outputBox);
	attach(nameInputBox);
	attach(qtyInputBox);
	attach(costInputBox);
}