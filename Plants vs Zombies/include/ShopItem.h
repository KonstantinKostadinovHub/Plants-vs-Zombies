#ifndef SHOPITEM_H
#define SHOPITEM_H

#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>
#include "color.h"

using namespace std;

class ShopItem
{
    public:
        ShopItem(int x, int y, int price, char key);
        int m_x, m_y;
        int m_price;
        char m_key;
        string picture[12];
        void init(string fileName);
        virtual ~ShopItem();

    protected:

    private:
};

#endif // SHOPITEM_H
