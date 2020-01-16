#ifndef BULLET_H
#define BULLET_H

#include "Plant.h"

class Bullet : public Plant
{
    public:
        virtual void init(int x, int y, string configName);
        virtual void action();
        virtual void print();
        Bullet();
        virtual ~Bullet();

    protected:

    private:
};

#endif // BULLET_H
