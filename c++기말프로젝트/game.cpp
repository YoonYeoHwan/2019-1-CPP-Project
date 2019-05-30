#include <ncurses.h>
#include "PushBoxGame.h"
#include "map.h"

int (*PushBoxGame::getMap())[10]{
    return map_arr;
}

void PushBoxGame::setMap(int level){
    if(level==1) m.set_map(map_arr,level,a,b,goalCount);
    else if(level==2) m.set_map(map_arr,level,a,b,goalCount);
    else if(level==3) m.set_map(map_arr,level,a,b,goalCount);
    else if(level==4) m.set_map(map_arr,level,a,b,goalCount);
    else if(level==5) m.set_map(map_arr,level,a,b,goalCount);
}

void PushBoxGame::newGame(int map[][10]){
    game_map=newwin(12,14,10,7);
    wborder(game_map,'|','|','-','-','+','+','+','+');
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(map[i][j]==1){
                wattron(game_map,COLOR_PAIR(1));
                mvwprintw(game_map,i+1,j+3,"#");
                wattroff(game_map,COLOR_PAIR(1));
            }
            else if(map[i][j]==2) mvwprintw(game_map,i+1,j+3,"*");
            else if(map[i][j]==3) mvwprintw(game_map,i+1,j+3,"@");
            else mvwprintw(game_map,i+1,j+3," ");
        }
    }
    mvwprintw(game_map,a,b,"O");
    wrefresh(game_map);
}

void PushBoxGame::moveUP(int map[][10]){
    int up=a-2; 
    int up2=a-3; 
    if(map[up][b-3]==Wall) return;
    else if(map[up][b-3]==Box){ 
        if(map[up2][b-3]==Wall) return; 
        else if(map[up2][b-3]==Box || map[up2][b-3]==BoxOnGoal) return; 
        else{
            if(map[up2][b-3]==Goal) {
                s.pushUp();
                // stepRefresh(win_step,s.getStep());
                mvwprintw(game_map,a-2,b,"*");
                map[up2][b-3]=BoxOnGoal; 
                map[up][b-3]=Space;
            }
            else {
                s.pushUp(); 
                // stepRefresh(win_step,s.getStep());
                mvwprintw(game_map,a-2,b,"*");
                map[up2][b-3]=Box;
                map[up][b-3]=Space;
            }
        }
    }
    else if(map[up][b-3]==BoxOnGoal) {
        if(map[up2][b-3]==Wall) return; 
        else if(map[up2][b-3]==Box || map[up2][b-3]==BoxOnGoal) return; 
        else {
            if(map[up2][b-3]==Goal) {
                s.pushUp(); 
                mvwprintw(game_map,a-2,b,"*");
                map[up2][b-3]=BoxOnGoal; 
                map[up][b-3]=Goal;
            }

            else {
                s.pushUp();
                mvwprintw(game_map,a-2,b,"*");
                map[up2][b-3]=Box;
                map[up][b-3]=Goal;
            }
        }

    }
    if(map[a-1][b-3]==Goal) mvwprintw(game_map,a,b,"@");
    else if(map[a-1][b-3]==Space) mvwprintw(game_map,a,b," ");
    a--;
    s.stepUp();
    mvwprintw(game_map,a,b,"O");
    stepRefresh(win_step,s.getStep());
    pushRefresh(win_push,s.getPush());
    wrefresh(game_map);
}
void PushBoxGame::moveDOWN(int map[][10]){
    int down=a; 
    int down2=a+1; 
    if(map[down][b-3]==Wall) return; 
    else if(map[down][b-3]==Box){ 
        if(map[down2][b-3]==Wall) return; 
        else if(map[down2][b-3]==Box || map[down2][b-3]==BoxOnGoal) return;  
        else{
            if(map[down2][b-3]==Goal) { 
                s.pushUp();
                mvwprintw(game_map,a+2,b,"*");
                map[down2][b-3]=BoxOnGoal; 
                map[down][b-3]=Space;
            }
            else { 
                s.pushUp();
                mvwprintw(game_map,a+2,b,"*");
                map[down2][b-3]=Box;
                map[down][b-3]=Space;
            }
        }
    }
    else if(map[down][b-3]==BoxOnGoal) {
        if(map[down2][b-3]==Wall) return; 
        else if(map[down2][b-3]==Box || map[down2][b-3]==BoxOnGoal) return; 
        else {
            if(map[down2][b-3]==Goal) { 
                s.pushUp();
                mvwprintw(game_map,a+2,b,"*");
                map[down2][b-3]=BoxOnGoal; 
                map[down][b-3]=Goal;
            }
            else {
                s.pushUp();
                mvwprintw(game_map,a+2,b,"*");
                map[down2][b-3]=Box;
                map[down][b-3]=Goal;
            }
        }

    }

    if(map[a-1][b-3]==Goal) mvwprintw(game_map,a,b,"@");
    else if(map[a-1][b-3]==Space) mvwprintw(game_map,a,b," ");
    a++;
    s.stepUp();
    mvwprintw(game_map,a,b,"O");
    stepRefresh(win_step,s.getStep());
    pushRefresh(win_push,s.getPush());
    wrefresh(game_map);
}

