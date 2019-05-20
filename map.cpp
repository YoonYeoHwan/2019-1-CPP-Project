#include <ncurses.h>
#include <iostream>
int main()
{
WINDOW *win1;
initscr();
start_color();
init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
init_pair(2,COLOR_RED,COLOR_BLUE);

resize_term(30, 60);
attron(COLOR_PAIR(2));
border('*','*','*','*','*','*','*','*');
mvprintw(1,12,"push_box_game");
mvprintw(14,15,"START");
mvprintw(16,15,"QUIT");
attroff(COLOR_PAIR(2));
refresh();
getch();

int arr[9][7]={{1,1,1,1,4,4,4},{1,3,0,1,1,4,4},{1,3,0,0,1,4,4},{1,3,0,2,1,4,4},{1,1,2,0,1,1,1},{4,1,0,2,0,0,1},{4,1,0,0,0,0,1},{4,1,0,0,1,1,1},{4,1,1,1,1,4,4}};

win1=newwin(11,11,10,12);
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
wrefresh(win1);
getch();
delwin(win1);
endwin();
return 0; 
}