#ifndef MOUSE_H
#define MOUSE_H

#include <winbgim.h>
#include "Const.h"
#include "Pencil.h"


class Mouse{
public:
	
	static void set_mode(void (program_when)(int, int), int mode)
	{
		registermousehandler(mode, program_when);
	}
	
	static void show_circle(int cur_mouse_x, int cur_mouse_y)
	{
		circle(cur_mouse_x, cur_mouse_y, 20);
		delay(500);
		Pencil::set_color(BLACK);
		circle(cur_mouse_x, cur_mouse_y, 20);
	}
	
};

#endif
