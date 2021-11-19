#ifndef LINE_H
#define LINE_H

#include <winbgim.h>
#include "Pencil.h"
#include "Const.h"

class Line{
	
public:
	int x1;
	int y1;
	int x2;
	int y2;
	int thickness;
	
	Line(int x1, int y1, int x2, int y2, int thickness)
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}
	
	virtual void draw()
	{
		Pencil::set_thickness(this->thickness);
		line(x1, y1, x2, y2);
	}
	
	virtual void erase()
	{
		Pencil::set_color(getbkcolor());
		line(x1, y1, x2, y2);
		Pencil::set_color(BLACK);
	}

	
	static void draw_update_curpoint_to(int x, int y)
	{
		lineto(x, y);
	}
	
	static void draw_update_curpoint_by_delta(int delta_x, int delta_y)
	{
		linerel(delta_x, delta_y);
	}
	
	
	
};

#endif

