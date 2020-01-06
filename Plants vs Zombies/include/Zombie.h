#ifndef ZOMBIE_H
#define ZOMBIE_H


class Zombie
{
    public:
        int m_health;
        Zombie(int health);
        virtual ~Zombie();
        virtual void moveZombie();
        virtual void action();
    protected:

    private:
};

#endif // ZOMBIE_H
