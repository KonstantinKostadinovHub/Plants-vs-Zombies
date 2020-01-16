#ifndef BEANSHOOTER_H
#define BEANSHOOTER_H

#include "Plant.h"

class Beanshooter : public Plant
{
    public:
        virtual void action();
        Beanshooter();
        virtual ~Beanshooter();
    protected:

    private:
};

#endif // BEANSHOOTER_H
