#ifndef PLANT_H
#define PLANT_H

#include "color.h"
#include "types.h"
#include <iostream>
#include <winuser.h>
#include <fstream>
#include <windows.h>

class Plant
{
    public:
        string m_configName;
        int m_x, m_y;
        int m_damage;
        int m_health;
        string m_gfxName;
        PLANTS m_type;
        int m_SCALE;
        int m_UI_WIDTH;
        string m_picture[16];

        friend istream& operator>> (istream& in, Plant& plant);
        Plant();
        virtual ~Plant();
        virtual void init(int x, int y, string configName);
        virtual void clearPrint();
        virtual void print();
        virtual int action();

    protected:

    private:
};

#endif // PLANT_H
