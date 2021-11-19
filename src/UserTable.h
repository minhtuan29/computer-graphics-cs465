#ifndef USERTABLE_H
#define USERTABLE_H




#define ROUND(a) (int)(a+0.5)
#define Round(a) (int)(a+0.5)


#include "program_store.h"

#include <vector>
#include <math.h>
#define COS(x) cos(x * 3.141592653589 / 180)
#define SIN(x) sin(x * 3.141592653589 / 180)
#include "Shape.h"
#include "Painter.h"


class UserTable{
	
public:
	
	static int COL; // 211
	static int ROW; // 125
	static int DTX; // 300
	static int DTY; // 100
	
private:
	
	
	void put_to_table(int x, int y, int color)
	{
		Painter::set_color_will_fill(color);
		bar(301+6*x,101+6*y, 306+6*x,106+6*y);
	}
	

	
public:
	
	static void make_change_ratote(int& user_x, int& user_y, double alpha)
	{
		 
		int x = user_x;
		int y = user_y;
		user_x = x*COS(alpha) - y*SIN(alpha);
		user_y = x*SIN(alpha) + y*COS(alpha);
		
		if(user_x < 0 && abs(user_x) < 12)
			user_x--;
		if(user_x > 0 && abs(user_x) < 12)
			user_x++;	
	}
	
	
	
	UserTable()
	{
		Pencil::set_color(LIGHTGRAY);
		
		for (int i = 0; i < COL+1; i++)
			line(DTX+6*i, DTY, DTX+6*i, DTY+6*ROW);
		
		for(int i = 0; i < ROW+1; i++)
			line(DTX, DTY+6*i, DTX+6*COL, DTY+6*i);
	
		
		Pencil::set_color(RED);
		
		line(DTX+3*(COL-1), DTY, DTX+3*(COL-1), DTY+6*ROW );
		line(DTX+3*(COL-1)+6, DTY, DTX+3*(COL-1)+6, DTY+6*ROW );
		
		line(DTX, DTY+3*(ROW-1), DTX+6*COL, DTY+3*(ROW-1));
		line(DTX, DTY+3*(ROW-1)+6, DTX+6*COL, DTY+3*(ROW-1)+6);
	}
	
	
	
	void draw_shape(Shape* shape, int color)
	{
		int SZ = shape->point_list.size();
		for(int i = 0; i < SZ; i++)
			this->put_to_table(shape->point_list.at(i).x, shape->point_list.at(i).y, color);

	}
	
	
	void clear_shape(Shape* shape)
	{
		int SZ = shape->point_list.size();
		for(int i = 0; i < SZ; i++)
			this->put_to_table(shape->point_list.at(i).x, shape->point_list.at(i).y, WHITE);
	}

};

int UserTable::COL = 211;
int UserTable::ROW = 125;
int UserTable::DTX = 300;
int UserTable::DTY = 100;



#endif
