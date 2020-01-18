#ifndef SHOP_H
#define SHOP_H

#include <stdlib.h>
#include "color.h"
#include "ShopItem.h"
#include "types.h"

using namespace std;

class Shop
{
    public:
        ShopItem* m_item[3];
        int m_WIDTH;
        int m_SCALE;
        int m_plantPosX;
        int m_plantPosY;
        PLANTS m_desiredPlant;
        Shop(int width, int scale);
        void initUI();
        void updateUI(int coins);
        virtual ~Shop();
        void drawInGame(ShopItem* item, int x, int y);
        void drawInShop(ShopItem* item, COLORS background);
        void plant();
        void buy(int& coins);
        void canBuyItem(ShopItem item, int coins);
    protected:

    private:
};

#endif // SHOP_H
