#include "Sunflower.h"

Sunflower::Sunflower()
{
    //ctor
}

Sunflower::~Sunflower()
{
    //dtor
}
int Sunflower::action(){
//adding coins(+25 for every 5 seconds)
if(!m_cooldown){
    m_cooldown = true;
    m_start_time = time(NULL);
    return 1;
}
else{
    if(m_start_time + m_cooldown_time < time(NULL)){
        m_cooldown = false;
        return 0;
    }

}


//TO DO add constant file
}
