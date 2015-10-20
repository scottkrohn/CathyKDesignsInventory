#ifndef SCROLLBOX_GUARD
#define SCROLLBOX_GUARD
#include "Simple_window.h"
#include "Graph.h"
#include <FL/Fl_Browser.H>
#include <FL/Fl_Browser_.H>

struct Scrollbox: public Widget
{
public:
	Scrollbox(const Point &topLeft, int w, int h, const std::string &label, Graph_lib::Callback cb);
	void attach(Window&);
	void add(const char* s, void * v = 0) 
	{
		((Fl_Browser*)pw)->add(s, v);
	}
	void clear()
	{
		((Fl_Browser*)pw)->clear();
	}
};

#endif