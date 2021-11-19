#ifndef YESNORECTANG_H
#define YESNORECTANG_H

#include "Rectang.h"


class YesNoRectang : public Rectang
{	
	
public:
	
	Rectang*   yes_rectang;
	Rectang*   no_rectang;
	
	YesNoRectang(int x1 , int y1, int x2 , int y2) 
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
		this->yes_rectang = new Rectang(x1+40, y2-50, x1+100, y2-20);
		this->no_rectang = new Rectang(x2-100, y2-50, x2-40, y2-20);
	}
	
	virtual void draw()
	{
		Painter::set_color_will_fill(DARKGRAY);
		this->draw_and_fill();
		this->yes_rectang->draw();
		this->no_rectang->draw();
	}
};






#endif
