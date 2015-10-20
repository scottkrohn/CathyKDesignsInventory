#ifndef CHECKBOX_GUARD
#define CHECKBOX_GUARD
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Button.H>
#include "Simple_window.h"
#include "Graph.h"

struct Checkbox: public Widget
{
public:
	Checkbox(const Point &p, int w, int h, const std::string &l, Graph_lib::Callback cb);
	void attach(Window&);
	int value() const {return ((Fl_Button*)pw)->value();}
};

#endif