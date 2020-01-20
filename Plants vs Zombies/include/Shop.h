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
        //TO-DO const number
        ShopItem* m_item[3];
        int m_WIDTH;
        int m_SCALE;
        Shop(int width, int scale);
        void initUI();
        void updateUI(int coins);
        virtual ~Shop();
        void drawInShop(ShopItem* item, COLORS background);
        void canBuyItem(ShopItem item, int coins);
    protected:

    private:
};

#endif // SHOP_H
