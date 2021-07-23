#ifndef SHAPE_H
#define SHAPE_H

#include <winbgim.h>
#include "Pencil.h"
#include "Const.h"


#define ROUND(a) (int)(a+0.5)
#define Round(a) (int)(a+0.5)

#include "program_store.h"

#include <vector>
#include <math.h>
#define COS(x) cos(x * 3.141592653589 / 180)
#define SIN(x) sin(x * 3.141592653589 / 180)







class Shape
{

private:
	
	
	void add4(int xc, int yc, int x, int y)
	{
		this->add_pixel(xc+x, yc+y);
	    this->add_pixel(xc-x, yc+y);
	    this->add_pixel(xc+x, yc-y);
	    this->add_pixel(xc-x, yc-y);
	}
	
	
	
	void add8(int xc, int yc, int x, int y)
	{
	    this->add_pixel(x + xc, y + yc);
	    this->add_pixel(-x + xc, y + yc);
	    this->add_pixel(x + xc, -y + yc);
	    this->add_pixel(-x + xc, -y + yc);
	    this->add_pixel( y + xc, x + yc);
	    this->add_pixel(-y + xc, x + yc);
	    this->add_pixel(y + xc, -x + yc);
	    this->add_pixel(-y + xc, -x + yc);
	}
	
	
	void lineDDA_net_dut(int x1, int y1, int x2, int y2) {
		int count = 1;
	  if (x1 == x2) {
	    int i;
	    if (y1 < y2)
	      for (i = y1; i <= y2; i++) {
	        Point p(x1, i);
	        count++; if(count %4 == 0 || (count+1)%4 == 0 )
	        point_list.push_back(p);
	      }
	    else
	      for (i = y2; i <= y1; i++) {
	        Point p(x1, i); 
			count++; if(count %4 == 0 || (count+1)%4 == 0 )
	        point_list.push_back(p);
	      }
	  }
	  if (y1 == y2) {
	    int i;
	    if (x1 < x2)
	      for (i = x1; i <= x2; i++) {
	        Point p(i, y1);
	        count++; if(count %4 == 0 || (count+1)%4 == 0 )
	        point_list.push_back(p);
	      }
	    else
	      for (i = x2; i <= x1; i++) {
	        Point p(i, y1);
	        count++; if(count %4 == 0 || (count+1)%4 == 0 )
	        point_list.push_back(p);
	      }
	  }
	  if (x1 < x2) {
	    if (y1 < y2) {
	      if ((y2 - y1) / (x2 - x1) < 1) {
	        int i;
	        int Dx = x2 - x1;
	        int Dy = y2 - y1;
	        int p = 2 * Dy - Dx;
	        Point p2(x1, y1);
	        count++; if(count %4 == 0 || (count+1)%4 == 0 )
	        point_list.push_back(p2);
	        for (i = x1; i < x2; i++) {
	          if (p < 0)
	            p += 2 * Dy;
	          else {
	            p += 2 * (Dy - Dx);
	            y1++;
	          }
	          x1++;
	          Point p(x1, y1);
	          count++; if(count %4 == 0 || (count+1)%4 == 0 )
	          point_list.push_back(p);
	
	        }
	      } else {
	        int i;
	        int Dx = x2 - x1;
	        int Dy = y2 - y1;
	        int p = 2 * Dx - Dy;
	        Point p3(x1, y1);
	        count++; if(count %4 == 0 || (count+1)%4 == 0 )
	        point_list.push_back(p3);
	        for (i = y1; i < y2; i++) {
	          if (p < 0)
	            p += 2 * Dx;
	          else {
	            p += 2 * (Dx - Dy);
	            x1++;
	          }
	          y1++;
	          Point p(x1, y1);
	          count++; if(count %4 == 0 || (count+1)%4 == 0 )
	          point_list.push_back(p);
	        }
	      }
	    }
	    if (y1 > y2) {
	      if ((y2 - y1) / (x2 - x1) > -1) {
	        int i;
	        int Dx = x2 - x1;
	        int Dy = y2 - y1;
	        int p = 2 * Dy + Dx;
	        Point p4(x1, y1);
	        count++; if(count %4 == 0 || (count+1)%4 == 0 )
	        point_list.push_back(p4);
	        for (i = x1; i <= x2; i++) {
	          if (p > 0)
	            p += 2 * Dy;
	          else {
	            p += 2 * (Dy + Dx);
	            y1--;
	          }
	          x1++;
	          Point p(x1, y1);
	          count++; if(count %4 == 0 || (count+1)%4 == 0 )
	          point_list.push_back(p);
	        }
	      } else {
	        int i;
	        int Dx = x2 - x1;
	        int Dy = y2 - y1;
	        int p = 2 * Dx + Dy;
	
	        Point p5(x1, y1);
	        count++; if(count %4 == 0 || (count+1)%4 == 0 )
	        point_list.push_back(p5);
	        for (i = y1; i >= y2; i--) {
	          if (p < 0)
	            p += 2 * Dx;
	          else {
	            p += 2 * (Dx + Dy);
	            x1++;
	          }
	          y1--;
	          Point p(x1, y1);
	          count++; if(count %4 == 0 || (count+1)%4 == 0 )
	          point_list.push_back(p);
	        }
	      }
	    }
	  }
	  if (x1 > x2) {
	    if (y1 < y2) {
	      	if ((y2 - y1) / (x2 - x1) > -1) {
	        	int i;
		        int Dx = x2 - x1;
		        int Dy = y2 - y1;
		        int p = -2 * Dy - Dx;
		        Point p6(x1, y1);
		        count++; if(count %4 == 0 || (count+1)%4 == 0 )
		        point_list.push_back(p6);
		        for (i = x1; i > x2; i--) {
		          if (p < 0) {
		            p = p - 2 * Dy - 2 * Dx;
		            y1++;
		          } else
		            p = p - 2 * Dy;
		          x1--;
		          Point p(x1, y1);
		          count++; if(count %4 == 0 || (count+1)%4 == 0 )
		          point_list.push_back(p);
		        }
		      } else {
		        int i;
		        int Dx = x2 - x1;
		        int Dy = y2 - y1;
		        int p = -2 * Dx - Dy;
		        Point p7(x1, y1);
		        point_list.push_back(p7);
		        for (i = y1; i < y2; i++) {
		          if (p < 0)
		            p -= 2 * Dx;
		
		          else {
		            p -= 2 * (Dx + Dy);
		            x1--;
		          }
		          y1++;
		          Point p(x1, y1);
		          count++; if(count %4 == 0 || (count+1)%4 == 0 )
		          point_list.push_back(p);
		        }
		      }
		    }
		    if (y1 > y2) {
		      if ((y2 - y1) / (x2 - x1) < 1) {
		        int i;
		        int Dx = x2 - x1;
		        int Dy = y2 - y1;
		        int p = 2 * Dy - Dx;
		        Point p8(x1, y1);
		        count++; if(count %4 == 0 || (count+1)%4 == 0 )
		        point_list.push_back(p8);
		        for (i = x1; i > x2; i--) {
		          if (p > 0) {
		            p = p - 2 * Dy + 2 * Dx;
		            y1--;
		          } else
		            p -= 2 * Dy;
		          x1--;
		          Point p(x1, y1);
		          count++; if(count %4 == 0 || (count+1)%4 == 0 )
		          point_list.push_back(p);
		        }
		      } else {
		        int i;
		        int Dx = x1 - x2;
		        int Dy = y1 - y2;
		        int p = 2 * Dx + Dy;
		        Point p9(x1, y1);
		        count++; if(count %4 == 0 || (count+1)%4 == 0 )
		        point_list.push_back(p9);
		        for (i = y1; i > y2; i--) {
		          if (p < 0) {
		            p = p - 2 * Dx + 2 * Dy;
		            x1--;
		          } else
		
		            p = p - 2 * Dx;
		          y1--;
		          Point p(x1, y1);
		          count++; if(count %4 == 0 || (count+1)%4 == 0 )
		          point_list.push_back(p);
		        }
		      }
	    	}
		}
	}
	
	
	
	
	void lineDDA(int x1, int y1, int x2, int y2) {
	  if (x1 == x2) {
	    int i;
	    if (y1 < y2)
	      for (i = y1; i <= y2; i++) {
	        Point p(x1, i);
	        point_list.push_back(p);
	      }
	    else
	      for (i = y2; i <= y1; i++) {
	        Point p(x1, i);
	        point_list.push_back(p);
	      }
	  }
	  if (y1 == y2) {
	    int i;
	    if (x1 < x2)
	      for (i = x1; i <= x2; i++) {
	        Point p(i, y1);
	        point_list.push_back(p);
	      }
	    else
	      for (i = x2; i <= x1; i++) {
	        Point p(i, y1);
	        point_list.push_back(p);
	      }
	  }
	  if (x1 < x2) {
	    if (y1 < y2) {
	      if ((y2 - y1) / (x2 - x1) < 1) {
	        int i;
	        int Dx = x2 - x1;
	        int Dy = y2 - y1;
	        int p = 2 * Dy - Dx;
	        Point p2(x1, y1);
	        point_list.push_back(p2);
	        for (i = x1; i < x2; i++) {
	          if (p < 0)
	            p += 2 * Dy;
	          else {
	            p += 2 * (Dy - Dx);
	            y1++;
	          }
	          x1++;
	          Point p(x1, y1);
	          point_list.push_back(p);
	
	        }
	      } else {
	        int i;
	        int Dx = x2 - x1;
	        int Dy = y2 - y1;
	        int p = 2 * Dx - Dy;
	        Point p3(x1, y1);
	        point_list.push_back(p3);
	        for (i = y1; i < y2; i++) {
	          if (p < 0)
	            p += 2 * Dx;
	          else {
	            p += 2 * (Dx - Dy);
	            x1++;
	          }
	          y1++;
	          Point p(x1, y1);
	          point_list.push_back(p);
	        }
	      }
	    }
	    if (y1 > y2) {
	      if ((y2 - y1) / (x2 - x1) > -1) {
	        int i;
	        int Dx = x2 - x1;
	        int Dy = y2 - y1;
	        int p = 2 * Dy + Dx;
	        Point p4(x1, y1);
	        point_list.push_back(p4);
	        for (i = x1; i <= x2; i++) {
	          if (p > 0)
	            p += 2 * Dy;
	          else {
	            p += 2 * (Dy + Dx);
	            y1--;
	          }
	          x1++;
	          Point p(x1, y1);
	          point_list.push_back(p);
	        }
	      } else {
	        int i;
	        int Dx = x2 - x1;
	        int Dy = y2 - y1;
	        int p = 2 * Dx + Dy;
	
	        Point p5(x1, y1);
	        point_list.push_back(p5);
	        for (i = y1; i >= y2; i--) {
	          if (p < 0)
	            p += 2 * Dx;
	          else {
	            p += 2 * (Dx + Dy);
	            x1++;
	          }
	          y1--;
	          Point p(x1, y1);
	          point_list.push_back(p);
	        }
	      }
	    }
	  }
	  if (x1 > x2) {
	    if (y1 < y2) {
	      	if ((y2 - y1) / (x2 - x1) > -1) {
	        	int i;
		        int Dx = x2 - x1;
		        int Dy = y2 - y1;
		        int p = -2 * Dy - Dx;
		        Point p6(x1, y1);
		        point_list.push_back(p6);
		        for (i = x1; i > x2; i--) {
		          if (p < 0) {
		            p = p - 2 * Dy - 2 * Dx;
		            y1++;
		          } else
		            p = p - 2 * Dy;
		          x1--;
		          Point p(x1, y1);
		          point_list.push_back(p);
		        }
		      } else {
		        int i;
		        int Dx = x2 - x1;
		        int Dy = y2 - y1;
		        int p = -2 * Dx - Dy;
		        Point p7(x1, y1);
		        point_list.push_back(p7);
		        for (i = y1; i < y2; i++) {
		          if (p < 0)
		            p -= 2 * Dx;
		
		          else {
		            p -= 2 * (Dx + Dy);
		            x1--;
		          }
		          y1++;
		          Point p(x1, y1);
		          point_list.push_back(p);
		        }
		      }
		    }
		    if (y1 > y2) {
		      if ((y2 - y1) / (x2 - x1) < 1) {
		        int i;
		        int Dx = x2 - x1;
		        int Dy = y2 - y1;
		        int p = 2 * Dy - Dx;
		        Point p8(x1, y1);
		        point_list.push_back(p8);
		        for (i = x1; i > x2; i--) {
		          if (p > 0) {
		            p = p - 2 * Dy + 2 * Dx;
		            y1--;
		          } else
		            p -= 2 * Dy;
		          x1--;
		          Point p(x1, y1);
		          point_list.push_back(p);
		        }
		      } else {
		        int i;
		        int Dx = x1 - x2;
		        int Dy = y1 - y2;
		        int p = 2 * Dx + Dy;
		        Point p9(x1, y1);
		        point_list.push_back(p9);
		        for (i = y1; i > y2; i--) {
		          if (p < 0) {
		            p = p - 2 * Dx + 2 * Dy;
		            x1--;
		          } else
		
		            p = p - 2 * Dx;
		          y1--;
		          Point p(x1, y1);
		          point_list.push_back(p);
		        }
		      }
	    	}
		}
	}



public:	
	class Point{
		public:
			
