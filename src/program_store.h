
#ifndef PROGRAM_STORE_H
#define PROGRAM_STORE_H

#include "support_function.h"
#include "Text.h"




//void your_program()
//{
// 	setbkcolor(int color);
//  cleardevice();
//	... your code here....
//}



Text login()
{
	setbkcolor(LIGHTGRAY);
	cleardevice();
	
	Pixel mouse_click_pixel;
	Pixel mouse_cur_pos;
	
	
	Pencil::set_color(BLACK);
	Pencil::set_thickness(3);
		
	Rectang id_rectang(300, 300, 700, 350, 2);
	id_rectang.draw();
	Rectang password_rectang(300, 370, 700, 420, 2);
	password_rectang.draw();
	Rectang playmusic_rectang(10, 10, 240, 60, 5);
	playmusic_rectang.draw();


	Text  playmusic_text("play music"); // HEAP HEAP HEAP HEAP HEAP HEAP
	playmusic_text.set_style(6, 4);
	playmusic_text.set_xy(playmusic_rectang.x1 + 10, playmusic_rectang.y1 + 10);
	playmusic_text.draw();
	
	
	// way 1: while !kbhit + not delay
	// way 2: while (true) + delay(1) : like gaming : it is beter input but lower performance
	while (true) // while user doesn't take input keyboard, let program auto run
	{
		user_input(mouse_click_pixel, mouse_cur_pos);
		

		if(mouse_click_pixel.is_in(id_rectang))
		{	
			Text id; // default constructor in C++ doesnt need "()"
			Text::SETSTYLE(6, 2);
			Pencil::set_color(BLACK);
			id.cin_at(id_rectang.x1 + 10, id_rectang.y1 + 10);  // HEAP HEAP HEAP HEAP HEAP
			
			id_rectang.draw();
			
			Pencil::set_color(BLUE);
			password_rectang.draw();
			
			
			Text password; // HEAP HEAP HEAP HEAP
			Pencil::set_color(BLACK);
			password.cin_at(password_rectang.x1 + 10, password_rectang.y1 + 10, Text::IS_PASSWORD);
			Music::stop_play();
			
			// delete heap before exiting function:  DEL password->char_ptr, DEL playmusic_text->char_ptr
			password.free_data();
			playmusic_text.free_data();
			return id; // break the loop and go to next program
			// my operator= , it ref to id data, not shallow copy
		}
		else
		if(mouse_click_pixel.is_in(playmusic_rectang))
		{
			Music::play("sound/baihat1.wav");
			playmusic_rectang.click_blink(LIGHTBLUE);
		}
		
		
		if(mouse_cur_pos.is_in(id_rectang))
		{
			id_rectang.light_by_mouse_pos(BLUE);
		}
		else if(mouse_cur_pos.is_in(playmusic_rectang))
		{
			playmusic_text.light_by_mouse_pos(LIGHTCYAN);
		}
		else
		{
			Pencil::set_color(BLACK);
			id_rectang.draw();
			playmusic_text.draw();
		}
		
		
		delay(1);
	}
}




void access(Text& id)
{
	cleardevice();
	
	Pixel  mouse_click_pixel;
	Pixel  mouse_cur_pos;
	
	YesNoRectang yes_no_rectang(getmaxx()/2.5, getmaxy()/3, getmaxx()/2.5+300, getmaxy()/2.5+200);
	Rectang back_rectang(5, 5, 30, 30);
	back_rectang.draw();
	
	id.set_style(10, 1);
	id.set_xy(150, 90);
	Text::SETSTYLE(10,1);
	outtextxy(65, 90, "welcome");
	id.draw();
	
	int THICKNESS = 3;
	int N_MENU    = 5;
	
	
	Pencil::set_thickness(THICKNESS);
	line(250, 0, 250, getmaxy());
	
	Rectang rectangs_menu[N_MENU];
	for(int i=0; i<N_MENU; i++)
	{
		rectangs_menu[i].set(10, 150+60*i, 250, 200+60*i, THICKNESS);
		rectangs_menu[i].draw();
	}
	
	Pencil::set_color(LIGHTGRAY);
	line(rectangs_menu[0].x2, rectangs_menu[0].y1+2, rectangs_menu[0].x2, rectangs_menu[0].y2-2);
	Pencil::set_color(BLACK);
	
	int widths[] = {60, 260, 150, 150, 60, 60};
	Table table(9,6,  290,80,  50,  widths,  1);
	table.draw(); 
	
	Pencil::set_thickness(THICKNESS);
	
	Text text_menu[] = {Text("Market"), Text("Shopping"), Text("Books"), Text("Travel"), Text("TOTAL")};
	for(int i=0; i<N_MENU; i++)
	{
		text_menu[i].set_style(10, 3);
		text_menu[i].draw_at(rectangs_menu[i]);
	}
	Image old_frame(0, 0, getmaxx(), getmaxy() );
	
	//-------------- PROCESS ----------------//
	while(true)
	{	
		user_input(mouse_click_pixel, mouse_cur_pos);
		
		process_menu(rectangs_menu, text_menu, mouse_click_pixel);
		
		if (mouse_click_pixel.is_in(back_rectang))
		{
			old_frame.take_photo();
			yes_no_rectang.draw();
		}
		
		
		if (mouse_click_pixel.is_in(yes_no_rectang.no_rectang))
		{
			old_frame.draw(0, 0);
		}
		
		
		delay(1);
	}
	
}

#endif

