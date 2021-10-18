#include "Tubes.h"

Tubes::Tubes()
{
	_rec.x = 0;
	_rec.y = 0;
	_rec.height = 0;
	_rec.width = 0;
	_status = false;
	_color = RAYWHITE;
}
Tubes::~Tubes()
{

}
void Tubes::set_rec(Rectangle rec)
{
	_rec = rec;
}
void Tubes::set_x(int x)
{
	_rec.x = x;
}
void Tubes::set_y(int y)
{
	_rec.y = y;
}
void Tubes::set_width(int width)
{
	_rec.width = width;
}
void Tubes::set_height(int height)
{
	_rec.height = height;
}
void Tubes::set_status(bool status)
{
	_status = status;
}
void Tubes::set_color(Color color)
{
	_color = color;
}
Rectangle Tubes::get_rec()
{
	return _rec;
}
bool Tubes::get_status()
{
	return _status;
}
Color Tubes::get_color()
{
	return _color;
}