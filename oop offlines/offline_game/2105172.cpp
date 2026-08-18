#include <iostream>
#include <cmath>
#include <sstream>
#include<ctime>

using namespace std;

#define GRIDSIZE 4
#define UP 0
#define DOWN 2
#define LEFT 3
#define RIGHT 1
#define MAX_SHOTS 3

string to_string(int x)
{
    std::string out_string;
    std::stringstream ss;
    ss << x;
    return ss.str();
}

class Position
{

    int x, y;

public:
    Position(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Position() {}

    // Modify the following four so that the resulting position does not leave the grid
    void moveRight()
    {
        if (x <= 2)
            x++;
    }

    void moveLeft()
    {
        if (x >= 1)
            x--;
    }

    void moveUp()
    {
        if (y <= 2)
            y++;
    }

    void moveDown()
    {
        if (y >= 1)
            y--;
    }

    bool isAdjacent(Position p)
    {
        // implement the function
        if ((p.getX() == x && abs(y - p.getY()) == 1) || (p.getY() == y && abs(p.getX() - x) == 1))
            return true;
        else
            return false;
    }

    bool isSamePoint(Position p)
    {
        // implement the function
        if (p.getX() == x && p.getY() == y)
            return true;
        else
            return false;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }
};

class Wumpus
{

    bool killed;
    Position p;

public:
    Wumpus(int x, int y)
    {
        p = Position(x, y);
        killed = false;
    }

    Wumpus()
    {
        //...
        int wumpus_x, wumpus_y;
        srand(time(0));
        wumpus_x = rand() % 4;
        wumpus_y = rand() % 4;
        p = Position(wumpus_x, wumpus_y);
        killed = false;
    }

    void kill()
    {
        cout << "wumpus screaming"<<endl<<"wumpus killed"<<endl;
        killed = true;
        p=Position(GRIDSIZE,GRIDSIZE);


    }

    Position getPosition()
    {
        return p;
    }
};

class Player
{

    int direction;
    int total_shots;
    bool killed;
    Position p;

public:
    Player()
    {
        //...
        direction = UP;
        killed = false;
        total_shots = MAX_SHOTS;
        p=Position(0,0);
    }

    void turnLeft()
    {
        //...
        if (direction == UP)
            direction = LEFT;
        else if (direction == DOWN)
            direction = RIGHT;
        else if (direction == LEFT)
            direction = DOWN;
        else
            direction = direction = UP;
    }

    void turnRight()
    {
        //...
        if (direction == UP)
            direction = RIGHT;
        else if (direction == DOWN)
            direction = LEFT;
        else if (direction == LEFT)
            direction = UP;
        else
            direction = DOWN;
    }

    void moveForward()
    {
        //...
        if (direction == UP)
            p.moveUp();
        else if (direction == DOWN)
            p.moveDown();
        else if (direction == LEFT)
            p.moveLeft();
        else
            p.moveRight();
    }

    bool isAdjacent(Position pos)
    {
        return p.isAdjacent(pos);
    }

    bool isSamePoint(Position pos)
    {
        return p.isSamePoint(pos);
    }

    void kill()
    {
        killed = true;
    }
    ////3
    int Direction()
    {
        return direction;
    }
    Position getPosition()
    {
        return p;
    }
    int fired()
    {
       return --total_shots;
    }
    int remain()
    {
        return total_shots;
    }
    string getPositionInfo()
    {
        return "Player is now at " + std::to_string(p.getX()) + ", " + std::to_string(p.getY());
    }

    string getDirectionInfo()
    {
        string s;
        if (direction == UP)
            s = "up";
        if (direction == DOWN)
            s = "down";
        if (direction == LEFT)
            s = "left";
        if (direction == RIGHT)
            s = "right";
        return "Player is moving at direction: " + s;
    }
};

class WumpusWorld
{

private:
    Player player;
    Wumpus wumpus;
    Position gold_position, pit_position;
    bool ended;

public:

    WumpusWorld()
    {

        //...
        int pit_x, pit_y, gold_x, gold_y;
        int wumpus_x = wumpus.getPosition().getX();
        int wumpus_y = wumpus.getPosition().getY();

        do
        {
            //srand(time(0));

            gold_x = rand() % 4;
            gold_y = rand() % 4;
        } while (gold_x == 0 && gold_y == 0);
        gold_position = Position(gold_x, gold_y);
        do
        {
            //srand(time(0));
            pit_x = rand() % 4;
            pit_y = rand() % 4;
        } while ((pit_x == 0 && pit_y == 0) || (pit_x == gold_x && pit_y == gold_y) || (pit_x == wumpus_x && pit_y == wumpus_y));
        pit_position = Position(pit_x, pit_y);
    }

