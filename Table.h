#ifndef TABLE_H
#define TABLE_H

#include <winbgim.h>

class Table{
private:
	
	int  n_row;
	int  n_col;
	int  x;
	int  y;
	
	int  height_per_row;
	
	int* width_of_cells;
	int  width_total;
	
	int  thickness;
	
public:
	
	Table(int n_row, int n_col, int x, int y, int height_per_row, int width_of_cells[], int thickness)
	{
		this->n_row = n_row;
		this->n_col = n_col;
		this->x = x;
		this->y = y;
		this->height_per_row = height_per_row;
		this->width_of_cells = width_of_cells;
		
		this->width_total = 0;
		for(int i=0; i< this->n_col; i++)
			this->width_total += width_of_cells[i];
			
		this->thickness = thickness;
	}
	
	
	void draw()
	{
		Pencil::set_thickness(this->thickness);
		int cur_y = this->y;
		for(int i=0; i <= this->n_row; i++)
		{	
			line(x, cur_y, x+width_total, cur_y);
			cur_y += this->height_per_row;	
		} 	
		cur_y -= this->height_per_row;
		
		int cur_x = this->x;
		for(int i=0; i <= this->n_col; i++)
		{	line(cur_x, this->y, cur_x, cur_y);
			cur_x += this->width_of_cells[i];	
		}
	}
};


#endif
