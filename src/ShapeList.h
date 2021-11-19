#ifndef SHAPELIST_H
#define SHAPELIST_H
#include "Shape.h"



class Triangle : public Shape{
	
	
public:
	
	int arr[3][2];
	
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
	{
		arr[0][0] = x1;
		arr[0][1] = y1;
		arr[1][0] = x2;
		arr[1][1] = y2;
		arr[2][0] = x3; 
		arr[2][1] = y3;
		
		this->add_line(arr[0][0], arr[0][1], arr[1][0], arr[1][1] );
		this->add_line(arr[1][0], arr[1][1], arr[2][0], arr[2][1] );
		this->add_line(arr[2][0], arr[2][1], arr[0][0], arr[0][1] );
	}
	
	
	void rotate(int xc, int yc, double alpha)
	{
		for(int i = 0; i < 3; i++)
		{
			int x_sh = arr[i][0] - xc;
			int y_sh = arr[i][1] - yc;
			
			arr[i][0] = xc   +  x_sh * COS(alpha) - y_sh * SIN(alpha);
        	arr[i][1] = yc   +  x_sh * SIN(alpha) + y_sh * COS(alpha);
		}
		
		this->point_list.clear();
		this->add_line(arr[0][0], arr[0][1], arr[1][0], arr[1][1] );
		this->add_line(arr[1][0], arr[1][1], arr[2][0], arr[2][1] );
		this->add_line(arr[2][0], arr[2][1], arr[0][0], arr[0][1] );
	}
	
};








class Ship : public Shape{
public:
		int head_x;
		int head_y;
		int tail_x;
		int tail_y;
		bool is_moving_right;
		
public:
		
		Ship(){
			
			this->add_line(20, 10+5, 50, 10+5);
			this->add_line(15, 19+5, 55, 25+5);
			tail_x = 15, tail_y = 24;
			head_x = 55; head_y = 30;
			this->add_line(20, 10+5, 15, 19+5);
			this->add_line(50, 10+5, 55, 24+5);
			this->add_line(35, 21+5, 35, 49+5);
			this->add_line(35, 49+5, 45, 27+5);
			this->add_line(45, 27+5, 35, 27+5);
			is_moving_right = true;
		}
		
		
		
		void change_move()
		{
			if(this->is_moving_right)
				is_moving_right = false;
			else
				is_moving_right = true;
		}			
};



class Watch : public Shape{
public:
		int head_x;
		int head_y;
};




class Fish : public Shape
{
private:

	int half_len_body;
	int size;
	
public:
	
	bool is_having_wing;
	int center_x;
	int center_y;

		
	Fish(int center_x, int center_y, int size, bool is_having_wing= true)
	{
		this->center_x = center_x;
		this->center_y = center_y;
		this->half_len_body = 8*size;
		this->size = size;
		this->add_elip(center_x, center_y, half_len_body, half_len_body/2);
		this->add_triangle      (center_x-half_len_body, center_y, 
		             center_x - half_len_body-  half_len_body/2,  center_y + half_len_body/2  ,
					  center_x - half_len_body- half_len_body/2,  center_y - half_len_body/2 );
		
		if(is_having_wing)
			this->add_triangle(center_x+2*size, center_y, center_x-2*size, center_y, center_x-4*size, center_y-2*size );
		else
			this->add_line(center_x+2*size, center_y, center_x-2*size, center_y );
			
		this->add_line(center_x+4*size, center_y+2*size, center_x+6*size, center_y+size);
		this->is_having_wing = true;
	}
	
	
	
	void change_having_wing_status()
	{
		if (this->is_having_wing)
			is_having_wing = false;
		else
			is_having_wing = true;
	}
	
	
	Fish* get_him_in_not_wing()
	{
		return new Fish(this->center_x, this->center_y, this->size, false);
	}
	
	
	void up_size()
	{
		if(size == 7)
			return;
		this->size++;
		this->half_len_body = 8*size;
		this->point_list.clear();
		this->add_elip(center_x, center_y, half_len_body, half_len_body/2);
		this->add_triangle      (center_x-half_len_body, center_y, 
		             center_x - half_len_body-  half_len_body/2,  center_y + half_len_body/2  ,
					  center_x - half_len_body- half_len_body/2,  center_y - half_len_body/2 );
		this->add_triangle     (center_x+2*size, center_y, center_x-2*size, center_y, center_x-4*size, center_y-2*size );
		this->add_line(center_x+4*size, center_y+2*size, center_x+6*size, center_y+size);
	}
	
	
	void down_size()
	{
		if(size==1)
			return;
		this->size--;
		this->half_len_body = 8*size;
		this->point_list.clear();
		this->add_elip(center_x, center_y, half_len_body, half_len_body/2);
		this->add_triangle      (center_x-half_len_body, center_y, 
		             center_x - half_len_body-  half_len_body/2,  center_y + half_len_body/2  ,
					  center_x - half_len_body- half_len_body/2,  center_y - half_len_body/2 );
		this->add_triangle     (center_x+2*size, center_y, center_x-2*size, center_y, center_x-4*size, center_y-2*size );
		this->add_line(center_x+4*size, center_y+2*size, center_x+6*size, center_y+size);
	}
};



#endif
