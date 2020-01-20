#include "Shop.h"

Shop::Shop(int width, int scale)
{
    m_WIDTH = width;
    m_SCALE = scale;
}

Shop::~Shop()
{
    //dtor
}

void Shop::drawInShop(ShopItem* item, COLORS background)
{
    COLORS color = backgroundColor;
    for (int i = 0; i < m_SCALE; i++) {
        for (int j = 0; j < m_SCALE; j++) {
            switch(item->picture[i][j]) {
                case 'R' : color = RED; break;
                case 'G' : color = GREEN; break;
                case 'W' : color = WHITE; break;
                case 'D' : color = BLACK; break;
                case 'Y' : color = YELLOW; break;
                case 'B' : color = BLUE; break;
                case 'L' : color = LIGHT_GREEN; break;
                case 'N' : color = BROWN; break;
                default: color = background;
            }
            if(color != backgroundColor){
                draw_char('-', item->m_x + j, item->m_y + i, color, color);
            }
        }
    }
}


void Shop::initUI()
{
    m_item[0] = new ShopItem(SUNFLOWER, "ShopSunflower.txt");
    m_item[1] = new ShopItem(BEANSHOOTER, "ShopBeanshooter.txt");
    m_item[2] = new ShopItem(WALNUT, "ShopWalnut.txt");
    draw_str("coins:", 0, 0);
    for(int i = 0; i < 3; i++){
        m_item[i]->init();
    }
}

void Shop::updateUI(int coins)
{
    char buff[32];
    sprintf(buff, "%d", coins);
    draw_str(buff, 0, 1);
    for(int i = 0; i < 3; i++){
        canBuyItem((*m_item[i]), coins);
    }
}

void Shop::canBuyItem(ShopItem item, int coins)
{
    if(item.m_price > coins){
        drawInShop(&item, GREY);
    }else{
        drawInShop(&item, LIGHT_GREY);
    }
}
