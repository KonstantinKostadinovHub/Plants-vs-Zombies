#include "Beanshooter.h"

Beanshooter::Beanshooter()
{

}

Beanshooter::~Beanshooter()
{
    //dtor
}

int Beanshooter::action()
{
    //TO-DO  ADD: const file
    if(!m_cooldown){
        m_cooldown = true;
        m_start_time = time(NULL);
        return 2;
    }else if(m_start_time + m_cooldown_time < time(NULL)){
        m_cooldown = false;
        return 0;
    }

}
