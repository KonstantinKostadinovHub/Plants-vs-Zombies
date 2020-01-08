#include "Shop.h"
#include "ShopItem.h"
ShopItem sunflowerShop(0, 2, 2, '1',"sunflower.txt");
ShopItem beanShooterShop(0, 14, 4, '2',"beanshooter.txt");

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

void Shop::draw(string fileName, int x, int y)
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
                default: color = LIGHT_GREY;
            }
            if(color != backgroundColor){
                draw_char('-',m_WIDTH + x + j, y + i, color, color);
            }
        }
    }
}

void Shop::initUI()
{
    sunflowerShop.init(/*"sunflower.txt"*/);
    beanShooterShop.init(/*"beanshooter.txt"*/);

    draw_str("coins:", 0, 0);
}

void Shop::updateUI(int coins)
{
    char buff[32];
    itoa(coins, buff, 10);
    draw_str(buff, 0, 1);
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
        }
    }
}

void Shop::plant(){
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            draw_char('-', m_WIDTH + m_plantPosX + j, m_plantPosY + i, backgroundColor, backgroundColor);
        }
    }
    if(m_desiredPlant != NOPLANT){
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                draw_char('-', m_WIDTH + m_plantPosX * 12 + j, m_plantPosY * 12 + i, backgroundColor, backgroundColor);
            }
        }
        if(GetAsyncKeyState('W') && m_plantPosY > 0){
            m_plantPosY --;
        }else if(GetAsyncKeyState('A') && m_plantPosX > 0){
            m_plantPosX --;
        }else if(GetAsyncKeyState('S')){
            m_plantPosY ++;
        }else if(GetAsyncKeyState('D')){
            m_plantPosX ++;
        }
    }
    if(m_desiredPlant == SUNFLOWER){
        draw("sunflower.txt", m_plantPosX, m_plantPosY);
    }else if(m_desiredPlant == BEANSHOOTER){
        draw("beanshooter.txt", m_plantPosX, m_plantPosY);
    //}else if(m_desiredPlant==BEANSHOOTER){
       // draw("ZOMBIE.txt", m_plantPosX, m_plantPosY);
    }
}
void Shop::planting(int x,int y,int z,int p)
{
    x=m_plantPosX;
    y=m_plantPosY;
    z=new_m_plantPosX;
    p=new_m_plantPosY;
    for(int i=0;i<40;i++){//Пробни стойности. После ще го направя с раЕмера на вектора!
    plant();
    if(GetAsyncKeyState('Q'))
    {
        new_m_plantPosX=m_plantPosX;
        new_m_plantPosY=m_plantPosY;
        m_plantPosX=12;
        m_plantPosY=2;
    }
    }


}
