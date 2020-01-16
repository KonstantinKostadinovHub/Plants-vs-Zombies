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
    world.initWorld();

    Z_Default* S_Zombie1 = new Z_Default;
    S_Zombie1->init("zombie.txt", world.m_pole_cols + 10, 0 * world.m_SCALE);
    S_Zombie1->print();
    Z_Default* S_Zombie2 = new Z_Default;
    S_Zombie2->init("zombie.txt", world.m_pole_cols + 10, 1 * world.m_SCALE);
    S_Zombie2->print();
    Z_Default* S_Zombie3 = new Z_Default;
    S_Zombie3->init("zombie.txt", world.m_pole_cols + 10, 2 * world.m_SCALE);
    S_Zombie3->print();

    Plant* beanshooter1 = new Beanshooter();
    beanshooter1->init(0, 0, "BeanshooterConfig.txt");
    beanshooter1->print();

    world.m_zombies.push_back(S_Zombie1);
    world.m_zombies.push_back(S_Zombie2);
    world.m_zombies.push_back(S_Zombie3);
    //world.music();
    //музиката забавя стартирането на играта Ицо - от Косьо
    while(!end_game){

        world.update();
        world.draw();
        Sleep(100);
    }

    return 0;
}
