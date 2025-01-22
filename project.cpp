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

void printmap()
{
    for (int i=0; i<pagesize; ++i)
        for (int j=0; j<pagesize; ++j)
            map[i][j]=' ';

            
    map[1][1]='A';
    map[1][2]=' ';
    map[2][1]=' ';

    for(int i=0; i<pagesize; ++i)
    {
        map[i][0]='*';
        map[i][pagesize-1]='*';
    }
    for(int j=0; j<pagesize-1; ++j)
    {
        map[0][j]='*';
        map[pagesize-1][j]='*';
    }

    for(int i=2; i<pagesize-1; ++i)
        for(int j=2; i<pagesize-1; j+=2)
            map[i][j]='X';


    for(int i=0; i<15; ++i)
    {
        int x = give_random();
        int y = give_random();
        COORD coordinate;
        if(map[y][x]!='X' && map[y][x]!='A')
        {
            map[y][x]='_';
            coordinate.X=x;
            coordinate.Y=y;
            blocks.push_back(coordinate);
        }
        else
            --i;
    }
    unsigned int seed = time(0);
    mt19937 engine(seed);
    uniform_int_distribution<int> dist(0,blocks.size()-1);
    exitdoor=blocks[dist(engine)];


    for(int i=0; i<enemynumber; ++i)
    {
        int x = give_random();
        int y = give_random();

        if(map[y][x]!='X' && map[y][x]!='A' &&  map[y][x]!='_')
            map[y][x]='E';
        else
            --i;
    }
//showpage
    for(int i=0; i<pagesize; ++i)
    {
        for(int j=0; j<pagesize; ++j)
            cout<<map[i][j]<<' ';

        cout<<endl;
    }

}

void showGuide()
{

    cout << " <<Spoon Man Game>>\n";
    cout << "\n Game Guide:\n";
    cout << " - Move with 'W', 'A', 'S', 'D' or arrow keys.\n";
    cout << " - Place bombs with 'B'.\n";
    cout << " - Bombs explode after two moves.\n";
    cout << " - Destroy enemies and find the exit 'O'.\n";
    cout << " - Press 'M' to return to menu.\n";

    getch();
}

void setDifficulty()
{
    char choice;
    cout << "setDifficulty\n";
    cout << "1. Easy\n";
    cout << "2. Medium\n";
    cout << "3. Hard\n";
    cout << "choose the level you want:";
    cin >> choice;
    switch (choice)
    {
    case '1':
        pagesize = 15;
        enemynumber=3;
        break;
    case '2':
        pagesize = 20;
        enemynumber=5;
        break;
    case '3':
        pagesize = 25;
        enemynumber=7;
        break;
    default:
        cout << "Invalid choice. Please try again.\n";
    }

}
void runGame()
{
    player.pos.x=1;
    player.pos.y=1;
    isGameRunning = true;
    char input;
    while (isGameRunning)
    {

        printmap();

        cout << "\nUse 'W', 'A', 'S', 'D' to move, 'B' to place bomb, 'M' to return to menu: ";
        input = getch();
        if(input>='A' && input<='Z')
            input+=32;

        switch (input)
        {
        case 'w':
        case 72:
            if( map[player.pos.y-1][player.pos.x]!='X' && map[player.pos.y-1][player.pos.x]!='_')
            {
                map[player.pos.y][player.pos.x]=' ';
                map[player.pos.y-1][player.pos.x]='A';
                player.pos.y -=1;
                bomb.timer-=1;
            }
            break;
        case 's':
        case 80:
            if(player.pos.y>0 && map[player.pos.y+1][player.pos.x]!='X' && map[player.pos.y+1][player.pos.x]!='_')
            {
                map[player.pos.y][player.pos.x]=' ';
                map[player.pos.y+1][player.pos.x]='A';
                player.pos.y += 1;
                bomb.timer-=1;
            }
            break;
        case 'a':
        case 75:
            if(player.pos.x>0 && map[player.pos.y][player.pos.x-1]!='X' && map[player.pos.y][player.pos.x-1]!='_')
            {
                map[player.pos.y][player.pos.x]=' ';
                map[player.pos.y][player.pos.x-1]='A';
                player.pos.x -= 1;
                bomb.timer-=1;
            }

            break;
        case 'd':
        case 77:
            if(player.pos.x>0 && map[player.pos.y][player.pos.x+1]!='X' && map[player.pos.y][player.pos.x+1]!='_')
            {
                map[player.pos.y][player.pos.x]=' ';
                map[player.pos.y][player.pos.x+1]='A';
                player.pos.x += 1;
                bomb.timer-=1;
            }

            break;
        case 'b':
        {

            bomb.pos.x = player.pos.x;
            bomb.pos.y = player.pos.y;
            bomb.timer=2;
            map[bomb.pos.y][bomb.pos.x]= 'B';
        }

        break;
        case 'm':
            isGameRunning = false;
            return;
        default:
            return;
        }

        if(bomb.timer == 0)
        {

            if(map[bomb.pos.y][bomb.pos.x+1]='E')
                --enemynumber;

            if(map[bomb.pos.y][bomb.pos.x-1]='E')
                --enemynumber;

            if (map[bomb.pos.y+1][bomb.pos.x]='E')
                --enemynumber;

            if (map[bomb.pos.y-1][bomb.pos.x]='E')
                --enemynumber;

            if( map[bomb.pos.y][bomb.pos.x+1]!='X'|| map[bomb.pos.y][bomb.pos.x+1]=='-'|| map[bomb.pos.y][bomb.pos.x+1]=='E')
                map[bomb.pos.y][bomb.pos.x+1]=' ';

            if(map[bomb.pos.y][bomb.pos.x-1]!='X'|| map[bomb.pos.y][bomb.pos.x-1]=='-'|| map[bomb.pos.y][bomb.pos.x-1]=='E' )
                map[bomb.pos.y][bomb.pos.x-1]=' ';
