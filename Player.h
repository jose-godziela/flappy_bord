#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player
{
private:
	Vector2 _pos;
	float _velocity;
	float _accel;
	float _radius;
	Color _color;
public:
	Player();
	~Player();
	void set_pos_x(int x);
	void set_pos_y(int y);
	void set_vel(float vel);
	void set_accel(float accel);
	void set_radius(float radius);
	void set_color(Color color);
	Vector2 get_pos();
	float get_vel();
	float get_accel();
	float get_radius();
	Color get_color();
};

#endif