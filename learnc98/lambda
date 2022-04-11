```C++
	
	void lineDDA_custom(int x1, int y1, int x2, int y2, bool(*predicateDraw)(int count)  ) { 
  // Predicate in Java8 or lambda expression in all languages
	// means : the way to draw in condition, depend on count --- I am using C++98 having not lambda
	int count = 1;
	  if (x1 == x2) {
	    int i;
	    if (y1 < y2)
	      for (i = y1; i <= y2; i++) {
	        Point p(x1, i);
	        count++; if( predicateDraw(count) )
	        point_list.push_back(p);
	      }
	    else
	      for (i = y2; i <= y1; i++) {
	        Point p(x1, i); 
			count++; if(predicateDraw(count) )
	        point_list.push_back(p);
	      }
	  }
	  if (y1 == y2) {
	    int i;
	    if (x1 < x2)
	      for (i = x1; i <= x2; i++) {
	        Point p(i, y1);
	        count++; if(predicateDraw(count)  )
	        point_list.push_back(p);
	      }
	    else
	      for (i = x2; i <= x1; i++) {
	        Point p(i, y1);
	        count++; if(predicateDraw(count)  )
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
	        count++; if(predicateDraw(count) )
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
	          count++; if(predicateDraw(count)  )
	          point_list.push_back(p);
	
	        }
	      } else {
	        int i;
	        int Dx = x2 - x1;
	        int Dy = y2 - y1;
	        int p = 2 * Dx - Dy;
	        Point p3(x1, y1);
	        count++; if(predicateDraw(count)  )
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
	          count++; if(predicateDraw(count)  )
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
	        count++; if(predicateDraw(count)  )
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
	          count++; if(predicateDraw(count)  )
	          point_list.push_back(p);
	        }
	      } else {
	        int i;
	        int Dx = x2 - x1;
	        int Dy = y2 - y1;
	        int p = 2 * Dx + Dy;
	
	        Point p5(x1, y1);
	        count++; if(predicateDraw(count)  )
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
	          count++; if(predicateDraw(count)  )
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
		        count++; if(predicateDraw(count)  )
		        point_list.push_back(p6);
		        for (i = x1; i > x2; i--) {
		          if (p < 0) {
		            p = p - 2 * Dy - 2 * Dx;
		            y1++;
		          } else
		            p = p - 2 * Dy;
		          x1--;
		          Point p(x1, y1);
		          count++; if(predicateDraw(count)  )
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
		          count++; if(predicateDraw(count)  )
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
		        count++; if(predicateDraw(count) )
		        point_list.push_back(p8);
		        for (i = x1; i > x2; i--) {
		          if (p > 0) {
		            p = p - 2 * Dy + 2 * Dx;
		            y1--;
		          } else
		            p -= 2 * Dy;
		          x1--;
		          Point p(x1, y1);
		          count++; if(predicateDraw(count)  )
		          point_list.push_back(p);
		        }
		      } else {
		        int i;
		        int Dx = x1 - x2;
		        int Dy = y1 - y2;
		        int p = 2 * Dx + Dy;
		        Point p9(x1, y1);
		        count++; if(predicateDraw(count)  )
		        point_list.push_back(p9);
		        for (i = y1; i > y2; i--) {
		          if (p < 0) {
		            p = p - 2 * Dx + 2 * Dy;
		            x1--;
		          } else
		
		            p = p - 2 * Dx;
		          y1--;
		          Point p(x1, y1);
		          count++; if(predicateDraw(count)  )
		          point_list.push_back(p);
		        }
		      }
	    	}
		}
	}
	
	
```