void PushBoxGame::moveLEFT(int map[][10]){
    int left=b-4; 
    int left2=b-5; 
    if(map[a-1][left]==Wall) return; 
    else if(map[a-1][left]==Box){ 
        if(map[a-1][left2]==Wall) return; 
        else if(map[a-1][left2]==Box || map[a-1][left2]==BoxOnGoal) return; 
        else{
            if(map[a-1][left2]==Goal) {
                s.pushUp(); 
                mvwprintw(game_map,a,b-2,"*");
                map[a-1][left2]=BoxOnGoal; 
                map[a-1][left]=Space;
            }
            else { 
                s.pushUp();
                mvwprintw(game_map,a,b-2,"*");
                map[a-1][left2]=Box;
                map[a-1][left]=Space;
            }
        }
    }
    else if(map[a-1][left]==BoxOnGoal) {
        if(map[a-1][left2]==Wall) return; 
        else if(map[a-1][left2]==Box || map[a-1][left2]==BoxOnGoal) return;
        else {
            if(map[a-1][left2]==Goal) { 
                s.pushUp();
                mvwprintw(game_map,a,b-2,"*");
                map[a-1][left2]=BoxOnGoal; 
                map[a-1][left]=Goal;
            }

            else {
                s.pushUp();
                mvwprintw(game_map,a,b-2,"*");
                map[a-1][left2]=Box;
                map[a-1][left]=Goal;
            }
        }

    }
    if(map[a-1][b-3]==Goal) mvwprintw(game_map,a,b,"@");
    else if(map[a-1][b-3]==Space) mvwprintw(game_map,a,b," ");
    b--;
    s.stepUp();
    mvwprintw(game_map,a,b,"O");
    stepRefresh(win_step,s.getStep());
    pushRefresh(win_push,s.getPush());
    wrefresh(game_map);
}

void PushBoxGame::moveRIGHT(int map[][10]){
    int right=b-2; 
    int right2=b-1;
    if(map[a-1][right]==Wall) return;
    else if(map[a-1][right]==Box){ 
        if(map[a-1][right2]==Wall) return; 
        else if(map[a-1][right2]==Box || map[a-1][right2]==BoxOnGoal) return; 
        else{
            if(map[a-1][right2]==Goal) { 
                s.pushUp();
                mvwprintw(game_map,a,b+2,"*");
                map[a-1][right2]=BoxOnGoal; 
                map[a-1][right]=Space;
            }
            else { 
                s.pushUp();
                mvwprintw(game_map,a,b+2,"*");
                map[a-1][right2]=Box;
                map[a-1][right]=Space;
            }
        }
    }
    else if(map[a-1][right]==BoxOnGoal) {
        if(map[a-1][right2]==Wall) return; 
        else if(map[a-1][right2]==Box || map[a-1][right2]==BoxOnGoal) return;
        else {
            if(map[a-1][right2]==Goal) {
                s.pushUp();
                mvwprintw(game_map,a,b+2,"*");
                map[a-1][right2]=BoxOnGoal;
                map[a-1][right]=Goal;
            }

            else { 
                s.pushUp();
                mvwprintw(game_map,a,b+2,"*");
                map[a-1][right2]=Box;
                map[a-1][right]=Goal;
            }
        }

    }
    if(map[a-1][b-3]==Goal) mvwprintw(game_map,a,b,"@");
    else if(map[a-1][b-3]==Space) mvwprintw(game_map,a,b," ");
    b++;
    s.stepUp();
    mvwprintw(game_map,a,b,"O");
    stepRefresh(win_step,s.getStep());
    pushRefresh(win_push,s.getPush());
    wrefresh(game_map);
}

bool PushBoxGame::finishGame(){
    int cnt=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(map_arr[i][j]==5) cnt++;
        }
    }
    if(goalCount==cnt) return true;
    else return false;
}
void PushBoxGame::stepRefresh(WINDOW *win,int step){
    mvwprintw(win,2,3,"%d",step);
    wrefresh(win_step);
}
void PushBoxGame::pushRefresh(WINDOW *win,int push){
    mvwprintw(win,2,3,"%d",push);
    wrefresh(win_push);
}


