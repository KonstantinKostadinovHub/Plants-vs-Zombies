#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "color.h"
#include "types.h"
#include "Shop.h"
#include "Z_Default.h"
#include "Plant.h"

class World
{
    public:
        World();
        vector <Zombie*> m_zombies;
        vector <Zombie*> m_waitingZombies;
        vector <Plant*> m_plants;
        Shop* m_shop;
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
        void addPlant(PLANTS type, int x, int y);
        void addZombie(ZOMBIES type, int x, int y);
        void addCoins();
        virtual ~World();
        void music();
    protected:

    private:
};

#endif // WORLD_H
