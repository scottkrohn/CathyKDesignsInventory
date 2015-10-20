#ifndef ALERT_WIN_GUARD
#define ALERT_WIN_GUARD

#include <string>
#include "Simple_window.h"
#include "Graph.h"

class Alert_win: public Window
{
public:
	Alert_win(Point top_left, int width, int height, const std::string &title,
			  const std::string &msg);
private:
	Text alert_msg;
	Button ok_button;

	static void cb_ok(void *, void *);

	void ok();
};

#endif
