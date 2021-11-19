#ifndef CONST_H
#define CONST_H

#include <winbgim.h> 



bool user_hasnt_pressed_any_key()
{
	return !kbhit();
}
 
char GET_KEYBOARD_KEY()
{
	return getch();
}  


int num_form(char c)
{
	return c-'0'; // tra ma~ SoThuTu trong ASCII
} 



#define LEFT_CLICK WM_LBUTTONDOWN
#define RIGHT_CLICK WM_RBUTTONDOWN
#define MOUSE_MOVE WM_MOUSEMOVE

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15


#define LEFT 0
#define RIGHT 2

#define MID 1

#define BOTTOM 1
#define TOP 2

#define ENTER_KEY 13
#define BACKSPACE_KEY 8
#define SPACE_KEY 32

#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77


#endif
