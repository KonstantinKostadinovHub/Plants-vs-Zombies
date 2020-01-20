#ifndef BULLET_H
#define BULLET_H

#include "Plant.h"

class Bullet : public Plant
{
    public:
        Bullet();
        virtual void init(int x, int y, string configName);
        virtual int action();
        virtual void print();
        virtual ~Bullet();

    protected:

    private:
};

#endif // BULLET_H
