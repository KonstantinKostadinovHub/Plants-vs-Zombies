#ifndef SHOP_H
#define SHOP_H

#include "color.h"
#include "ShopItem.h"
#include "types.h"

class Shop
{
    public:
        Shop(int width);
        void initUI();
        void updateUI(int coins);
        virtual ~Shop();
        void draw(string fileName, int x, int y);
        void plant();
        void buy(int& coins);
        int m_WIDTH;
        int m_plantPosX;
        int m_plantPosY;
        PLANTS m_desiredPlant;
    protected:

    private:
};

#endif // SHOP_H