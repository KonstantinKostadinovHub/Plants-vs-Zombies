#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "color.h"
#include <iostream>
#include <winuser.h>
#include <fstream>
#include <windows.h>


const int SCALE = 16;
const int Z_DEF_HP = 8;

class Zombie{
    public:
        string picture[SCALE];
        int m_x, m_y;
        int m_health;
        bool m_status=false;

        Zombie();
        virtual ~Zombie();
        virtual void init(string file_name, int x, int y);
        virtual void print();
        virtual void moveZombie();

    protected:

    private:
};

#endif // ZOMBIE_H
