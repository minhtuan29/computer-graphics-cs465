
#include "UserTable.h"
#include "Rectang.h"
#include "ShapeList.h"
using namespace std;



class Point{
public:
	int x;
	int y;
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};



int main()
{
	initwindow(1600, 900);
	
 	Painter::fill_background(WHITE);
 	Pencil::set_color(BLACK);
 	
	Rectang rectang_ship_x1;
	Rectang rectang_ship_y1;
	Rectang rectang_ship_x2;
	Rectang rectang_ship_y2;
	Rectang rectang_watch_x;
	Rectang rectang_watch_y;
	Rectang rectang_fish_x;
	Rectang rectang_fish_y;
	Rectang xy_shape_rectang_group[8];
	Rectang rectang_fish_bigger;
	Rectang rectang_fish_smaller;
	Rectang rectang_show_fish_symm_ox;
	Rectang rectang_show_fish_symm_oy;
	Rectang rectang_show_fish_symm_oxy;
	
	
	Rectang rectang_line_x1(300, 20, 350, 50); 
	rectang_line_x1.draw();
	Rectang rectang_line_y1(360, 20, 410, 50);
	rectang_line_y1.draw();
	Rectang rectang_line_x2(420, 20, 470, 50);
	rectang_line_x2.draw();
	Rectang rectang_line_y2(480, 20, 530, 50);
	rectang_line_y2.draw();
	
	Text line_text("Line");
	line_text.set_style(6,1);
	line_text.draw_at(new Rectang(480, 15, 500, 40));
	
	
	Rectang rectang_3d_d(720, 20, 770, 50); 
	rectang_3d_d.draw();
	Rectang rectang_beginx(720, 60, 770, 90);
	rectang_beginx.draw();
	
	Rectang rectang_3d_r(780, 20, 830, 50);
	rectang_3d_r.draw();
	Rectang rectang_beginy(780, 60, 830, 90);
	rectang_beginy.draw();
	
	Rectang rectang_3d_c(840, 20, 890, 50);
	rectang_3d_c.draw();
	Rectang rectang_beginz(840, 60, 890, 90);
	rectang_beginz.draw();
	
	Text rt3d("Rectangle3D");
	rt3d.set_style(6,1);
	rt3d.draw_at(new Rectang(1100, 15, 1200, 40));
	
	
	
	Rectang rectang_cylinder3d_r(1080, 20, 1130, 50); 
	rectang_cylinder3d_r.draw();
	Rectang rectang_cylinder3d_h(1140, 20, 1190, 50);
	rectang_cylinder3d_h.draw();
	
	Text cy3d("Cylinder3D");
	cy3d.set_style(6,1);
	cy3d.draw_at(new Rectang(1820, 15, 1920, 40));
	
	
	
	Rectang   rectang_elip_x(1300, 20, 1350, 50); 
	Rectang   rectang_elip_y(1360, 20, 1410, 50);
	Rectang   rectang_elip_dtx(1420, 20, 1470, 50);
	Rectang   rectang_elip_dty(1480, 20, 1530, 50);
	rectang_elip_x.draw();
	rectang_elip_y.draw();
	rectang_elip_dtx.draw();
	rectang_elip_dty.draw();
	
	Text el("Elip");
	el.set_style(6,1);
	el.draw_at(new Rectang(2480, 15, 2500, 40));
	
	
	
	int x = 100;
	int y = 30;
	int width = 80;
	int height = 30;
	int distance = 20;
	
	rectang_ship_x1.set(x, y, x + width, y + height, 1);
	xy_shape_rectang_group[0].set(x-120, y, x + width-120, y + height, 1);
	y += height + distance;
	rectang_ship_y1.set(x, y, x + width, y + height, 1);
	xy_shape_rectang_group[1].set(x-120, y, x + width-120, y + height, 1);
	y += height + distance;
	rectang_ship_x2.set(x, y, x + width, y + height, 1);
	xy_shape_rectang_group[2].set(x-120, y, x + width-120, y + height, 1);
	y += height + distance;
	rectang_ship_y2.set(x, y, x + width, y + height, 1);
	xy_shape_rectang_group[3].set(x-120, y, x + width-120, y + height, 1);
	y += height + distance;
	rectang_watch_x.set(x, y, x + width, y + height, 1);
	xy_shape_rectang_group[4].set(x-120, y, x + width-120, y + height, 1);
	y += height + distance;
	rectang_watch_y.set(x, y, x + width, y + height, 1);
	xy_shape_rectang_group[5].set(x-120, y, x + width-120, y + height, 1);
	y += height + distance;
	rectang_fish_x.set(x, y, x + width, y + height, 1);
	xy_shape_rectang_group[6].set(x-120, y, x + width-120, y + height, 1);
	y += height + distance;
	rectang_fish_y.set(x, y, x + width, y + height, 1);	
	xy_shape_rectang_group[7].set(x-120, y, x + width-120, y + height, 1);
	y += height + distance;
	
	rectang_fish_bigger.set(x - 80, y, x + width + 60, y + height + 10, 1);
	y += height + distance;
	rectang_fish_smaller.set(x - 80, y, x + width + 60, y + height + 10, 1);
	y += height + distance;
	rectang_show_fish_symm_ox.set(x - 80, y, x + width + 60, y + height + 10, 1);
	y += height + distance;
	rectang_show_fish_symm_oy.set(x - 80, y, x + width + 60, y + height + 10, 1);
	y += height + distance;
	rectang_show_fish_symm_oxy.set(x - 80, y, x + width + 60, y + height + 10, 1);
	
	int control_width = 60;
	y += height + distance + 20;
	Rectang rectang_up(x, y, x + control_width, y + height, 1);
	y += height + distance;
	Rectang rectang_left(x - 70, y, x - 70 + control_width, y + height, 1);
	
	Rectang rectang_right(x + 70, y, x + 70 + control_width, y + height, 1);
	y += height + distance;
	Rectang rectang_down(x, y, x + control_width, y + height, 1);
	
	rectang_up.draw();
	rectang_left.draw();
	rectang_right.draw();
	rectang_down.draw();
	
	rectang_ship_x1.draw();
	rectang_ship_x2.draw();
	rectang_ship_y1.draw();
	rectang_ship_y2.draw();
	rectang_watch_x.draw();
	rectang_watch_y.draw();
	rectang_fish_x.draw();
	rectang_fish_y.draw();	
	rectang_fish_bigger.draw();
	rectang_fish_smaller.draw();
	rectang_show_fish_symm_ox.draw();
	rectang_show_fish_symm_oy.draw();
	rectang_show_fish_symm_oxy.draw();	
	
	Text a("fish bigger");
	a.set_style(6,1);
	a.draw_at(rectang_fish_bigger);
	
	Text b("fish smaller");
	b.set_style(6,1);
	b.draw_at(rectang_fish_smaller);
	
	Text c("fish symm ox");
	c.set_style(6,1);
	c.draw_at(rectang_show_fish_symm_ox);
	
	Text d("fish symm oy");
	d.set_style(6,1);
	d.draw_at(rectang_show_fish_symm_oy);
	
	Text e("fish symm oxy");
	e.set_style(6,1);
	e.draw_at(rectang_show_fish_symm_oxy);
	
	Text g("ship x1");
	g.set_style(6,1);
	g.draw_at(xy_shape_rectang_group[0]);
	
	Text h("ship y1");
	h.set_style(6,1);
	h.draw_at(xy_shape_rectang_group[1]);
	
	Text i("ship x2");
	i.set_style(6,1);
	i.draw_at(xy_shape_rectang_group[2]);
	
	Text j("ship y2");
	j.set_style(6,1);
	j.draw_at(xy_shape_rectang_group[3]);
	
	Text k("watch x");
	k.set_style(6,1);
	k.draw_at(xy_shape_rectang_group[4]);
	
	Text l("watch y");
	l.set_style(6,1);
	l.draw_at(xy_shape_rectang_group[5]);	
	
	Text m("fish x");
	m.set_style(6,1);
	m.draw_at(xy_shape_rectang_group[6]);
	
	Text n("fish y");
	n.set_style(6,1);
	n.draw_at(xy_shape_rectang_group[7]);
	
	Text o("       up");
	o.set_style(6,1);
	o.draw_at(rectang_up);
	
	Text p("     down");
	p.set_style(6,1);
	p.draw_at(rectang_down);
	
	Text q("  left");
	q.set_style(6,1);
	q.draw_at(rectang_left);
	
	Text r("           right");
	r.set_style(6,1);
	r.draw_at(rectang_right);
	
	
	
	UserTable  user_table;
	Shape* circle = new Shape;
	circle->add_circle(94, 52, 4);
	Watch* w = new Watch;
	w->head_x = 10;
	w->head_y = 10;
	Fish* f = new Fish(-40, -40, 2);
	Triangle* tamgiac = new Triangle(85, 48, 95, 60, 105, 48);
	Ship* sh = new Ship; 

	
	Pixel mouse_cur_pos;
	Pixel mouse_click_pixel;
	int count = 0;
	
	
	
	
	while(true)
	{
		mouse_cur_pos.cur_mouse_pos();
		mouse_click_pixel.mouse_click();
		
		
				// MY MAIN PROGRAM HERE
		//=====================================================
		if(mouse_click_pixel.is_in(&rectang_line_x1))
		{
			user_table.clear_shape(sh);
			user_table.clear_shape(tamgiac);
			user_table.clear_shape(f);
			user_table.clear_shape(w);
			
			int x1, y1, x2, y2;
			Text input;
			
			input.cin_at(rectang_line_x1);
			x1 = input.get_num();
			
			input.cin_at(rectang_line_y1);	
			y1 = input.get_num();
			
			input.cin_at(rectang_line_x2);	
			x2 = input.get_num();
			
			input.cin_at(rectang_line_y2);	
			y2 = input.get_num();
			
			Shape shape;
			shape.add_line(x1, y1, x2, y2);
			user_table.draw_shape(&shape, MAGENTA); getch();
			user_table.clear_shape(&shape);		
		}
		
		
		if(mouse_click_pixel.is_in(&rectang_elip_x))
		{
			user_table.clear_shape(sh);
			user_table.clear_shape(tamgiac);
			user_table.clear_shape(f);
			user_table.clear_shape(w);
			
			int x, y, dtx, dty;
			Text input;
			
			input.cin_at(rectang_elip_x);
			x = input.get_num();
			
			input.cin_at(rectang_elip_y);	
			y = input.get_num();
			
			input.cin_at(rectang_elip_dtx);	
			dtx = input.get_num();
			
			input.cin_at(rectang_elip_dty);	
			dty = input.get_num();
			
			Shape shape;
			shape.add_elip(x, y, dtx, dty);
			user_table.draw_shape(&shape, MAGENTA); getch();
			user_table.clear_shape(&shape);		
		}
		
		
		if(mouse_click_pixel.is_in(&rectang_3d_d))
		{
			user_table.clear_shape(sh);
			user_table.clear_shape(tamgiac);
			user_table.clear_shape(f);
			user_table.clear_shape(w);
			
			int d, r, c, beginx, beginy, beginz;
			Text input;
			
			input.cin_at(rectang_3d_d);
			d = input.get_num();
			
			if(d%2 == 1)
				d++;
			
			input.cin_at(rectang_3d_r);	
			r = input.get_num();
			
			input.cin_at(rectang_3d_c);	
			c = input.get_num();
			
			input.cin_at(rectang_beginx);
			beginx = input.get_num();
			
			input.cin_at(rectang_beginy);
			beginy = input.get_num();
			
			input.cin_at(rectang_beginz);
			beginz = input.get_num();
			
			vector<Point*> point_list;
			
			point_list.push_back(new Point(10,10-c));//A
			point_list.push_back(new Point(10+d,10-c));//B
			point_list.push_back(new Point(10+d,10));//C
			point_list.push_back(new Point(10,10));//D
			point_list.push_back(new Point(10-sqrt(2)*r/2,10-(c-sqrt(2)*r/2)));//E
			point_list.push_back(new Point(10+d-sqrt(2)*r/2,10-(c-sqrt(2)*r/2)));//F
			point_list.push_back(new Point(10+d-sqrt(2)*r/2,10+sqrt(2)*r/2));//G
			point_list.push_back(new Point(10-sqrt(2)*r/2,10+sqrt(2)*r/2));//H
			
			Shape* shape = new Shape;
	
			shape->add_line(point_list[0]->x, point_list[0]->y, point_list[1]->x, point_list[1]->y);//AB
			shape->add_line(point_list[2]->x, point_list[2]->y, point_list[3]->x, point_list[3]->y);//CD
			shape->add_line(point_list[3]->x, point_list[3]->y, point_list[0]->x, point_list[0]->y);//DA
			shape->add_line(point_list[1]->x, point_list[1]->y, point_list[2]->x, point_list[2]->y);//BC	
			shape->add_line_net_dut(point_list[4]->x, point_list[4]->y, point_list[5]->x, point_list[5]->y);//EF
			shape->add_line_net_dut(point_list[5]->x, point_list[5]->y, point_list[6]->x, point_list[6]->y);//FG
			shape->add_line(point_list[6]->x, point_list[6]->y, point_list[7]->x, point_list[7]->y);//GH
			shape->add_line(point_list[7]->x, point_list[7]->y, point_list[4]->x, point_list[4]->y);//HE
			shape->add_line(point_list[0]->x, point_list[0]->y, point_list[4]->x, point_list[4]->y);//AE
			shape->add_line_net_dut(point_list[1]->x, point_list[1]->y, point_list[5]->x, point_list[5]->y);//BF
			shape->add_line(point_list[2]->x, point_list[2]->y, point_list[6]->x, point_list[6]->y);//CG
			shape->add_line(point_list[3]->x, point_list[3]->y, point_list[7]->x, point_list[7]->y);//DH
			
			
			Text A("A: "), B("B: "), C("C: "), D("D: "), E("E: "), F("F: "), G("G: "), H("H: ");
			
			A.add("0,0,0"); 
			B.add(d); B.add(",0,0"); 
			C.add(d); C.add(","); C.add(r); C.add(",0");
			D.add("0,"); D.add(r); D.add(",0");
			E.add("0,0,"); E.add(c);
			F.add(d); F.add(",0,"); F.add(c);
			G.add(d); G.add(","); G.add(r); G.add(","); G.add(c);
			H.add("0,"); H.add(r); H.add(","); H.add(c);
			
			A.set_style(6, 1);
			B.set_style(6, 1);
			C.set_style(6, 1);
			D.set_style(6, 1);
			E.set_style(6, 1);
			F.set_style(6, 1);
			G.set_style(6, 1);
			H.set_style(6, 1);
			
			A.draw_at(new Rectang(600, 60, 650, 70));
			B.draw_at(new Rectang(900, 60, 950, 70));
			C.draw_at(new Rectang(1200, 60, 1250, 70));
			D.draw_at(new Rectang(1500, 60, 1550, 70));
			E.draw_at(new Rectang(1800, 60, 1850, 70));
			F.draw_at(new Rectang(2100, 60, 2150, 70));
			G.draw_at(new Rectang(2400, 60, 2450, 70));
			H.draw_at(new Rectang(2700, 60, 2750, 70));
			
			user_table.draw_shape(shape, MAGENTA); 
			
			
			getch();
			user_table.clear_shape(shape);	
			Painter::set_color_will_fill(WHITE);
			bar(300, 60, 1500, 100);
			
		}
		
		
		if(mouse_click_pixel.is_in(&rectang_cylinder3d_r))
		{
			user_table.clear_shape(sh);
			user_table.clear_shape(tamgiac);
			user_table.clear_shape(f);
			user_table.clear_shape(w);
			
			int r, h;
			
			Text input;
			
			input.cin_at(rectang_cylinder3d_r);
			r = input.get_num();
			
			input.cin_at(rectang_cylinder3d_h);	
			h = input.get_num();
			
			
			
			vector<Point*> point_list;
			
			point_list.push_back(new Point(0,0));
			point_list.push_back(new Point(0,h));
			point_list.push_back(new Point(-r,0));
			point_list.push_back(new Point(-r,h));
			point_list.push_back(new Point(r,0));
			point_list.push_back(new Point(r,h));
			
			Shape* shape = new Shape;
	
			shape->add_elip(point_list[0]->x, point_list[0]->y, r, r/2); 
			shape->add_elip(point_list[1]->x, point_list[1]->y, r, r/2); 
			shape->add_line(point_list[2]->x, point_list[2]->y, point_list[3]->x, point_list[3]->y);
			shape->add_line(point_list[4]->x, point_list[4]->y, point_list[5]->x, point_list[5]->y);
			
			user_table.draw_shape(shape, MAGENTA); getch();
			user_table.clear_shape(shape);	
		}
		
		
		
		// step1: clear, step2: setup, step3: draw
		if(count%100==0)
		{
			user_table.clear_shape(w);
			user_table.make_change_ratote(w->head_x, w->head_y, -9);
			w->point_list.clear();
			w->add_line(0, 0, w->head_x, w->head_y);
			w->add_circle(0, 0, 15);
			user_table.draw_shape(w , LIGHTGRAY); 
		}
			
			
			
		if(count%25==0) // fish
		{
			user_table.clear_shape(f);
		
			if(mouse_cur_pos.is_in(rectang_fish_bigger))
				f->up_size();
				
			if(mouse_cur_pos.is_in(rectang_fish_smaller))
				f->down_size();
				
			if(mouse_cur_pos.is_in(rectang_show_fish_symm_ox))
			{
				user_table.draw_shape(f, CYAN);
				Shape f2 = *(f->get_symmetry_ox());
				user_table.draw_shape(&f2, MAGENTA); getch();
				user_table.clear_shape(&f2);
			}
			if(mouse_cur_pos.is_in(rectang_show_fish_symm_oy))
			{
				user_table.draw_shape(f, CYAN);
				Shape f2 = *(f->get_symmetry_oy());
				user_table.draw_shape(&f2, MAGENTA); getch();
				user_table.clear_shape(&f2);
			}
			if(mouse_cur_pos.is_in(rectang_show_fish_symm_oxy))
			{
				user_table.draw_shape(f, CYAN);
				Shape f2 = *(f->get_symmetry_oxy());
				user_table.draw_shape(&f2, MAGENTA); getch();
				user_table.clear_shape(&f2);
			}
			
			if(mouse_cur_pos.is_in(rectang_up))
				f->move_up(), f->center_y++;
			if(mouse_cur_pos.is_in(rectang_down))	
				f->move_down(), f->center_y--;
			if(mouse_cur_pos.is_in(rectang_left))	
				f->move_left(), f->center_x--;
			if(mouse_cur_pos.is_in(rectang_right))
				f->move_right(), f->center_x++;
				
				
			f->change_having_wing_status();
			
			if(f->is_having_wing)
				user_table.draw_shape(f, CYAN);
			else
				user_table.draw_shape(f->get_him_in_not_wing(), CYAN);
			
		}
		
		
		// the sun
		user_table.clear_shape(tamgiac);
		tamgiac->rotate(93, 53, 20);
		user_table.draw_shape(tamgiac, RED);
		user_table.draw_shape(circle, RED);
		
		
		// the ship
		user_table.clear_shape(sh);
		if(sh->head_x == 105 || sh->tail_x == -105)
			sh->change_move();
		if(sh->is_moving_right)
			sh->move_right(), sh->head_x++, sh->tail_x++;
		else
			sh->move_left(), sh->head_x--, sh->tail_x--;
			
		user_table.draw_shape(sh, LIGHTBLUE);
		
		
	//=========================END PROGRAM=============================
	
	
	
		Text::SETSTYLE(6,1);
		Text::draw_num(rectang_fish_x.x1+8, rectang_fish_x.y1+5, f->center_x );
		Text::draw_num(rectang_fish_y.x1+8, rectang_fish_y.y1+5, f->center_y );
		Text::draw_num(rectang_watch_x.x1+8, rectang_watch_x.y1+5, w->head_x );
		Text::draw_num(rectang_watch_y.x1+8, rectang_watch_y.y1+5, w->head_y );
		Text::draw_num(rectang_ship_x1.x1+8, rectang_ship_x1.y1+5, sh->head_x);
		Text::draw_num(rectang_ship_y1.x1+8, rectang_ship_y1.y1+5, sh->head_y);
		Text::draw_num(rectang_ship_x2.x1+8, rectang_ship_x2.y1+5, sh->tail_x);
		Text::draw_num(rectang_ship_y2.x1+8, rectang_ship_y2.y1+5, sh->tail_y);
		
			
		
		delay(1);
		count++;
		if (count==100)
			count= 0;
	}
	
	
	
	
	getch(); closegraph();
}


