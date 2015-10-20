#include "Alert_win.h"

/********** ERROR_WIN DEFINITIONS ***********/
Alert_win::Alert_win(Point top_left, int width, int height, const std::string &title, 
					 const std::string &msg)
	:Window(top_left, width, height, title),
	alert_msg(Point(10, height/4), msg),
	ok_button(Point(width/2-50, height-50), 100, 25, "OK", cb_ok)
{
	attach(alert_msg);
	attach(ok_button);
}

void Alert_win::cb_ok(void *, void *win)
{
	((Alert_win*)win)->ok();
}

void Alert_win::ok()
{
	hide();
}

