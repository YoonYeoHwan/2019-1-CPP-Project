#include <ncurses.h>
#include <iostream>

class Player {
    private:
        int a, b;
        WINDOW *win1;
    public:        
        Player(int a, int b) {
        }
        void move_up();
        void move_down();
        void move_left();
        void move_right();

};

void Player::move_up() {
    mvwprintw(win1,a,b,"#");
    a--;
    mvwprintw(win1,a,b,"O");
    wrefresh(win1);
}

void Player::move_down() {
    mvwprintw(win1,a,b,"#");
    a++;
    mvwprintw(win1,a,b,"O");
    wrefresh(win1);
}

void Player::move_left() {
    mvwprintw(win1,a,b,"#");
    b--;
    mvwprintw(win1,a,b,"O");
    wrefresh(win1);    
}

void Player::move_right() {
    mvwprintw(win1,a,b,"#");
    b++;
    mvwprintw(win1,a,b,"O");
    wrefresh(win1);
}



int main() {

    int input_key;

    WINDOW *win1;

    initscr();
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_WHITE);
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
    // getch();


    int testarray[10][10] = {{1,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}};
    int a = 0; // 좌표로 사용할 변수
    int b = 0; // 좌표로 사용할 변수
    
    // input_key = getch();

    win1=newwin(10,10,2,2);
    wborder(win1,'|','|','-','-','+','+','+','+');
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(testarray[i][j] == 0) {
                wattron(win1,COLOR_PAIR(1));
                mvwprintw(win1,i,j,"#");
                wattroff(win1,COLOR_PAIR(1));
            }
            else if(testarray[i][j] == 1) {
                wattron(win1,COLOR_PAIR(3));
                mvwprintw(win1,i,j,"O");
                wattroff(win1,COLOR_PAIR(3));            
            }
        }
    }
    wrefresh(win1);
    // getch();

    Player player1(0, 0);

    while(true) {

        input_key = getch();
        if(input_key == KEY_UP) {
            // mvwprintw(win1,a,b,"#");
            // a--;
            // mvwprintw(win1,a,b,"O");
            // wrefresh(win1);
            player1.move_up();

        }
        if(input_key == KEY_DOWN) {
            // mvwprintw(win1,a,b,"#");
            // a++;
            // mvwprintw(win1,a,b,"O");
            // wrefresh(win1);
            player1.move_down();
        }
        if(input_key == KEY_LEFT) {
            // mvwprintw(win1,a,b,"#");
            // b--;
            // mvwprintw(win1,a,b,"O");
            // wrefresh(win1);
            player1.move_left();
        }
        if(input_key == KEY_RIGHT) {
            // mvwprintw(win1,a,b,"#");
            // b++;
            // mvwprintw(win1,a,b,"O");
            // wrefresh(win1);
            player1.move_right();
        }
    }

    wrefresh(win1);

    getch();

    delwin(win1);
    endwin();
    return 0;
} 
