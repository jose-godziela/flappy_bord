#include "Manager.h"

void init_player()
{
	player->set_radius(PLAYER_RADIUS);
	player->set_pos_x(80);
	player->set_vel(0.0f);
	player->set_accel(0.0f);
	player->set_pos_y(GetScreenHeight() / 2);
	player->set_color(RED);
}

void init_blocks()
{
	//later the blocks will be more, and this will solve me the hassle of declaring them later
	for (int i = 0; i < CANT_TUBES; i++)
	{
		tubes[i]->set_x(600+280*i);
		tubes[i]->set_y(-GetRandomValue(0,40));
		tubes[i]->set_width(30);
		tubes[i]->set_height(70);
		tubes[i]->set_status(true);
		tubes[i]->set_color(GREEN);
	}
}

void init_game()
{
	InitWindow(800, 450, "Flappy Bord");
	SetTargetFPS(FPS);
	player = new Player();
	
	for(int i = 0; i < CANT_TUBES; i++)
		tubes[i] = new Tubes();
	
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
		for (int i = 0; i < CANT_TUBES; i++)
		{
			if (CheckCollisionCircleRec(player->get_pos(), player->get_radius(), tubes[i]->get_rec()))
			{
				game_over = true;

			}
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
		//Update blocks
		for(int i = 0; i < CANT_TUBES; i++)
		{
			tubes[i]->set_x(tubes[i]->get_rec().x - MOVEMENT);
			if (tubes[i]->get_rec().x < SCREEN_LEFT_BORDER - tubes[i]->get_rec().width)
			{
				tubes[i]->set_x(GetScreenWidth() + SCREEN_OFFSET);
			}
		}
		//Update player
		player->set_accel(player->get_accel() - (GRAVITY * GetFrameTime()));
		if (player->get_accel() >= GRAVITY)
			player->set_accel(GRAVITY);

		player->set_vel(player->get_vel() - (player->get_accel() * GetFrameTime()));

		player->set_pos_y(player->get_pos().y + (player->get_vel()));

		//std::cout << player->get_vel() << endl;
		std::cout << "vel: " << player->get_vel() << " accel: " << player->get_accel() << " v - a: " << player->get_vel() - player->get_accel() * GetFrameTime() << endl;


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
			DrawText("version: 0.1", GetScreenWidth() - SCREEN_OFFSET, GetScreenHeight() - 30, 5, RED);
			break;
		}
		case CREDITS:
		{
			DrawText("Programming: Felix Godziela", GetScreenWidth() / 4 - 50, GetScreenHeight() / 2-  30, 30, RED);
			DrawText("Press enter to go back", GetScreenWidth() / 4, GetScreenHeight() / 1.5f, 15, RED);
			break;
		}
		case GAME:
		{
			if (!game_over)
			{
				DrawCircle(player->get_pos().x, player->get_pos().y, player->get_radius(), player->get_color());
				for(int i = 0; i < CANT_TUBES; i++)
				if(tubes[i]->get_status())
					DrawRectangleRec(tubes[i]->get_rec(),/*blocks->get_color()*/GRAY);
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

			if (IsKeyPressed(KEY_SPACE))
			{
				player->set_accel(0.0f);
				player->set_vel(-GRAVITY / 4);
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

	if (tubes != NULL)
		delete tubes;
}


void play()
{
	init_game();

	while (!WindowShouldClose())
	{
		update();
		draw();
		input();
	}
	de_init();
	CloseWindow();

}




