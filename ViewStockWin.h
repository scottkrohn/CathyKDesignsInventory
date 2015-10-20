#ifndef VIEWSTOCKWIN_GUARD
#define VIEWSTOCKWIN_GUARD
#include "Scrollbox.h"
#include <string>
#include <iostream>
#include "inventory.h"

class StockWin: public Window
{
public:
	StockWin(const Point &topLeft, int w, int h, const std::string &title,
			 const Inventory &i);
	~StockWin() {outputBox;}
private:
	int thisx;
	int thisy;
	Inventory inv;

	// Buttons
	Button backButton;
	Button allButton;
	Button specificButton;

	// Labels
	Text titleLabel;

	// Rectangles

	// Input/Output Boxes
	In_box stockNameBox;
	Out_box totalValueBox;

	// Scrollbox
	Scrollbox outputBox;

	static void cb_nothing(void *, void *win) {((StockWin*)win)->nothing();}
	static void cb_back(void *, void *win) {((StockWin*)win)->back();}
	static void cb_viewall(void *, void *win) {((StockWin*)win)->viewAll();}
	static void cb_viewspecific(void *, void *win) {((StockWin*)win)->viewSpecific();}

	void back() {hide();}
	void nothing() {};
	void viewAll();
	void viewSpecific();
};

#endif