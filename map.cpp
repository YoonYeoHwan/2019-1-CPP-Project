#include <ncurses.h>
#include <iostream>
int main()
{
WINDOW *win1;
WINDOW *win_push;
WINDOW *win_level;
WINDOW *win_step;

initscr();
start_color();
init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
init_pair(2,COLOR_RED,COLOR_BLUE);

resize_term(27,27);
attron(COLOR_PAIR(2));
border('*','*','*','*','*','*','*','*');
attroff(COLOR_PAIR(2));
refresh();
getch();

int arr[9][7]={{1,1,1,1,4,4,4},{1,3,0,1,1,4,4},{1,3,0,0,1,4,4},{1,3,0,2,1,4,4},{1,1,2,0,1,1,1},{4,1,0,2,0,0,1},{4,1,0,0,0,0,1},{4,1,0,0,1,1,1},{4,1,1,1,1,4,4}};

win1=newwin(9,7,12,10);
wborder(win1,'|','|','-','-','+','+','+','+');
for(int i=0;i<=9;i++){
    for(int j=0;j<=7;j++){
        if(arr[i][j]==1){
            wattron(win1,COLOR_PAIR(1));
            mvwprintw(win1,i,j,"#");
            wattroff(win1,COLOR_PAIR(1));
        }
        else if(arr[i][j]==2) mvwprintw(win1,i,j,"*");
        else if(arr[i][j]==3) mvwprintw(win1,i,j,"@");
        else mvwprintw(win1,i,j," ");
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


wrefresh(win1);
wrefresh(win_level);
wrefresh(win_push);
wrefresh(win_step);
getch();
delwin(win1);
endwin();
return 0;
} 
