#include "map.h"
#include "score.h"
#include <ncurses.h>

enum {Space,Wall,Box,Goal,Out,BoxOnGoal};

struct position{
    int x,y;
    position(int x=0,int y=0):x(x),y(y){}
};

class PushBoxGame{
private:
    score s;
    mapArray m;
    WINDOW *game_map;
    WINDOW *win_push;
    WINDOW *win_level;
    WINDOW *win_step;
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

        attron(COLOR_PAIR(2));
        win_level=newwin(4,7,4,2);
        wborder(win_level,'|','|','-','-','+','+','+','+');
        mvwprintw(win_level,1,1,"Level");
        mvwprintw(win_level,2,3,"1");
        win_push=newwin(4,7,4,10);
        wborder(win_push,'|','|','-','-','+','+','+','+');
        mvwprintw(win_push,1,1,"Push");
        mvwprintw(win_push,2,3,"0");
        win_step=newwin(4,7,4,18);
        wborder(win_step,'|','|','-','-','+','+','+','+');
        mvwprintw(win_step,1,1,"Step");
        mvwprintw(win_step,2,3,"0");
        attroff(COLOR_PAIR(2));
        refresh();
        wrefresh(win_level);
        wrefresh(win_push);
        wrefresh(win_step);
    }
    void setMap(int level);
    void newGame(int map[][10]);
    void moveUP(int map[][10]);
    void moveDOWN(int map[][10]);
    void moveRIGHT(int map[][10]);
    void moveLEFT(int map[][10]);
    bool finishGame();
    void stepRefresh(WINDOW *win,int step);
    void pushRefresh(WINDOW *win,int push);
    int (*getMap())[10];
};