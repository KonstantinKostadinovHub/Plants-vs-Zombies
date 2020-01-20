#ifndef BEANSHOOTER_H
#define BEANSHOOTER_H

#include "Plant.h"
#include "Bullet.h"
#include <ctime>

class Beanshooter : public Plant
{
    public:
        time_t start = time(NULL);
        bool m_cooldown;
        time_t m_start_time;
        time_t m_cooldown_time = 3;
        virtual int action();
        Beanshooter();
        virtual ~Beanshooter();
    protected:

    private:
};

#endif // BEANSHOOTER_H
