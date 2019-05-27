#include <ncurses.h>
#include <iostream>
using namespace std;
int main()
{
WINDOW *map_4;
WINDOW *win_push;
WINDOW *win_level;
WINDOW *win_step;

initscr();
curs_set(0);
noecho();
start_color();
init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
init_pair(2,COLOR_RED,COLOR_BLUE);
keypad(stdscr, TRUE);

resize_term(27,27);
attron(COLOR_PAIR(2));
border('*','*','*','*','*','*','*','*');
mvprintw(2,7,"push box game");
attroff(COLOR_PAIR(2));
refresh();

int level_4[10][10]={{4,4,4,4,4,4,4,4,4,4},{4,1,1,1,1,1,1,1,4,4},{4,1,0,0,0,0,0,1,4,4},{4,1,0,3,2,3,0,1,4,4},{4,1,0,2,3,2,0,1,4,4},{4,1,0,3,2,3,0,1,4,4},{4,1,0,2,3,2,0,1,4,4},{4,1,0,0,0,0,0,1,4,4},{4,1,1,1,1,1,1,1,4,4},{4,4,4,4,4,4,4,4,4,4}};

map_4=newwin(12,14,10,7);
wborder(map_4,'|','|','-','-','+','+','+','+');
for(int i=0;i<=9;i++){
    for(int j=0;j<=9;j++){
        if(level_4[i][j]==1){
            wattron(map_4,COLOR_PAIR(1));
            mvwprintw(map_4,i+1,j+3,"#");
            wattroff(map_4,COLOR_PAIR(1));
        }
        else if(level_4[i][j]==2) mvwprintw(map_4,i+1,j+3,"*");
        else if(level_4[i][j]==3) mvwprintw(map_4,i+1,j+3,"@");
        else mvwprintw(map_4,i+1,j+3," ");
    }
}
attron(COLOR_PAIR(2));
win_level=newwin(4,7,4,2);
wborder(win_level,'|','|','-','-','+','+','+','+');
mvwprintw(win_level,1,1,"Level");
mvwprintw(win_level,2,1,"0");
win_push=newwin(4,7,4,10);
wborder(win_push,'|','|','-','-','+','+','+','+');
mvwprintw(win_push,1,1,"Push");
mvwprintw(win_push,2,1,"0");
win_step=newwin(4,7,4,18);
wborder(win_step,'|','|','-','-','+','+','+','+');
mvwprintw(win_step,1,1,"Step");
mvwprintw(win_step,2,1,"0");
attroff(COLOR_PAIR(2));


wrefresh(map_4);
wrefresh(win_level);
wrefresh(win_push);
wrefresh(win_step);
int a=8;
int b=7;
mvwprintw(map_4,a,b,"O");
wrefresh(map_4);

while(true) {
    int input_key = getch();
    if(input_key == KEY_UP) {
        int p_a=a-2;
        int p2_a=a-3;
        if(level_4[p_a][b-3]==1) continue; // y+1 벽
        else if(level_4[p_a][b-3]==2){ // y+1 박스
            if(level_4[p2_a][b-3]==1) continue; // y+1 박스 && y+2 벽
            else if(level_4[p2_a][b-3]==2) continue; // y+1 박스 && y+2 박스
            else{
                mvwprintw(map_4,a-2,b,"*");
                level_4[p2_a][b-3]=2;
                level_4[p_a][b-3]=0;
            }
        }

        if(level_4[a-1][b-3]==3) mvwprintw(map_4,a,b,"@");
        else if(level_4[a-1][b-3]==0) mvwprintw(map_4,a,b," ");
        a--;
        mvwprintw(map_4,a,b,"O");
        wrefresh(map_4);
    }
    if(input_key == KEY_DOWN) {
        int d_a=a;
        int d2_a=a+1;

        if(level_4[d_a][b-3]==1) continue; // y-1 벽
        else if(level_4[d_a][b-3]==2){ // y-1 박스
            if(level_4[d2_a][b-3]==1) continue; // y-1 박스 && y-2 벽
            else if(level_4[d2_a][b-3]==2) continue; // y-1 박스 && y-2 박스
            else{
                mvwprintw(map_4,a+2,b,"*");
                level_4[d2_a][b-3]=2;
                level_4[d_a][b-3]=0;
            }
        }

        if(level_4[a-1][b-3]==3) mvwprintw(map_4,a,b,"@");
        else if(level_4[a-1][b-3]==0) mvwprintw(map_4,a,b," ");
        a++;
        mvwprintw(map_4,a,b,"O");
        wrefresh(map_4);

    }
    if(input_key == KEY_LEFT) {
        if(level_4[a-1][b-4]==1) continue;
        if(level_4[a-1][b-3]==2) mvwprintw(map_4,a,b,"*");
        else if(level_4[a-1][b-3]==3) mvwprintw(map_4,a,b,"@");
        else if(level_4[a-1][b-3]==0) mvwprintw(map_4,a,b," ");
        b--;
        mvwprintw(map_4,a,b,"O");
        wrefresh(map_4);
    }
    if(input_key == KEY_RIGHT) {
        if(level_4[a-1][b-2]==1) continue;
        if(level_4[a-1][b-3]==2) mvwprintw(map_4,a,b,"*");
        else if(level_4[a-1][b-3]==3) mvwprintw(map_4,a,b,"@");
        else if(level_4[a-1][b-3]==0) mvwprintw(map_4,a,b," ");
        b++;
        mvwprintw(map_4,a,b,"O");
        wrefresh(map_4);
    }
}
return 0;
} 

