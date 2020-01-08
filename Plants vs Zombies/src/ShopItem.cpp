#include "ShopItem.h"

using namespace std;

ShopItem::ShopItem(int x, int y, int price, char key, string fileName)
{
    m_x = x;
    m_y = y;
    m_price = price;
    m_key = key;
    m_fileName = fileName;
}

ShopItem::~ShopItem()
{
    //dtor
}

void ShopItem::init()
{
    fstream fin;
    fin.open(m_fileName.c_str());
    for (int i = 0; i < 12; i++) {
        getline(fin, picture[i]);
    }
    fin.close();
    COLORS color = backgroundColor;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
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
