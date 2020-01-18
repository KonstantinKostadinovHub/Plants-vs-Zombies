#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "color.h"
#include "types.h"
#include "Shop.h"
#include "Beanshooter.h"
#include "Z_Default.h"
#include "Bullet.h"

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
