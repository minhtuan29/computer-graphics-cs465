#ifndef FLASHLIGHT_H
#define FLASHLIGHT_H

#include <winbgim.h>
#include "Pencil.h"
#include "Const.h"

class FlashLight{  // Abstract Base Class
public:
	virtual void draw() 
	{
		// override
	}
	
	virtual void click_blink(int color)
	{
		Pencil::set_color(color);
		this->draw();
		delay(150); // milisecond
		Pencil::set_color(BLACK);
		this->draw();
	}
	
	virtual void light_by_mouse_pos(int color)
	{
		Pencil::set_color(color);
		this->draw();
	}
};

#endif
