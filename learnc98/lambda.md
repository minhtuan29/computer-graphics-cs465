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
	  ....
	  ....
	
	
```
```C++

bool  predicate_net_dut(int count){
 	return count %4 == 0 || (count+1)%4 == 0;
}


int main()
{		
	Shape shape;
	shape.add_line_custom(x1, y1, x2, y2, predicate_net_dut);
}
```
