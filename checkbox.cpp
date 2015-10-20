#include "checkbox.h"

Checkbox::Checkbox(const Point &p, int w, int h, const std::string &l, Graph_lib::Callback cb)
	:Widget(p, w, h, l, cb)
{
}

void Checkbox::attach(Window &win)
{
	pw = new Fl_Check_Button(loc.x, loc.y, width, height, label.c_str());
	own = &win;
}