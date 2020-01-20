#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "color.h"
#include <iostream>
#include <winuser.h>
#include <fstream>
#include <windows.h>


const int SCALE = 16;
const int Z_DEF_HP = 100;

class Zombie{
    public:
        string picture[SCALE];
        int m_x, m_y;
        int m_health;
        int m_UI_WIDTH = 16;

        Zombie();
        virtual ~Zombie();
        virtual void init(string file_name, int y);
        virtual void clearPrint();
        virtual void print();
        virtual void moveZombie();
        virtual void takeDamage(int damage);
    protected:

    private:
};

#endif // ZOMBIE_H
