#ifndef SHOPITEM_H
#define SHOPITEM_H

#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>
#include <cstdlib>
#include "color.h"
#include "types.h"

using namespace std;

class ShopItem
{
    public:
        ShopItem(PLANTS type, int x, int y, int price, char key, string fileName, string configName);
        string m_configName;
        PLANTS m_type;
        int m_x, m_y;
        int m_price;
        int m_SCALE;
        char m_key;
        string m_fileName;
        string picture[16];
        void init();
        virtual ~ShopItem();

    protected:

    private:
};

#endif // SHOPITEM_H
