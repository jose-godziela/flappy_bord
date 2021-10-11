#include <iostream>

#include "raylib.h"

using namespace std;



//Player.cpp
//--------------------------------------------------------------------------------------------------------------------------------------
class Player
{
private:
	Vector2 _pos;

public:
	Player();
	~Player();
	void set_pos_x(int x);
	void set_pos_y(int y);
	Vector2 get_pos();
};
Player::Player()
{
	_pos = {0,0};
}
Player::~Player()
{
	cout << "Bye bye" << endl;
}
void Player::set_pos_x(int x)
{
	_pos.x = x;
}
void Player::set_pos_y(int y)
{
	_pos.y = y;
}
Vector2 Player::get_pos()
{
	return _pos;
}
//-----------------------------------------------------------------------------------------------


void init_game()
{
	Player* player = new Player();
}











void play()
{
	InitWindow(800, 450, "Flappy Bord");
	init_game();
}

void main()
{
	play();
	fflush(stdin);
	cin.get();
}
