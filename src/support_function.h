#ifndef SUPPORT_FUNCTION_H
#define SUPPORT_FUNCTION_H

#include <winbgim.h> 
#include <conio.h>

#include "Line.h"
#include "Pencil.h"
#include "Pixel.h"
#include "Rectang.h"
#include "Painter.h"
#include "Const.h"
#include "Text.h"
#include "Table.h"
#include "Music.h"
#include "Mouse.h"
#include "Image.h"
#include "YesNoRectang.h"



void user_input(Pixel& click, Pixel& cur_mouse)
{
	click.mouse_click();
	cur_mouse.cur_mouse_pos();
}


void hide_right_line(Rectang& rectang)
{
	line(250, 0, 250, getmaxy());
	Pencil::set_thickness(3);
	Pencil::set_color(LIGHTGRAY);
	line(rectang.x2, rectang.y1+2, rectang.x2, rectang.y2-2);
	Pencil::set_color(BLACK);
}



void process_menu(Rectang rectangs[], Text text_menu[], Pixel& mouse_click_pixel)
{
	int len = 5;
	
	for(int i=0; i < len; i++)
	{
		if(mouse_click_pixel.is_in(rectangs[i]))
		{
			Music::play("sound/tingting");
			
			for(int k=0; k<len; k++)
				rectangs[k].draw();
			
			rectangs[i].draw_color(CYAN);
			hide_right_line(rectangs[i]);
			text_menu[i].click_blink(random(getmaxcolor()));
			
			
			bar(280, 50, 1060, 600);
			Painter::set_color_will_fill(random(getmaxcolor()));
			bar(280, 50, 1060, 600);
		}
			
	}
}








#endif
