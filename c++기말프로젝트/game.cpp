#include <ncurses.h>
#include <iostream>
#include <fstream>
#include "map.cpp"

enum {Space,Wall,Box,Goal,Out,BoxOnGoal};

class PushBoxGame{
private:
    mapArray a;
    WINDOW *game_map;
    WINDOW *win_push;
    WINDOW *win_level;
    WINDOW *win_step;
    int *map_arr;
    int startingA;
    int startingB;
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
    void newGame(int map[]);
    void moveUP(int map[]);
    void moveDOWN(int map[]);
    void moveRIGHT(int map[]);
    void moveLEFT(int map[]);
    void finishGame(int map[]);
    int *getMap();
};

void PushBoxGame::setMap(int level){
    if(level==1){
        map_arr=a.getLevel_1();
        newGame(map_arr,a.getLevel1_a_s());
    }
    else if(level==2){
        map_arr=a.getLevel_2();
        newGame(map_arr,a.getLevel2_a_s());
    }
    else if(level==3){
        map_arr=a.getLevel_3();
        newGame(map_arr,a.getLevel3_a_s());
    }
    else if(level==4){
        map_arr=a.getLevel_4();
        newGame(map_arr,a.getLevel4_a_s());
    }
    else if(level==5){
        map_arr=a.getLevel_5();
        newGame(map_arr,a.getLevel5_a_s());
    }
}

void PushBoxGame::newGame(int map[][],int map_a_s[][]){
    //맵 생성
    GameMap=newwin(12,14,10,7);
    wborder(GameMap,'|','|','-','-','+','+','+','+');
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(map[i][j]==1){
                wattron(GameMap,COLOR_PAIR(1));
                mvwprintw(GameMap,i+1,j+3,"#");
                wattroff(GameMap,COLOR_PAIR(1));
            }
            else if(map[i][j]==2) mvwprintw(GameMap,i+1,j+3,"*");
            else if(map[i][j]==3) mvwprintw(GameMap,i+1,j+3,"@");
            else mvwprintw(GameMap,i+1,j+3," ");
        }
    }
    wrefresh(GameMap);

    //캐릭터 생성
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(map_a_s[i][j]==1){
                startingA=i+1;
                startingB=j+3;
                break;
            }
        }
    }
    mvwprintw(map,startingA,startingB,"O");
    wrefresh(GameMap);

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(map_arr[i][j]==1){
                
            }
        }
    }
}