    WumpusWorld(int wumpus_x, int wumpus_y)
    {
        //...
        wumpus = Wumpus(wumpus_x, wumpus_y);
        int pit_x, pit_y, gold_x, gold_y;

        do
        {
            //srand(time(0));

            gold_x = rand() % 4;
            gold_y = rand() % 4;
        } while (gold_x == 0 && gold_y == 0);
        gold_position = Position(gold_x, gold_y);
        do
        {
           //srand(time(0));
            pit_x = rand() % 4;
            pit_y = rand() % 4;
        } while ((pit_x == 0 && pit_y == 0) || (pit_x == gold_x && pit_y == gold_y) || (pit_x == wumpus_x && pit_y == wumpus_y));
        pit_position = Position(pit_x, pit_y);
    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y)
    {
        //...
        wumpus = Wumpus(wumpus_x, wumpus_y);
        gold_position = Position(gold_x, gold_y);
        int pit_x, pit_y;

        do
        {
           // srand(time(0));
            pit_x = rand() % 4;
            pit_y = rand() % 4;
        } while ((pit_x == 0 && pit_y == 0) || (pit_x == gold_x && pit_y == gold_y) || (pit_x == wumpus_x && pit_y == wumpus_y));
        pit_position = Position(pit_x, pit_y);
    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y, int pit_x, int pit_y)
    {
        //...
        wumpus = Wumpus(wumpus_x, wumpus_y);
        gold_position = Position(gold_x, gold_y);
        pit_position = Position(pit_x, pit_y);
    }

    void moveForward()
    {
        player.moveForward();
        return showGameState();
    }

    void turnLeft()
    {
        player.turnLeft();
        return showGameState();
    }

    void turnRight()
    {
        player.turnRight();
        return showGameState();
    }

    void shoot()
    {
       int m=player.fired();
        //...
        if(m<0)
            cout<<"NO SHOT AVAILABLE"<<endl;
        else{
        if(player.Direction()==RIGHT && wumpus.getPosition().getX()>player.getPosition().getX() && wumpus.getPosition().getY()==player.getPosition().getY() )
            {

                wumpus.kill();
            }
           else if(player.Direction()==LEFT && wumpus.getPosition().getX()<player.getPosition().getX() && wumpus.getPosition().getY()==player.getPosition().getY() )
            {

                wumpus.kill();
            }
            if(player.Direction()==UP && wumpus.getPosition().getX()==player.getPosition().getX() && wumpus.getPosition().getY()>player.getPosition().getY() )
            {
                wumpus.kill();
            }
            if(player.Direction()==DOWN && wumpus.getPosition().getX()==player.getPosition().getX() && wumpus.getPosition().getY()<player.getPosition().getY() )
            {
                wumpus.kill();
            }
        }
    }

    void showGameState()
    {
        cout << player.getPositionInfo() << endl;
        cout << player.getDirectionInfo() << endl;

        if (player.isAdjacent(wumpus.getPosition()))
        {
            cout << "stench!" << endl;
        }
         if (player.isAdjacent(pit_position))
        {
            cout << "breeze" << endl;
        }

        if (player.isSamePoint(wumpus.getPosition()))
        {
            cout << "Player is killed!" << endl;
            player.kill();
            cout << "Game over!" << endl;
            ended = true;
        }

        if (player.isSamePoint(gold_position))
        {
            cout << "Got the gold!" << endl;
            cout << "Game ended, you won!" << endl;
            ended = true;
        }

        if (player.isSamePoint(pit_position))
        {
            cout << "Into The Pit!" << endl;
            cout << "Game Over!" << endl;
            ended = true;
        }

    }

    bool isOver()
    {
        return ended;
    }
};

int main()
{
     srand(time(0));
    int c=1, wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y;
    // take the six integers input from file
    // WumpusWorld w(wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y);
    /*FILE *doc=fopen("sheet.txt","r");
    if(doc==NULL)
    {
        cout<<"error opening file"<<endl;
        return -1;
    }
    else
    {
        fscanf(doc,"%d %d %d %d %d %d",&wumpus_x,&wumpus_y,&gold_x,&gold_y,&pit_x,&pit_y);
        fclose(doc);
    }
     WumpusWorld w( wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y);*/
    WumpusWorld w;
    w.showGameState();
    while (!w.isOver())
    {
        cout << "1: move forward" << endl;
        cout << "2: Turn left" << endl;
        cout << "3: Turn right" << endl;
        cout << "4: Shoot" << endl;
        cin >> c;
        if (c == 1)
        {
            w.moveForward();
        }
        else if (c == 2)
        {
            w.turnLeft();
        }
        else if (c == 3)
        {
            w.turnRight();
        }
        else if (c == 4)
        {
            w.shoot();
        }
    }
    return 0;
}
