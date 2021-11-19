#ifndef IMAGE_H
#define IMAGE_H

class Image{
private:
	void* m_data;
	int x1;
	int x2;
	int y1;
	int y2;
	
public:
	
	Image(int x1, int y1, int x2, int y2)
	{
		this->x1 = x1;
		this->x2 = x2;
		this->y1 = y1;
		this->y2 = y2;
		m_data = malloc(imagesize(x1, y1, x2, y2));
		
	}
	
	void take_photo()
	{
		getimage(x1, y1, x2, y2, m_data);
	}
	
	void draw(int x, int y, int mode = 0)
	{
		putimage(x, y, m_data, mode);
	}
};

#endif
