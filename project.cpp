#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string>
#include <random>
#include <windows.h>
void printmap();
int give_random();
void showGuide();
void setDifficulty();
void runGame();

using namespace std;

struct Position
{
    int x;
    int y;
};
struct Player
{
    Position pos;
    int moves;
};
struct Bomb
{
    Position pos;
    int timer;

};
COORD exitdoor;
Player player;
 Bomb bomb;
int pagesize=15;
int enemynumber=3;
bool isGameRunning = false;

vector <COORD> blocks;

vector<vector<char>> map(pagesize,vector<char>(pagesize,' '));