#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ncurses/ncurses.h>

const int w = 6;
const int h = 6;
int board[h][w] = {
    { 0, 4, 1, 1, 0, 0 },
    { 0, 4, 0, 4, 0, 0 },
    { 1, 0, 0, 0, 0, 0 },
    { 1, 0, 1, 4, 0, 0 },
    { 1, 0, 1, 0, 1, 0 },
    { 1, 2, 1, 1, 0, 0 },

};

void display_board() {
    for (int i = 0; i < h; ++i ) {
        for (int l = 0; l < w; ++l) {
            if ( board[i][l] == 0) {
                std::cout << "| ---- |";
            } else {
                char value[10] = "";
                sprintf(value, "| %4d |", board[i][l]);
               std::cout << value;
            }
        }
        std::cout << std::endl;
    }
}