			int x;
			int y;
			
			Point() {}
			
			Point(int x, int y)
			{
				this->x = x;
				this->y = y;
			}
	};
	
	
	std::vector<Point>  point_list;  
	

	void add_pixel(int user_x, int user_y)
	{
		Point p(user_x+105, 62- user_y);
		this->point_list.push_back(p);
	}
	
	
	
	Shape* get_symmetry_oy()
	{
		Shape* shape = new Shape;
		int SZ = this->point_list.size();
		
		for(int i = 0; i < SZ; i++)
		{
			Point p(210 - this->point_list.at(i).x, this->point_list.at(i).y);
			shape->point_list.push_back(p);
		}
		return shape;
	}
	
	
	
	Shape* get_symmetry_ox()
	{
		Shape* shape = new Shape;
		int SZ = this->point_list.size();
		
		for(int i = 0; i < SZ; i++)
		{
			Point p(this->point_list.at(i).x, 124 - this->point_list.at(i).y);
			shape->point_list.push_back(p);
		}
		return shape;
	}
	
	
	
	Shape* get_symmetry_oxy()
	{
		Shape* shape = new Shape;
		int SZ = this->point_list.size();
		
		for(int i = 0; i < SZ; i++)
		{
			Point p( 210 - this->point_list.at(i).x, 124 - this->point_list.at(i).y);
			shape->point_list.push_back(p);
		}
		return shape;
	}
	
	
	
	
	void add_line(int user_x1, int user_y1, int user_x2, int user_y2)
	{
		this->lineDDA(user_x1 + 105, 62-user_y1, user_x2 + 105, 62-user_y2);
	}

