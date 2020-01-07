#include "World.h"

World::World(Shop* shop)
{
    m_shop = shop;
}

World::~World()
{
        m_pole_rows = pole_rows;
        m_pole_cols = pole_cols;
        m_UI_WIDTH = 16;
        m_LANE_COUNT = 5;
        m_SPACE_COUNT = 8;
        m_coins = 0;
}

void World::init()
{
    m_shop->initUI();
}

void World::addPlant(PLANTS type, int x, int y)
{

}

void World::addZombie(ZOMBIES type, int x, int y)
{

}

void World::addCoins()
{
    m_coins++;
}

void World::update()
{
    addCoins();
    m_shop->updateUI(m_coins);
    m_shop->buy(m_coins);
    m_shop->plant();
}

void World::draw()
{

}
