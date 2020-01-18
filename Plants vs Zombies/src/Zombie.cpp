#include "Zombie.h"


Zombie::Zombie(){
    //ctor
}

Zombie::~Zombie(){
    //dtor
}

void Zombie::init(string file_name, int x, int y){
    m_x = x;
    m_y = y;
    fstream fin;
    fin.open(file_name.c_str());
    for(int i = 0; i < SCALE; i++){
        getline(fin, picture[i]);
    }
    fin.close();
}

void Zombie::print(){
    int x = m_x;
    int y = m_y;
    COLORS color;
    for(int i=0; i<SCALE; i++){
        for(int j=0; j<SCALE; j++){
            switch(picture[j][i]){
                case 'R' : color = RED; break;
                case 'G' : color = GREEN; break;
                case 'W' : color = WHITE; break;
                case 'D' : color = BLACK; break;
                case 'Y' : color = YELLOW; break;
                case 'B' : color = BLUE; break;
                case 'L' : color = LIGHT_GREEN; break;
                case 'N' : color = BROWN; break;
                default: color=backgroundColor;
                //model
            }
            if(color != backgroundColor){
                draw_char('*', x+i, y+j, color, color);
            }
        }
    }
}

void Zombie::moveZombie(){
    for(int i=0; i<SCALE; i++){
        for(int j=0; j<SCALE; j++){
            draw_char('\0', m_x+i, m_y+j, backgroundColor, backgroundColor);
        }
    }
    m_x--;
    if(m_x<0){return;}
}
