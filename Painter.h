
#ifndef PAINTER_H
#define PAINTER_H

#include <winbgim.h> 


class Painter{
public:
	
	static void set_color_will_fill(int color, int mode =1)
	{
		setfillstyle(mode, color);
	}
	
	static void fill_by_lookfor(int x, int y, int color)
	{
		floodfill(x, y, color);
	}
	
	static void fill_background(int n)
	{
		setbkcolor(n);
		cleardevice();
	}
};


#endif 
