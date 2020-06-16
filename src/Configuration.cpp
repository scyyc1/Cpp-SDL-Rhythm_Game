#include "Configuration.h"

// Life tiles related
int TILE_SIZE = 80;
int MAP_HEIGHT = 2;
int MAP_WIDTH = 8;
int LIFEMAP_START_X = 800;
int LIFEMAP_START_Y = 50;

// Scyyc1TileManger related
int AVENUE_TILE_SIZE = 100;
int AVENUE_MAP_HEIGHT = 4;
int AVENUE_MAP_WIDTH = 10;
int AVENUE_START_X = 150;
int AVENUE_START_Y = 200;

// Note related
int NOTE_SIZE = 100;
int NOTE_START_1_Y = 250;
int NOTE_START_2_Y = 350;
int NOTE_START_3_Y = 450;
int NOTE_START_4_Y = 550;
int NOTE_START_X = 50;

int SINGLE = 0;
int DOUBLE = 1;
int LONG = 2;

// Controller related
int CONTROLLER_SIZE = 100;
int CONTROLLER_NUM = 4;

int CONTROLLER_START_1_Y = 200;
int CONTROLLER_START_2_Y = 300;
int CONTROLLER_START_3_Y = 400;
int CONTROLLER_START_4_Y = 500;
int CONTROLLER_START_X = 1200;

// Evalutaion related
int PERFECT = 0;
int GREAT = 1;
int GOOD = 2;
int BAD = 3;
int MISS = 4;

// Speed controller related
int MIN_POS_X = 900;
int MIN_POS_Y = 680;
int MAX_POS_X = 1100;

// Controling related
int RESTART = -1;
int OVAL_OFFSET = 5;
int RECTANGLE_OFFSET = 1;

// Time related
int BEATS = 125;		// 125ms per beat

// Button related
int BUTTON_OFFSET = 3;

// State related
int STATENUM = 2;
int START_S = 0;
int START_G = 1;
int START_A = 2;

// Colour
int RED= 0x010000;
int GREEN=0x000100;
int BLUE = 0x000001;

// Window
extern int WINDOW_X = 1300;
extern int WINDOW_Y = 800;

// score
int finalScore = 0;
int CHANCE = 1;
string PLAYER_NAME = "default";
int RANK_SIZE = 5;
int RANK_LINE_SPACE = 100;