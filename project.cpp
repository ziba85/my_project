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