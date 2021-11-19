#ifndef PIXEL_H
#define PIXEL_H

#include <winbgim.h>
#include "Rectang.h"

#include <iostream>
class Pixel{
	
public:
	
	int x;
	int y;
	
	Pixel(int x = -1, int y = -1)
	{
		this->x = x;
		this->y = y;
	}
	
	virtual void mouse_click()
	{
		getmouseclick(WM_LBUTTONDOWN, x, y);
	}
	
	virtual void cur_mouse_pos()
	{
		x = mousex();
		y = mousey();
	}
	
	virtual bool is_in(Rectang rectang)
	{
		return(  x >= rectang.x1
		      && x <= rectang.x2
		      && y >= rectang.y1    
			  && y <= rectang.y2 );
	}
	
	virtual bool is_in(Rectang* rectang)
	{
		return(  x > rectang->x1
		      && x <= rectang->x2
		      && y > rectang->y1    
			  && y <= rectang->y2 );
	}
	
		

	
	
	
	virtual int get_color()
	{
		return getpixel(x, y);
	}
	
	virtual void draw(int color)
	{
		putpixel(x, y, color);
	}
	
	
	static inline void update_curpoint(int x, int y)
	{
		moveto(x, y);
	}
};

#endif
