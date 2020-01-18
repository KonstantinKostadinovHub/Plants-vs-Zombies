#include <iostream>

#include <ctime>
#include "World.h"
#include "ShopItem.h"
#include "Beanshooter.h"

using namespace std;

bool end_game = false;


World world;
int main()
{
    clock_t startTime = clock();

    Z_Default* S_Zombie1 = new Z_Default;
    Z_Default* S_Zombie2 = new Z_Default;
    Z_Default* S_Zombie3 = new Z_Default;

    world.m_zombies.push_back(S_Zombie1);
    world.m_zombies.push_back(S_Zombie2);
    world.m_zombies.push_back(S_Zombie3);
    //world.music();
    //музиката забавя стартирането на играта Ицо - от Косьо

    world.initWorld();

    while(!end_game){
        if(GetAsyncKeyState('E')){
            world.addPlant();
        }
        world.update();
        world.draw();
        Sleep(100);
    }

    return 0;
}
