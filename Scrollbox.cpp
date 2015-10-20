#include "Scrollbox.h"

Scrollbox::Scrollbox(const Point &topLeft, int w, int h, const std::string &label, Graph_lib::Callback cb)
	:Widget(topLeft, w, h, label, cb)
{
}

void Scrollbox::attach(Window &win)
{
	pw = new Fl_Browser(loc.x, loc.y, width, height, label.c_str());
	own = &win;
}

