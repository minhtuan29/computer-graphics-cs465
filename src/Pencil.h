#ifndef PENCIL_H
#define PENCIL_H


#include <winbgim.h>

class Pencil{
public:
	
	static void set_color(int n)
	{	
		setcolor(n);
	}
	
	static int get_color()
	{
		return getcolor();
	}
	
	static void set_thickness(int n)
	{
		setlinestyle(0, 0, n);
	}
	
	static void override_color_mode()
	{
		setwritemode(0);
	}
	
	static void override_mix_color_mode()
	{
		setwritemode(1);
	}
	
	static void erase_area(int x, int y)
	{
		outtextxy(x, y, "       ");
	}
};

#endif
