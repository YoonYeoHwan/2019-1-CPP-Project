#include <ncurses.h>
#include <iostream>

// class Player {
//     public:
//         void move_up();
//         void move_down();
//         void move_left();
//         void move_right();

// };

int main() {

    int input_key;

    WINDOW *win1;

    initscr();
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(2, COLOR_RED,COLOR_BLUE);
    init_pair(3, COLOR_GREEN, COLOR_WHITE);
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();

    resize_term(27,27);

    attron(COLOR_PAIR(2));
    border('*','*','*','*','*','*','*','*');
    attroff(COLOR_PAIR(2));
    refresh();
    getch();


    int testarray[10][10] = {{1,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
    int a = 0; // 좌표로 사용할 변수
    int b = 0; // 좌표로 사용할 변수
    
    input_key = getch();

    win1=newwin(10,10,2,2);
    wborder(win1,'|','|','-','-','+','+','+','+');
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(testarray[i][j] == 0) {
                // wattron(win1,COLOR_PAIR(1));
                mvwprintw(win1,i,j,"#");
                // wattroff(win1,COLOR_PAIR(1));
            }
            else if(testarray[i][j] == 1) {
                // wattron(win1,COLOR_PAIR(3));
                mvwprintw(win1,i,j,"O");
                // wattroff(win1,COLOR_PAIR(3));            
            }
        }
    }
    wrefresh(win1);
    getch();

        // input_key = getch();
        // if(input_key == KEY_UP) {
        //     mvwprintw(win1,a,b,"#");
        //     a--;
        //     mvwprintw(win1,a,b," ");
        // }
        // if(input_key == KEY_DOWN) {
        //     mvwprintw(win1,a,b,"#");
        //     a++;
        //     mvwprintw(win1,a,b," ");
        // }
        // if(input_key == KEY_LEFT) {
        //     mvwprintw(win1,a,b,"#");
        //     b--;
        //     mvwprintw(win1,a,b," ");
        // }
        // if(input_key == KEY_RIGHT) {
        //     mvwprintw(win1,a,b,"#");
        //     b++;
        //     mvwprintw(win1,a,b," ");
        // }


    while(true) {

        input_key = getch();
        if(input_key == KEY_UP) {
            mvwprintw(win1,a,b,"#");
            a--;
            mvwprintw(win1,a,b,"O");
            wrefresh(win1);
        }
        if(input_key == KEY_DOWN) {
            mvwprintw(win1,a,b,"#");
            a++;
            mvwprintw(win1,a,b,"O");
            wrefresh(win1);
        }
        if(input_key == KEY_LEFT) {
            mvwprintw(win1,a,b,"#");
            b--;
            mvwprintw(win1,a,b,"O");
            wrefresh(win1);
        }
        if(input_key == KEY_RIGHT) {
            mvwprintw(win1,a,b,"#");
            b++;
            mvwprintw(win1,a,b,"O");
            wrefresh(win1);
        }
    }

    wrefresh(win1);

    getch();

    delwin(win1);
    endwin();
    return 0;
} 
