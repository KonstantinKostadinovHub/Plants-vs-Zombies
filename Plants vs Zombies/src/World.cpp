#include "World.h"
#include <vector>
#include<windows.h>
World::World()
{
        m_pole_rows = pole_rows;
        m_pole_cols = pole_cols;
        m_UI_WIDTH = 16;
        m_LANE_COUNT = 5;
        m_SPACE_COUNT = 8;
        m_SCALE = 16;
        m_coins = 0;
        m_zombiesWaveConfig = "zombies_1.txt";
}

World::~World()
{

}

void World::initWorld()
{
    init();
    srand(time(NULL));
    m_shop = new Shop(m_UI_WIDTH, m_SCALE);
    m_shop->initUI();
    fstream configZombies;
    configZombies.open(m_zombiesWaveConfig.c_str());
    int buff;
    configZombies >> buff;
    int zombiesPositions[buff];
    for(int i; i < buff; i++){
        configZombies >> zombiesPositions[i];
    }
    configZombies.close();
    //zombies
    for(int i = 0; i < m_zombies.size(); i++){
        m_zombies[i]->init("zombie.txt", zombiesPositions[i] * m_SCALE);
    }
}

bool World::checkForCollision(Zombie zombie, Bullet bullet){
    //TO-DO the number in the for-cycle must not be hard-coded
    if(bullet.m_x + 10 >= zombie.m_x && bullet.m_y == zombie.m_y){
        return true;
    }
    return false;
}

void World::addPlant()
{
    PLANTS type = m_shop->m_desiredPlant;
    if(type != NOPLANT){
        int x = m_shop->m_plantPosX, y = m_shop->m_plantPosY;
        if(type == BEANSHOOTER){
            Plant* beanshooter1 = new Beanshooter();
            beanshooter1->init(x, y, "BeanshooterConfig.txt");
            m_plants.push_back(beanshooter1);
        }else if(type == WALNUT){
            Plant* walnut1 = new walnut();
            walnut1->init(x, y, "WalnutConfig.txt");
            m_plants.push_back(walnut1);
        }else if(type ==SUNFLOWER){
            Plant* sunflower1 = new Sunflower();
            sunflower1->init(x, y, "SunflowerConfig.txt");
            m_plants.push_back(sunflower1);
        }
        m_shop->m_desiredPlant = NOPLANT;
        m_shop->m_plantPosX = 0;
        m_shop->m_plantPosY = 0;
    }
}

void World::addZombie(ZOMBIES type, int x, int y)
{

}

void World::addCoins()
{
    m_coins++;
}

void World::cleaner()
{
    for(int i=0; i < m_zombies.size(); i++){
        if(m_zombies[i]->m_health <= 0){
            m_zombies[i]->clearPrint();
            m_zombies.erase(m_zombies.begin() + i);
            i--;
        }
    }
    for(int i=0; i < m_plants.size(); i++){
        if(m_plants[i]->m_health <= 0){
            m_plants[i]->clearPrint();
            m_plants.erase(m_plants.begin() + i);
            i--;
        }
    }
    for(int i = 0; i < m_bullets.size(); i++){
        if(m_bullets[i]->m_health <= 0){
            m_bullets[i]->clearPrint();
            m_bullets.erase(m_bullets.begin() + i);
            i--;
        }
    }
}

void World::update()
{
    //zombies
    for(int i=0; i < m_zombies.size(); i++){
        m_zombies[i]->moveZombie();
    }
    //plants
    for(int i=0; i < m_plants.size(); i++){
        int value = m_plants[i]->action();
        if(value == SPAWN_BULLET){
            Bullet* bullet = new Bullet();
            bullet->init(m_plants[i]->m_x, m_plants[i]->m_y, "BulletConfig.txt");
            m_bullets.push_back(bullet);
        }else if(value == ADD_MONEY){
            m_coins+=25;
        }
    }

    //bullet
    for(int i=0; i < m_bullets.size(); i++){
        m_bullets[i]->action();
    }

    //collision check
    for(int i = 0; i < m_zombies.size(); i++){
        for(int j = 0; j < m_bullets.size(); j++){
            if(checkForCollision(*m_zombies[i], *m_bullets[j])){
                m_zombies[i]->takeDamage(10);
                m_bullets[j]->m_health = 0;
            }
        }
    }

    //shop
    addCoins();
    m_shop->updateUI(m_coins);
    m_shop->buy(m_coins);
    m_shop->plant();
}

void World::draw()
{
    //zombies
    for(int i = 0; i < m_zombies.size(); i++){
        m_zombies[i]->print();
    }
    //plants
    for(int i = 0; i < m_plants.size(); i++){
        m_plants[i]->print();
    }
    //bullets
    for(int i=0; i < m_bullets.size(); i++){
        m_bullets[i]->print();
    }
}

void World::music(){

Beep(277.18,300);

Beep(293.66,350);
Beep(277.18,300);
Beep(293.66,350);

Beep(233.08,300);
Beep(196,700);
Beep(233.08,300);
Beep(196,700);
Beep(277.18,300);
Beep(196,700);

}
