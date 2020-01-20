#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "color.h"
#include "types.h"
#include "Shop.h"
#include "Beanshooter.h"
#include "Z_Default.h"
#include "Bullet.h"
#include "walnut.h"
#include "Sunflower.h"
#include <cstdlib>
#include <ctime>


static const int SPAWN_BULLET = 2;
static const int ADD_MONEY = 1;

class World
{
    public:
        World();
        vector <Zombie*> m_zombies;
        vector <Zombie*> m_waitingZombies;
        vector <Plant*> m_plants;
        vector <Bullet*> m_bullets;
        Shop* m_shop;
        string m_zombiesWaveConfig;
        int m_zombiesInWave;
        int m_pole_rows;
        int m_pole_cols;
        int m_SCALE;
        int m_UI_WIDTH;
        int m_LANE_COUNT;
        int m_SPACE_COUNT;
        int m_coins;
        int m_plantPosX;
        int m_plantPosY;
        ShopItem* m_item[3];
        PLANTS m_desiredPlant;
        void drawInGame(ShopItem* item, int x, int y);
        void buy(int& coins);
        void plant();
        void cleaner();
        void initWorld();
        void update();
        void draw();
        void addPlant();
        void addZombie(ZOMBIES type, int x, int y);
        void addCoins();
        bool checkForCollision(Zombie zombie, Bullet bullet);
        virtual ~World();
        void music();
    protected:

    private:
};

#endif // WORLD_H
