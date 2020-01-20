#include "Bullet.h"

Bullet::Bullet()
{
    //ctor
}

Bullet::~Bullet()
{
    //dtor
}

void Bullet::init(int x, int y, string configName)
{

    m_SCALE = 16;
    m_UI_WIDTH = 16;
    m_x = x * m_SCALE;
    m_y = y * m_SCALE;
    m_configName = configName;

    fstream config;
    config.open(m_configName.c_str());
    config >> *this;
    config.close();

    fstream fin;
    fin.open(m_gfxName.c_str());
    for (int i = 0; i < m_SCALE; i++) {
        getline(fin, m_picture[i]);
    }
    fin.close();
}

int Bullet::action()
{
    m_x++;
    return 0;
}

void Bullet::print()
{
    COLORS color = backgroundColor;
    int x = m_x - 1;
    for (int i = 0; i < m_SCALE; i++) {
        for (int j = 0; j < m_SCALE; j++) {
            switch(m_picture[i][j]) {
                case 'N' : color = BROWN; break;
                default: color = backgroundColor;
            }
            if(color != backgroundColor){
                draw_char('-', x + m_UI_WIDTH + j, m_y + i,   backgroundColor, backgroundColor);
            }
        }
    }
    for (int i = 0; i < m_SCALE; i++) {
        for (int j = 0; j < m_SCALE; j++) {
            switch(m_picture[i][j]) {
                case 'N' : color = BROWN; break;
                default: color = backgroundColor;
            }
            if(color != backgroundColor){
                draw_char('-', m_x + m_UI_WIDTH + j, m_y + i, color, color);
            }
        }
    }
}

