#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include "Tubes.h"
#include "Player.h"

const int FPS = 60;
const int PLAYER_RADIUS = 24;
const int MOVEMENT = 5;
const int CANT_TUBES = 1;
const float GAME_OVER_SCREEN_TIME = 180.0f;
const int SCREEN_OFFSET = 100;
const int SCREEN_LEFT_BORDER = 0;
const float GRAVITY = 10.0f;//temp number
Player* player;
Tubes* tubes[CANT_TUBES];
bool game_over;
int frames;

using namespace std;

enum Current_screen
{
	start,
	MENU,
	CREDITS,
	GAME,
	final
}current_screen;
//both "start" and "final" are safestates that i can use when there's a problem with the enum functions



#endif