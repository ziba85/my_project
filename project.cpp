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

int main()


    {int choice;

            cout << " << Spoon Man Game >>\n\n";
            cout << " 1.Start Game\n";
            cout << " 2.Load Game\n";
            cout << " 3.Difficulty\n";
            cout << " 4.Guide\n";
            cout << " 5.Scoreboard\n";
            cout << " 6.Exit\n\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                runGame();
                break;
            case 2:
                cout<<"Not available";
                break;
            case 3:
                setDifficulty();
                break;
            case 4:
             showGuide();
                break;
            case 5:
                cout<<"Not available";
                break;
            case 6:
                cout << "Exiting the game.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        return 0;
    }



int give_random()
{
    unsigned int seed = time(0);
    mt19937 engine(seed);
    uniform_int_distribution<int> dist(0, pagesize-1);
    return dist(engine);
}
