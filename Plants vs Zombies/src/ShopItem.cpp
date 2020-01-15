#include "ShopItem.h"

using namespace std;

ShopItem::ShopItem(PLANTS type, int x, int y, int price, char key, string fileName, string configName)
{
    m_type = type;
    m_fileName = fileName;
    m_configName = configName;
    m_SCALE = 16;
}

ShopItem::~ShopItem()
{
    //dtor
}

void ShopItem::init()
{
    fstream config;
    config.open(m_configName.c_str());
    config >> m_x >> m_y >> m_price >> m_key;
    config.close();
    fstream fin;
    fin.open(m_fileName.c_str());
    for (int i = 0; i < m_SCALE; i++) {
        getline(fin, picture[i]);
    }
    fin.close();
    COLORS color = backgroundColor;
    for (int i = 0; i < m_SCALE; i++) {
        for (int j = 0; j < m_SCALE; j++) {
            switch(picture[i][j]) {
                case 'R' : color = RED; break;
                case 'G' : color = GREEN; break;
                case 'W' : color = WHITE; break;
                case 'D' : color = BLACK; break;
                case 'Y' : color = YELLOW; break;
                case 'B' : color = BLUE; break;
                case 'L' : color = LIGHT_GREEN; break;
                case 'N' : color = BROWN; break;
                default: color = LIGHT_GREY;
            }
            if(color != backgroundColor){
                draw_char('-', m_x + j, m_y + i, color, color);
            }
        }
    }
}
