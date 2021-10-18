#ifndef TUBES_H
#define TUBES_H

#include "raylib.h"

class Tubes
{
private:
	Rectangle _rec;
	bool _status;
	Color _color;
public:
	Tubes();
	~Tubes();
	void set_rec(Rectangle rec);
	void set_x(int x);
	void set_y(int y);
	void set_width(int width);
	void set_height(int height);
	void set_status(bool status);
	void set_color(Color color);
	Rectangle get_rec();
	bool get_status();
	Color get_color();
};

#endif