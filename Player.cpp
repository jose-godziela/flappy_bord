#include "Player.h"

Player::Player()
{
	_pos = { 0,0 };
	_velocity = 0.0f;
	_accel = 0.0f;
	_radius = 0.0f;
	_color = RAYWHITE;
}
Player::~Player()
{

}
void Player::set_pos_x(int x)
{
	_pos.x = x;
}
void Player::set_pos_y(int y)
{
	_pos.y = y;
}
void Player::set_vel(float vel)
{
	_velocity = vel;
}
void Player::set_accel(float accel)
{
	_accel = accel;
}
void Player::set_radius(float radius)
{
	_radius = radius;
}
void Player::set_color(Color color)
{
	_color = color;
}
Vector2 Player::get_pos()
{
	return _pos;
}
float Player::get_vel()
{
	return _velocity;
}
float Player::get_accel()
{
	return _accel;
}
float Player::get_radius()
{
	return _radius;
}
Color Player::get_color()
{
	return _color;
}