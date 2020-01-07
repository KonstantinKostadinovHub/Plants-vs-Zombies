#include "color.h"

HANDLE hConsoleOutput = ::GetStdHandle(STD_OUTPUT_HANDLE);
COORD screen_buf = {pole_rows , pole_cols};
CHAR_INFO blank_screen[(pole_rows) * (pole_cols)] = {0};
void draw_char(char ch, int x, int y, COLORS foreground_color, COLORS background_color) {
    CHAR_INFO ch_info;
    ch_info.Char.AsciiChar = ch;
    ch_info.Attributes = foreground_color | (background_color << 4);

    COORD buf_size = {1, 1};
    COORD buf_coord = {0, 0};
    SMALL_RECT screen_pos = {x, y, x+1, y+1};
    ::WriteConsoleOutput(hConsoleOutput, &ch_info, buf_size, buf_coord, &screen_pos);

}

void clear_screen() {
    COORD buf_coord = {0, 0};
    SMALL_RECT screen_pos = {0, 0, screen_buf.X, screen_buf.Y};
    ::WriteConsoleOutput(hConsoleOutput, blank_screen, screen_buf, buf_coord, &screen_pos);
}

void set_background() {
    for (int i = 0; i < screen_buf.X; i++) {
        for (int j = 0; j < screen_buf.Y; j++) {
             draw_char(' ', j, i, PINK, LIGHT_GREEN);
        }
    }
}


void init(){

    SMALL_RECT rect = {0, 0, screen_buf.X, screen_buf.Y};

    ::SetConsoleScreenBufferSize(hConsoleOutput, screen_buf);
    ::SetConsoleWindowInfo(hConsoleOutput, TRUE, &rect);
    ::SetConsoleTitle("Plants vs Zombies");
    set_background();

}

void draw_str(char* str, int r, int c){
    for(int i = 0; str[i]!='\0'; i++){
        draw_char(str[i], r + i, c, BLACK, backgroundColor);
    }
}
