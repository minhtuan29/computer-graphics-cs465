#ifndef TEXT_H
#define TEXT_H


#include <stdio.h>
#include <conio.h>
#include "Const.h"
#include "FlashLight.h"



// text fonts are okay : 6 , 9, 10
// the text need to set xy and style before drawing. 
// Otherwise, it will draw by previous state

class Text : public FlashLight
{	
	static void blink_textpointer(int x, int y)
	{
		while(user_hasnt_pressed_any_key())
		{
			outtextxy(x,y, "|");
			delay(50); // milisecond
			outtextxy(x,y, " ");
			delay(50);
		}
	}
	
	char* m_data;
	int x;
	int y;
	int font;
	int size;
	
public:
	
	
	Text(const char* src)
	{
		m_data = new char[strlen(src)+1];     // 	 HEAP HEAP HEAP HEAP
		strcpy(m_data, src);
	}
	
	

	Text()
	{
		m_data = NULL;
		x = 0;
		y = 0;
		font = 0;
		size = 0;
	}
	
	
	void add(const char* src)
	{
		strcat(m_data, src);
	}
	
	void add(int n)
	{
		char buf[11];
		itoa(n, buf, 10);
		strcat(m_data, buf);
	}
	
	void free_data()
	{
		delete m_data, m_data = NULL;
	}
	
	
	int get_num()
	{
		return atoi(m_data);
	}
	
	
	void operator=(Text& text)
	{
		//shalow coppy
		// sorry I know it is wrong in C++, forgive me
		m_data = text.m_data;
		this->font = text.font;
		this->size = text.size;
	}
	
	
	
	void set_xy(int x, int y) 
	{
		this->x = x;
		this->y = y;
	}
	
	
	void set_style(int font, int size)
	{
		this->font = font;
		this->size = size;
	}


	static void SET_STYLE(int font, int size)
	{
		settextstyle(font, 0, size);
	}
	
	
	virtual void draw()
	{
		settextstyle(font, 0, size);
		outtextxy(x, y, m_data);
	}
	
	
	virtual void draw_at(const Rectang& rectang)
	{
		Pencil::erase_area(rectang.x1+5, rectang.y1+5);
		settextstyle(font, 0, size);
		this->x = (rectang.x1+rectang.x2)/4;
		this->y = rectang.y1+10;
		outtextxy((rectang.x1+rectang.x2)/4, rectang.y1+10, m_data);
	}
	
	
	
	virtual void draw_at(Rectang* rectang)
	{
		Pencil::erase_area(rectang->x1+5, rectang->y1+5);
		settextstyle(font, 0, size);
		this->x = (rectang->x1+rectang->x2)/4;
		this->y = rectang->y1+10;
		outtextxy(x, y, m_data);
	}
	
	
	virtual void cin_at(Rectang rectang, bool is_password = false)
	{
		Pencil::erase_area(rectang.x1+5, rectang.y1+5);
		int cur_x = rectang.x1 + 5;
		int y = rectang.y1 +5;
		int START_X = cur_x;
		m_data = new char[51]; // i choose 51
		char helper[2];
		
		helper[1] = 0;
		
		int i_data = 0;
		while(true)
		{	
			blink_textpointer(cur_x, y);
			helper[0] = GET_KEYBOARD_KEY();
			
			if(helper[0] == ENTER_KEY)
				break;
		
			if(helper[0] == BACKSPACE_KEY)
			{
				char help[2];
				help[0] = m_data[i_data-1];
				help[1] = 0;
				
				if(cur_x > START_X)
				{
					if(is_password)
						cur_x -= textwidth("*");
					else
						cur_x -= textwidth(help); 	
				}
			
				outtextxy(cur_x,y, "   "); // if the charactor is 'm', width is so long
				 						   // tobe safe, we let 3 spaces 
				if( i_data >0)
					i_data -= 1;
					
				continue;
			}
			
			if (is_password)
			{
				outtextxy(cur_x, y, "*");
				cur_x += textwidth("*"); 
			}		
			else
			{
				outtextxy(cur_x, y, helper);
				cur_x += textwidth(helper);
			}
			 
			m_data[i_data] = helper[0];
			i_data += 1; 
			m_data[i_data] = 0;
		}	
	}
	
	
	
	virtual void cin_at(int cur_x, int y, bool is_password = false)
	{
		int START_X = cur_x;
		m_data = new char[51]; // i choose 51
		char helper[2];
		
		helper[1] = 0;
		
		int i_data = 0;
		while(true)
		{	
			blink_textpointer(cur_x, y);
			helper[0] = GET_KEYBOARD_KEY();
			
			if(helper[0] == ENTER_KEY)
				break;
		
			if(helper[0] == BACKSPACE_KEY)
			{
				char help[2];
				help[0] = m_data[i_data-1];
				help[1] = 0;
				
				if(cur_x > START_X)
				{
					if(is_password)
						cur_x -= textwidth("*");
					else
						cur_x -= textwidth(help); 	
				}
			
				outtextxy(cur_x,y, "   "); // if the charactor is 'm', width is so long
				 						   // tobe safe, we let 3 spaces 
				if( i_data >0)
					i_data -= 1;
					
				continue;
			}
			
			if (is_password)
			{
				outtextxy(cur_x, y, "*");
				cur_x += textwidth("*"); 
			}		
			else
			{
				outtextxy(cur_x, y, helper);
				cur_x += textwidth(helper);
			}
			 
			m_data[i_data] = helper[0];
			i_data += 1; 
			m_data[i_data] = 0;
		}	
	}
	
	
	
	static void SETSTYLE(int font, int size)
	{
		settextstyle(font, 0, size);
	}
	
	
	static void draw_at_curpoint(const char* msg)
	{
		outtext(msg);
	}
	
	
	static void set_pos_at_curpoint(int left_right, int top_down)
	{
		settextjustify(left_right, top_down);
	}
	
	
	
	static void draw_num(int x, int y, int n)
	{
		Pencil::erase_area(x, y);
		char buffer[50];
		sprintf(buffer, "%d", n);
		outtextxy(x, y, buffer);
	}
	
	
	static bool IS_PASSWORD; // in C++, class data can not define in itself
};

bool Text::IS_PASSWORD = true;


#endif
