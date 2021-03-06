# computer graphics - CS465
This is my first time doing a project
![y](https://user-images.githubusercontent.com/86332370/142972501-b48d4257-53a3-42aa-b16a-40c2f6289ab3.gif)  

This is my first time doing a project and I got 9 mark due to high performance C++ my program. You need to download the software and run to see how it works in high performance, the GIF video is not enough frame to show.    

## How I make the program
I've finished it for 3 weeks of continuous work.  Due to inexperience, I destroyed it and rebuilt it twice.  After that, I don't rush to work, instead I write out what stuffs I will do on paper and how to implement them.  This helps me avoid risks when working. About it, it's built using DevC with graphic.h library. This software simulates how a computer graphics program works. Through this, students understand how computer graphics and computer vision programs work. It is very useful for those of student who are majoring in **AI and Machine Learning**. For example like this following in advance:  
![bd](https://user-images.githubusercontent.com/86332370/142972309-d543dd27-48cd-4191-a7b9-3b941675bb76.gif)  
![ezgif-2-c861a15b77](https://user-images.githubusercontent.com/86332370/156929164-7e6ee0bd-da47-4874-b0a8-dfba280d7d20.gif)

Key knowledges include:  
- Computers perceives that a complex shape made up of basic shapes
- Showing the graphic shape with pixels, each pixel has a specified x y coordinate
- The basic computer geometry algorithms such as : rotation, scale, translation, projection, symmetry
- Computers draw a line using **algorithms**
- use matrix to represent 2D shape to 3D

# Other name
Ky Thuat Do Hoa - Do Hoa May Tinh
# Author
HOANG MINH TUAN
# Updating
using lambda to custom the way to draw the line (Polymorphism), how to get lambda in C++98  
```C++
	
	void lineDDA_custom(int x1, int y1, int x2, int y2, bool(*predicateDraw)(int count)  ) { 
  	// Predicate in Java8 or condition lambda expression in all languages
	// means : the way to draw in condition, depend on count --- I am using C++98 , there is no lambda
	int count = 1;
	  if (x1 == x2) {
	    int i;
	    if (y1 < y2)
	      for (i = y1; i <= y2; i++) {
	        Point p(x1, i);
	        count++; 
		if( predicateDraw(count) )  point_list.push_back(p);
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
![Capture](https://user-images.githubusercontent.com/86332370/162718042-f5cabc68-ea23-471f-838f-d8922f0189db.PNG)  

Version 2.0 - June 2022 update - Project Mentor:  
Github : https://github.com/River-Tea/ComputerGraphics  
![bailam](https://user-images.githubusercontent.com/86332370/175193562-342e91c6-a90b-42da-afdc-0323eafa04db.gif)  
  