	void add_line_net_dut(int user_x1, int user_y1, int user_x2, int user_y2)
	{
		this->lineDDA_net_dut(user_x1 + 105, 62-user_y1, user_x2 + 105, 62-user_y2);
	}


	void add_triangle(int x1, int y1, int x2, int y2, int x3, int y3)
	{
		this->add_line(x1, y1, x2,y2 );
		this->add_line(x2, y2, x3, y3 );
		this->add_line(x3, y3, x1, y1 );
	}



	void add_elip(int xc, int yc, int a, int b)
	{
	    int x, y, fx, fy, a2, b2, p;
	    x = 0;
	    y = b;
	    a2 = a*a;
	    b2 = b*b;
	    fx = 0;
	    fy = 2 * a2 * y;
	    add4(xc, yc, x, y);
	    p = ROUND(b2 -(a2*b) + (0.25*a2));
	    while(fx<fy)
	    {
	        x++;
	        fx += 2*b2;
	        if(p<0)
	        {
	            p += b2*(2*x + 3);
	        }
	        else
	        {
	            y--;
	            p += b2*(2*x +3) + a2*(2- 2*y);
	            fy -= 2*a2;
	        }
	        add4(xc, yc, x, y);
	    }
	    p = ROUND(b2*(x +0.5)*(x +0.5) + a2*(y-1)*(y-1) - a2*b2);
	    
	    while(y>0)
	    {
	        y--;
	        fy -= 2*a2;
	        if(p >=0)
	        {
	            p += a2*(3-2*y); 
	        }
	        else
	        {
	            x++;
	            fx += 2*b2;
	            p += b2*(2*x +2) +a2*(3- 2*y);
	        }
	        add4(xc, yc, x, y);
	    }		
	}
	
	
	
	
	void add_circle(int xc, int yc, int r)
	{
	    int x = 0, y = r;
	    int f = 1 - r;
	
	    add8(xc, yc, x, y);
	
	    while (x < y)
	    {
	        if (f < 0) f += (x << 1) + 3;
	        else
	        {
	            y--;
	            f += ((x - y) << 1) + 5;
	        }
	        x++;
	        add8(xc, yc, x, y);
	    }
	}
	
	
	
	void move_up()
	{
		int SZ = this->point_list.size();
		for (int i = 0; i < SZ; i++)
			this->point_list.at(i).y--;
	}
	
	
	
	void move_down()
	{
		int SZ = this->point_list.size();
		for (int i = 0; i < SZ; i++)
			this->point_list.at(i).y++;
	}
	
	
	void move_left()
	{
		int SZ = this->point_list.size();
		for (int i = 0; i < SZ; i++)
			this->point_list.at(i).x--;
	}



	void move_right()
	{
		int SZ = this->point_list.size();
		for (int i = 0; i < SZ; i++)
			this->point_list.at(i).x++;
	}	
	
	
};


#endif
