#ifndef SUNFLOWER_H
#define SUNFLOWER_H
#include "Plant.h"
#include <ctime>
class Sunflower : public Plant
{
    public:
        time_t start = time(NULL);
        bool m_cooldown;
        time_t m_start_time;
        time_t m_cooldown_time=5;
        int addingMoney=25;
        virtual int action();
        Sunflower();
        virtual ~Sunflower();
    protected:

    private:
};

#endif // SUNFLOWER_H
