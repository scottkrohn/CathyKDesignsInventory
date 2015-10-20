#ifndef ADDSTOCKWIN_GUARD
#define ADDSTOCKWIN_GUARD
#include "Simple_window.h"
#include "Graph.h"
#include "inventory.h"
#include <string>
#include "Scrollbox.h"
#include "checkbox.h"

class AddStockWin: public Window
{
public:
	AddStockWin(const Point &topLeft, int w, int h, const std::string &title,
				Inventory &i);
private:
	Inventory inv;

	// Labels
	Text titleLabel;

	// Checkboxes
	Checkbox newCheck;
	Checkbox existingCheck;

	//Buttons
	Button backButton;

	// Scrollbox
	Scrollbox outputBox;

	// Input boxes
	In_box nameInputBox;
	In_box qtyInputBox;
	In_box costInputBox;

	// Callbacks
	static void cb_back(void *, void *win) {((AddStockWin*)win)->back();}
	static void cb_nothing(void *, void *win) {}

	void back() {hide();}
};

#endif