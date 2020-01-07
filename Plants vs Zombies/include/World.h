#ifndef WORLD_H
#define WORLD_H

#include "color.h"
#include "types.h"
#include "Shop.h"

class World
{
    public:
        World(Shop* shop);
        Shop* m_shop;
        int m_pole_rows;
        int m_pole_cols;
        int m_UI_WIDTH;
        int m_LANE_COUNT;
        int m_SPACE_COUNT;
        int m_coins;
        void init();
        void update();
        void draw();
        void addPlant(PLANTS type, int x, int y);
        void addZombie(ZOMBIES type, int x, int y);
        void addCoins();
        virtual ~World();

    protected:

    private:
};

#endif // WORLD_H
