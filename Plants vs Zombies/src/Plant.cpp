#include "Plant.h"

Plant::Plant()
{

}

Plant::~Plant()
{
    //dtor
}

void Plant::init(int x, int y, string configName)
{

    m_SCALE = 16;
    m_UI_WIDTH = 16;
    m_x = x;
    m_y = y;
    m_configName = configName;

    fstream config;
    config.open(m_configName.c_str());
    config >> m_health >> m_damage  >> m_gfxName;
    config.close();

    fstream fin;
    fin.open(m_gfxName.c_str());
    for (int i = 0; i < m_SCALE; i++) {
        getline(fin, m_picture[i]);
    }
    fin.close();
    COLORS color = backgroundColor;
    for (int i = 0; i < m_SCALE; i++) {
        for (int j = 0; j < m_SCALE; j++) {
            switch(m_picture[i][j]) {
                case 'R' : color = RED; break;
                case 'G' : color = GREEN; break;
                case 'W' : color = WHITE; break;
                case 'D' : color = BLACK; break;
                case 'Y' : color = YELLOW; break;
                case 'B' : color = BLUE; break;
                case 'L' : color = LIGHT_GREEN; break;
                case 'N' : color = BROWN; break;
                default: color = backgroundColor;
            }
            if(color != backgroundColor){
                draw_char('-', m_x * m_SCALE + m_UI_WIDTH + j, m_y * m_SCALE + i, color, color);
            }
        }
    }
}

void Plant::print()
{
    COLORS color = backgroundColor;
    for (int i = 0; i < m_SCALE; i++) {
        for (int j = 0; j < m_SCALE; j++) {
            switch(m_picture[i][j]) {
                case 'R' : color = RED; break;
                case 'G' : color = GREEN; break;
                case 'W' : color = WHITE; break;
                case 'D' : color = BLACK; break;
                case 'Y' : color = YELLOW; break;
                case 'B' : color = BLUE; break;
                case 'L' : color = LIGHT_GREEN; break;
                case 'N' : color = BROWN; break;
                default: color = backgroundColor;
            }
            if(color != backgroundColor){
                draw_char('-', m_x * m_SCALE + m_UI_WIDTH + j, m_y * m_SCALE+ i, color, color);
            }
        }
    }
}

void Plant::action()
{

}