//level_1
// int level1[10][10]={{4,4,4,4,4,4,4,4,4,4},{4,4,4,4,4,4,4,4,4,4},{4,4,1,1,1,1,1,4,4,4},{4,4,1,0,0,0,1,4,4,4},{4,4,1,3,3,3,1,4,4,4},{4,4,1,2,2,2,1,1,4,4},{4,4,1,0,0,0,0,1,4,4},{4,4,1,0,0,0,0,1,4,4},{4,4,1,1,1,1,1,1,4,4},{4,4,4,4,4,4,4,4,4,4}};
//level_3
// int level3[10][10]={{4,4,4,4,4,4,4,4,4,4},{4,4,4,4,4,4,4,4,4,4},{4,4,4,4,4,4,4,4,4,4},{4,1,1,1,1,1,1,1,1,4},{4,1,3,0,0,0,0,0,1,4},{4,1,0,3,2,2,2,0,1,4},{4,1,3,0,0,0,0,0,1,4},{4,1,1,1,1,1,0,0,1,4},{4,4,4,4,4,1,1,1,1,4},{4,4,4,4,4,4,4,4,4,4}};
//level_2
//int level2[10][10]={{4,4,1,3,0,1,1,4,4,4},{4,4,1,3,0,0,1,4,4,4},{4,4,1,3,0,2,1,4,4,4},{4,4,1,1,2,0,1,1,1,4},{4,4,4,1,0,2,0,0,1,4},{4,4,4,1,0,0,0,0,1,4},{4,4,4,1,0,0,1,1,1,4},{4,4,4,1,1,1,1,4,4,4},{4,4,1,1,1,1,4,4,4,4},{4,4,4,4,4,4,4,4,4,4}};
//level_4
//int level_4[10][10]={{4,4,4,4,4,4,4,4,4,4},{4,1,1,1,1,1,1,1,4,4},{4,1,0,0,0,0,0,1,4,4},{4,1,0,3,2,3,0,1,4,4},{4,1,0,2,3,2,0,1,4,4},{4,1,0,3,2,3,0,1,4,4},{4,1,0,2,3,2,0,1,4,4},{4,1,0,0,0,0,0,1,4,4},{4,1,1,1,1,1,1,1,4,4},{4,4,4,4,4,4,4,4,4,4}};