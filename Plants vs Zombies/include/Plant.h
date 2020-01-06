#ifndef PLANT_H
#define PLANT_H


class Plant
{
    public:
        int m_health;
        Plant(int health);
        virtual ~Plant();
        virtual void action();

    protected:

    private:
};

#endif // PLANT_H
