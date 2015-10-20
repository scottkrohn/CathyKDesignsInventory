#ifndef INVENTORYWIN_GUARD
#define INVENTORYWIN_GUARD
#include "Simple_window.h"
#include "Graph.h"
#include "inventory.h"
#include <string>

class InventoryWin: public Window
{
public:
	InventoryWin(const Point &topLeft, int w, int h, const std::string &title,
				 const std::string &filename);
private:

	Inventory inv;

	// xy postion of the main window
	int mainx;
	int mainy;

	// Buttons
	Button quitButton;
	Button addButton;
	Button subtractButton;
	Button viewButton;

	// Labels
	Text titleLabel;

	// Callbacks
	static void cb_quit(void *, void *win) {((InventoryWin*)win)->quit();}
	static void cb_add(void *, void *win) {((InventoryWin*)win)->add();}
	static void cb_subtract(void *, void *win) {((InventoryWin*)win)->subtract();}
	static void cb_view(void *, void *win) {((InventoryWin*)win)->view();}

	// Utility functions for callbacks
	void quit() {hide();}
	void add();
	void subtract();
	void view();

	// Other functions
};

#endif