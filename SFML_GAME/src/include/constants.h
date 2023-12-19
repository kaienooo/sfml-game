#pragma once

//gamestates

#define MENU 0
#define SETTINGS 1
#define PLAYING 2
#define SHOP 3
#define EXIT -1

//framerate constants

#define FPS 60
#define UPS 120

//movement constants

#define STEP_SIZE 230
//Pixel na sekunde
#define MOV_SPEED STEP_SIZE/1000.0f
//Pixel na microsekunde (unit czasu)



//reserve constants
#define BULLET_RESERVE 100
#define TEXTURE_RESERVE 5