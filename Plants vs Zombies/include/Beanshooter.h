#ifndef BEANSHOOTER_H
#define BEANSHOOTER_H

#include "Plant.h"
#include "Bullet.h"

class Beanshooter : public Plant
{
    public:
        virtual int action();
        Beanshooter();
        virtual ~Beanshooter();
    protected:

    private:
};

#endif // BEANSHOOTER_H
