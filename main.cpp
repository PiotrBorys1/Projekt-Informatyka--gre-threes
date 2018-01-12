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
    for (int i = 0; i < h; ++i )
    {
        for (int l = 0; l < w; ++l)
        {
            if ( board[i][l] == 0) 
            {
                std::cout << "| ---- |";
            } 
            else
            {
                char value[10] = "";
                sprintf(value, "| %4d |", board[i][l]);
               std::cout << value;
            }
        }
        std::cout << std::endl;
    }
}

void move_left() {


    for (int i = 0; i < h; ++i)
    {
        for (int l = 0; l < w-1 ; l++) 
        {
            if (board[i][l] == 0)
            {
                board[i][l] = board[i][l+1];
                board[i][l+1] = 0;
            } 
            else if (board[i][l] == board[i][l+1]) 
            {
                board[i][l] += board[i][l+1];
                board[i][l+1] = 0;
            }


        }
    }

}
void move_right(){



    for (int i = 0; i < h; i++) 
    {
        for (int l = w-1; l >0 ; l--)
        {
            if (board[i][l] == 0)
            {

                board[i][l] = board[i][l-1];
                board[i][l-1] = 0;
            }
            else if (board[i][l] == board[i][l-1])
            {
                board[i][l] += board[i][l-1];
                board[i][l-1] = 0;
            }

        }
    }
}
void move_up(){
initscr();

    for (int i = 0; i < h-1 ; ++i) 
    {
        for (int l = 0; l < w ; l++)
        {
            if (board[i][l] == 0)
            {
                board[i][l] = board[i+1][l];
                board[i+1][l] = 0;
            }
            else if (board[i][l] == board[i+1][l])
            {
                board[i][l] += board[i+1][l];
                board[i+1][l] = 0;
            }


        }
    }
    endwin();
}
void move_down(){



    for (int i = h-1; i >0 ; --i) 
    {
        for (int l = 0; l < w ; l++)
        {
            if (board[i][l] == 0)
            {
                board[i][l] = board[i-1][l];
                board[i-1][l] = 0;
            } 
            else if (board[i][l] == board[i-1][l]) 
            {
                board[i][l] += board[i-1][l];
                board[i-1][l] = 0;
            }



        }
    }
}
void punkty(){
    int punkty=0;
for (int i = 0; i < h ; ++i) 
{
        for (int l = 0; l < w ; l++) 
        {
       if (board[i][l]==16)
       {
                punkty++;
       }
        if (board[i][l]==32)
       {
         punkty+=3;
       }
       if (board[i][l]==64)
       {
         punkty+=7;
       }
       if (board[i][l]==128)
       {
         punkty+=40;
       }
       if (board[i][l]==256)
       {
         punkty+=100;
       }
       if (board[i][l]==512)
      {
        punkty+=300;
       }
       if (board[i][l]==1024)
       {
         punkty+=600;
       }
       if (board[i][l]==2048)
       {
         punkty+=1000;
       }
   }
  }std::cout<<"Punkty gry = "<<punkty<< std::endl;
}

void losowanie(){
    int liczba,i,l;
srand(time(NULL));


              liczba=rand()%3;
              i=rand()%w;
              l=rand()%h;
              if(board[i][l]==0)
              {
                  board[i][l]=board[i][l]+liczba;
              }
              else if (board[i][l]!=0&&board[0][0]==0)
              {
                  board[0][0]+=1;
              }
               else if (board[i][l]!=0&&board[0][0]!=0&&board[5][5]==0)
               {
                   board[5][5]+=2;
               }
              else if (board[i][l]!=0&&board[0][0]!=0&&board[5][5]!=0&&board[0][5]==0)
              {
                  board[0][5]+=1;
              }
              else if (board[i][l]!=0&&board[0][0]!=0&&board[5][5]!=0&&board[0][5]!=0&&board[5][0]==0)
              {
                  board[5][0]+=2;
              }

}


void gra() {


std::cout <<"Witamy w grze threes"<<std::endl;
    punkty();
    display_board();



    int i = 0;

    while (true) {
        std::cout << std::endl;
        std::cin >> i;
        system("cls");
        if ( i == 4 ) {
            move_left();

losowanie();
        }

        else if ( i == 6) 
        {
            move_right();
            losowanie();

        }
        else if ( i == 8)
        {
           move_up();
           losowanie();
        }
        else if (i == 2)
        {
         move_down();
         losowanie();
         }
        else
        {
            std::cout<<"zly klawisz "<<std::endl;
        }

 punkty();
 display_board();
   }
}

int main(){

int rzedy=0, kolumny=0;
int znak=0, znak1=0,i;

    initscr();
    getmaxyx( stdscr, rzedy, kolumny );
    start_color();
     init_pair( 1, COLOR_RED, COLOR_BLUE );
     attron(A_BOLD);
     attron(COLOR_PAIR(1));

     mvprintw(1,1," _____________ ___        ___    ___________ _________    _______   _________  ");
     mvprintw(2,1,"|_____________||  |       |  |  |  ______| | |  ______|  |  _____|  | _______| ");
     mvprintw(3,1,"      | |      |  |       |  |  |  |     | | |  |        |  |       | |        ");
     mvprintw(4,1,"      |-|      |  |       |  |  |  |     | | |  |        |  |       | |        ");
     mvprintw(5,1,"      | |      |  |-------|  |  |  |_____| | |  |______  |  |_____  | |______  ");
     mvprintw(6,1,"      | |      |  |-------|  |  |  |_______| |   ______| |   _____| |_______ | ");
     mvprintw(7,1,"      | |      |  |       |  |  |  |<<>>     |  |        |  |              | | ");
     mvprintw(8,1,"      | |      |  |       |  |  |  | <<>>    |  |        |  |              | | ");
     mvprintw(9,1,"      | |      |  |       |  |  |  |  <<>>   |  |______  |  |_____   ______| | ");
     mvprintw(10,1,"      |_|      |__|       |__|  |__|    <<>> |_________| |________|  |_______| ");
     mvprintw(11,1, "");
     mvprintw(12,1,"");
     mvprintw(13,1,"1.Start gry");
     mvprintw(14,1,"2.Demo gry");
     mvprintw(15,1,"3.Sterowanie");
     mvprintw(16,1,"4.Zakonczenie gry\n");
     getch();
     endwin();

std::cout<<"Wpisz swoj wybor"<<std::endl;
std::cin >> znak;
if (znak==1)
{
    gra();
}
else if (znak==2)
{
    display_board();
    std::cout<<"Wyprobuj teraz gre, masz 8 ruchow"<<std::endl;
   for(i=0;i<=8;i++)
   {
    std::cin >> znak1;
    system("cls");

    if (znak1==4)
    {
       move_left();
    }
    else if (znak1==6)
    {

        move_right();
    }
    else if (znak1==8)
    {
        move_up();
    }
    else if (znak1==2)
    {
        move_down();

    }
    std::cout<<"9.Rozpocznij gre"<<std::endl;
    std::cout<<"0.Zakoncz gre"<<std::endl;
    display_board();
    if (znak1==9)
    {
        system("cls");
        gra();
    }
    else if (znak1==0)
    {

    }
  }
}
else if (znak==3)
{
    std::cout<<"Sterowanie za pomoca klawiszy ";
}
else if (znak==4)
{
}
getch();
return 0;
}


