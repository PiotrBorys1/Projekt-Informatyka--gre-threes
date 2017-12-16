#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ncurses/ncurses.h>

const int w = 4;
const int h = 4;
int board[h][w] = {
    { 0, 4, 1, 1 },
    { 0, 4, 0, 4 },
    { 1, 0, 0, 0 },
    { 1, 0, 1, 4 },
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

void move_left() {


    for (int i = 0; i < h; ++i) {
        for (int l = 0; l < w-1 ; l++) {
            if (board[i][l] == 0) {
                board[i][l] = board[i][l+1];
                board[i][l+1] = 0;
            } else if (board[i][l] == board[i][l+1]) {
                board[i][l] += board[i][l+1];
                board[i][l+1] = 0;
            }
            if (board[0][0]==0){
               board[0][0]=board[0][0]+1;
            }
            else{board[0][0]==board[0][0];}

        }
    }

}
void move_right(){



    for (int i = 0; i < h; i++) {
        for (int l = w-1; l >0 ; l--) {
            if (board[i][l] == 0) {

                board[i][l] = board[i][l-1];
                board[i][l-1] = 0;
            }
            else if (board[i][l] == board[i][l-1]) {
                board[i][l] += board[i][l-1];
                board[i][l-1] = 0;
            }if (board[0][0]==0){
               board[0][0]=board[0][0]+1;
            }
            else{board[0][0]==board[0][0];}

        }
    }
}
void move_up(){



    for (int i = 0; i < h-1 ; ++i) {
        for (int l = 0; l < w ; l++) {
            if (board[i][l] == 0) {
                board[i][l] = board[i+1][l];
                board[i+1][l] = 0;
            } else if (board[i][l] == board[i+1][l]) {
                board[i][l] += board[i+1][l];
                board[i+1][l] = 0;
            }if (board[0][0]==0){
               board[0][0]=board[0][0]+1;
            }
            else{board[0][0]==board[0][0];}

        }
    }
}
void move_down(){



    for (int i = h-1; i >0 ; --i) {
        for (int l = 0; l < w ; l++) {
            if (board[i][l] == 0) {
                board[i][l] = board[i-1][l];
                board[i-1][l] = 0;
            } else if (board[i][l] == board[i-1][l]) {
                board[i][l] += board[i-1][l];
                board[i-1][l] = 0;
            }if (board[0][0]==0){
               board[0][0]=board[0][0]+1;
            }
            else{board[0][0]==board[0][0];}

        }
    }
}
void punkty(){
    int punkty=0;
for (int i = 0; i < h ; ++i) {
        for (int l = 0; l < w ; l++) {
       if (board[i][l]==16){
                punkty++;}
            if (board[i][l]==32){
                punkty+=3;}
                if (board[i][l]==64){
                punkty+=7;}
                     if (board[i][l]==128){
                    punkty+=40;}
                     if (board[i][l]==256){
                    punkty+=100;}
                     if (board[i][l]==512){
                    punkty+=300;}
                     if (board[i][l]==1024){
                    punkty+=600;}
                     if (board[i][l]==2048){
                    punkty+=1000;}
                       }
    }std::cout<<punkty<< std::endl;
}


int main() {
    display_board();
    int i = 0;

    while (true) {
        std::cout << std::endl;
        std::cin >> i;
        system("cls");
        if ( i == 4 ) {
            move_left();


        }

        else if ( i == 6) {
            move_right();


        }
        else if ( i == 8) {
                move_up();

        }
        else if (i == 2) {
                move_down();

                }
punkty();

        display_board();

    }


    return 0;
}



