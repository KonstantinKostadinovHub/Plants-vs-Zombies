#ifndef SHOP_H
#define SHOP_H

#include "color.h"
#include "ShopItem.h"
#include "types.h"

class Shop
{
    public:
        int m_WIDTH;
        int m_plantPosX;
        int m_plantPosY;
        PLANTS m_desiredPlant;
        Shop(int width);
        void initUI();
        void updateUI(int coins);
        virtual ~Shop();
        void drawInGame(string fileName, int x, int y);
        void drawInShop(string fileName, int x, int y, COLORS background);
        void plant();
        void buy(int& coins);
        void canBuyItem(ShopItem item, int coins);
        void planting(int x,int y,int z,int p);
    protected:

    private:
};

#endif // SHOP_H
