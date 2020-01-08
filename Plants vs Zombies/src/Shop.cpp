#include "Shop.h"

ShopItem sunflowerShop(0, 2, 25, '1', "sunflower.txt");
ShopItem beanShooterShop(0, 14, 50, '2', "beanshooter.txt");
ShopItem walnutShop(0, 26, 50, '3', "walnut.txt");

Shop::Shop(int width)
{
    m_desiredPlant = NOPLANT;
    m_plantPosX = 0;
    m_plantPosY = 0;
    m_WIDTH = width;
}

Shop::~Shop()
{
    //dtor
}

void Shop::drawInGame(string fileName, int x, int y)
{
    x *= 12;
    y *= 12;
    string picture[12];
    fstream fin;
    fin.open(fileName.c_str());
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
                default: color = backgroundColor;
            }
            if(color != backgroundColor){
                draw_char('-',m_WIDTH + x + j, y + i, color, color);
            }
        }
    }
}

void Shop::drawInShop(string fileName, int x, int y, COLORS background)
{
    string picture[12];
    fstream fin;
    fin.open(fileName.c_str());
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
                default: color = background;
            }
            if(color != backgroundColor){
                draw_char('-', x + j, y + i, color, color);
            }
        }
    }
}


void Shop::initUI()
{
    draw_str("coins:", 0, 0);
    sunflowerShop.init();
    beanShooterShop.init();
    walnutShop.init();
}

void Shop::updateUI(int coins)
{
    char buff[32];
    itoa(coins, buff, 10);
    draw_str(buff, 0, 1);

    canBuyItem(sunflowerShop, coins);
    canBuyItem(beanShooterShop, coins);
    canBuyItem(walnutShop, coins);
}

void Shop::canBuyItem(ShopItem item, int coins)
{
    if(item.m_price > coins){
        drawInShop(item.m_fileName, item.m_x, item.m_y, GREY);
    }else{
        drawInShop(item.m_fileName, item.m_x, item.m_y, LIGHT_GREY);
    }
}

void Shop::buy(int& coins)
{
    if(m_desiredPlant == NOPLANT){
        if(GetAsyncKeyState(sunflowerShop.m_key) && sunflowerShop.m_price <= coins)
        {
            coins -= sunflowerShop.m_price;
            m_desiredPlant = SUNFLOWER;
        }else if(GetAsyncKeyState(beanShooterShop.m_key) && beanShooterShop.m_price <= coins){
            coins -= beanShooterShop.m_price;
            m_desiredPlant = BEANSHOOTER;
        }else if(GetAsyncKeyState(walnutShop.m_key) && walnutShop.m_price <= coins){
            coins -= walnutShop.m_price;
            m_desiredPlant = WALNUT;
        }
    }
}
void Shop::plant(){
    if(m_desiredPlant != NOPLANT){
        int oldX = m_plantPosX, oldY = m_plantPosY;
        if(GetAsyncKeyState('W') && m_plantPosY > 0){
            m_plantPosY --;
        }else if(GetAsyncKeyState('A') && m_plantPosX > 0){
            m_plantPosX --;
        }else if(GetAsyncKeyState('S')){
            m_plantPosY ++;
        }else if(GetAsyncKeyState('D')){
            m_plantPosX ++;
        }
        if(oldX != m_plantPosX || oldY != m_plantPosY){
            for (int i = 0; i < 12; i++) {
                for (int j = 0; j < 12; j++) {
                    draw_char('-', m_WIDTH + oldX * 12 + j, oldY * 12 + i, backgroundColor, backgroundColor);
                }
            }
        }
    }
    if(m_desiredPlant == SUNFLOWER){
        drawInGame(sunflowerShop.m_fileName, m_plantPosX, m_plantPosY);
    }else if(m_desiredPlant == BEANSHOOTER){
        drawInGame(beanShooterShop.m_fileName, m_plantPosX, m_plantPosY);
    }else if(m_desiredPlant == WALNUT){
        drawInGame(walnutShop.m_fileName, m_plantPosX, m_plantPosY);
    }
}
