#include "map.h"
#include <ncurses.h>

enum {Space,Wall,Box,Goal,Out,BoxOnGoal};

struct position{
    int x,y;
    position(int x=0,int y=0):x(x),y(y){}
};

class PushBoxGame{
private:
    mapArray m;
    WINDOW *game_map;
    WINDOW *testWin; // test
    // WINDOW *win_push;
    // WINDOW *win_level;
    // WINDOW *win_step;
    int map_arr[10][10];
    position start;
    int a;
    int b;
    int goalCount;
public:
    PushBoxGame(){
        initscr();
        keypad(stdscr, TRUE);
        curs_set(0);
        noecho();
        start_color();
        init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
        init_pair(2,COLOR_RED,COLOR_BLUE);
        resize_term(27,27);
        attron(COLOR_PAIR(2));
        border('*','*','*','*','*','*','*','*');
        mvprintw(2,7,"push box game");
        attroff(COLOR_PAIR(2));
        refresh();
    }
    void setMap(int level);
    void newGame(int map[][10]);
    void moveUP(int map[][10]);
    void moveDOWN(int map[][10]);
    void moveRIGHT(int map[][10]);
    void moveLEFT(int map[][10]);
    bool finishGame();
    int (*getMap())[10];
};