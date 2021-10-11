#include <iostream>

#include "raylib.h"

const int FPS = 60;
const int PLAYER_RADIUS = 24;
const int MOVEMENT = 5;
const int CANT_BLOCKS = 1;
const float GAME_OVER_SCREEN_TIME = 180.0f;

using namespace std;

//Player.cpp
//--------------------------------------------------------------------------------------------------------------------------------------
class Player
{
private:
	Vector2 _pos;
	float _radius;
	Color _color;
public:
	Player();
	~Player();
	void set_pos_x(int x);
	void set_pos_y(int y);
	void set_radius(float radius);
	void set_color(Color color);
	Vector2 get_pos();
	float get_radius();
	Color get_color();
};
Player::Player()
{
	_pos = { 0,0 };
	_radius = 0.0f;
	_color = RAYWHITE;
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
float Player::get_radius()
{
	return _radius;
}
Color Player::get_color()
{
	return _color;
}
//-----------------------------------------------------------------------------------------------


//Blocks.cpp?
//--------------------------------------------------------------------------------------------------
class Blocks
{
private:
	Rectangle _rec;
	bool _status;
public:
	Blocks();
	~Blocks();
	void set_rec(Rectangle rec);
	void set_x(int x);
	void set_y(int y);
	void set_width(int width);
	void set_height(int height);
	void set_status(bool status);
	Rectangle get_rec();
	bool get_status();
};

Blocks::Blocks()
{

}
Blocks::~Blocks()
{

}
void Blocks::set_rec(Rectangle rec)
{
	_rec = rec;
}
void Blocks::set_x(int x)
{
	_rec.x = x;
}
void Blocks::set_y(int y)
{
	_rec.y = y;
}
void Blocks::set_width(int width)
{
	_rec.width = width;
}
void Blocks::set_height(int height)
{
	_rec.height = height;
}
void Blocks::set_status(bool status)
{
	_status = status;
}
Rectangle Blocks::get_rec()
{
	return _rec;
}
bool Blocks::get_status()
{
	return _status;
}
//-----------------------------------------------------------------------------------------------------

enum Current_screen
{
	start,
	MENU,
	CREDITS,
	GAME,
	final
}current_screen;
//both "start" and "final" are safestates that i can use when there's a problem with the enum functions

Player* player;
Blocks* blocks;
bool game_over;
int frames;

void init_player()
{
	player->set_radius(PLAYER_RADIUS);
	player->set_pos_x(80);
	player->set_pos_y(GetScreenHeight() / 2);
	player->set_color(RED);
}

void init_blocks()
{
	//later the blocks will be more, and this will solve me the hassle of declaring them later
	for (int i = 0; i < CANT_BLOCKS; i++)
	{
		blocks->set_x(600+280*i);
		blocks->set_y(-GetRandomValue(0,40));
		blocks->set_width(30);
		blocks->set_height(70);
		blocks->set_status(true);
	}
}

void init_game()
{
	InitWindow(800, 450, "Flappy Bord");
	player = new Player();
	blocks = new Blocks();
	game_over = false;

	//for the moment, player will be hardcoded

	init_player();
	init_blocks();
	current_screen = MENU;

}


void update()
{
	switch (current_screen)
	{
	case MENU:
	{
		init_player();
		init_blocks();
		break;
	}
	case GAME:
	{
		if (CheckCollisionCircleRec(player->get_pos(), player->get_radius(), blocks->get_rec()))
		{
			game_over = true;

		}
		if (game_over)
		{
			frames++;
			if (frames == GAME_OVER_SCREEN_TIME)
			{
				current_screen = MENU;
				frames = 0;
				game_over = false;
			}
		}
		int aux = blocks->get_rec().x;
		blocks->set_x(aux -= MOVEMENT);
		break;
	}
	}
	
}

void draw()
{
	ClearBackground(RAYWHITE);
	BeginDrawing();
	switch (current_screen)
	{
		case start:
		{
			cout << "something happenned, i'm at start" << endl;
			break;
		}
		case final:
		{
			cout << "something happenned, i'm at final" << endl;
			break;
		}
		case MENU:
		{
			DrawText("WELCOME TO FLAPPY BORD", GetScreenWidth() / 4, GetScreenHeight() / 2, 30, RED);
			DrawText("Press enter to start", GetScreenWidth() / 4, GetScreenHeight() / 2 + 80, 15, RED);
			DrawText("Press C to see the credits", GetScreenWidth() / 4, GetScreenHeight() / 2 + 110, 15, RED);
			DrawText("version: 0.1", GetScreenWidth() - 100, GetScreenHeight() - 30, 5, RED);
			break;
		}
		case CREDITS:
		{
			DrawText("Programming: Felix Godziela", GetScreenWidth() / 2- 50, GetScreenHeight() / 2-  30, 30, RED);
			DrawText("Press enter to go back", GetScreenWidth() / 2, GetScreenHeight() / 1.5f, 15, RED);
			break;
		}
		case GAME:
		{
			if (!game_over)
			{
				DrawCircle(player->get_pos().x, player->get_pos().y, player->get_radius(), player->get_color());
				//for(int i = 0; i < CANT_BLOCKS; i++)
				if(blocks/*[i]*/->get_status())
					DrawRectangleRec(blocks->get_rec(),/*blocks->get_color()*/GRAY);
				DrawText("Press A to go back to the menu", GetScreenWidth() - 200, GetScreenHeight() - 30, 5, RED);
			}
			else
			{
				DrawText("GAME OVER", GetScreenWidth() / 3, GetScreenHeight() / 2, 30, RED);
			}
			break;
		}
	}
	EndDrawing();
}

void input()
{
	switch (current_screen)
	{
		case start:
		{
			cout << "something happenned, i'm at start" << endl;
			break;
		}
		case final:
		{
			cout << "something happenned, i'm at final" << endl;
			break;
		}
		case MENU:
		{
			if (IsKeyPressed(KEY_ENTER))
				current_screen = GAME;
			if (IsKeyPressed(KEY_C))
				current_screen = CREDITS;
			break;
		}
		case CREDITS:
		{
			if (IsKeyPressed(KEY_ENTER))
				current_screen = MENU;
			break;
		}
		case GAME:
		{
			if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
			{
				player->set_pos_y(player->get_pos().y - MOVEMENT);
			}
			if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
			{
				player->set_pos_y(player->get_pos().y + MOVEMENT);
			}
			if (IsKeyPressed(KEY_A))
				current_screen = MENU;
			break;
		}
	}

}


void de_init()
{
	if (player != NULL)
		delete player;

	if (blocks != NULL)
		delete blocks;
}


void play()
{
	init_game();

	SetTargetFPS(FPS);

	while (!WindowShouldClose())
	{
		update();
		draw();
		input();
	}
	de_init();
	CloseWindow();

}

void main()
{
	play();
}


