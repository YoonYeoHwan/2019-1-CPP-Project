#include <ncurses.h>
#include "map.h"
#include "PushBoxGame.h"

int (*PushBoxGame::getMap())[10]{
    return map_arr;
}

void PushBoxGame::setMap(int level){
    if(level==1){
        goalCount=m.set_map(map_arr,level);
    }
    else if(level==2){
        m.set_map(map_arr,level);
    }
    else if(level==3){
        m.set_map(map_arr,level);
    }
    else if(level==4){
        m.set_map(map_arr,level);
    }
    else if(level==5){
        m.set_map(map_arr,level);
    }
}

void PushBoxGame::newGame(int map[][10]){
    //맵 생성
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
    a=7;
    b=7;
    mvwprintw(game_map,a,b,"O");
    wrefresh(game_map);
}

void PushBoxGame::moveUP(int map[][10]){
    int up=a-2; // y+1 좌표
    int up2=a-3; // y+2 좌표
    if(map[up][b-3]==Wall) return; // y+1 벽
    else if(map[up][b-3]==Box){ // y+1 박스
        if(map[up2][b-3]==Wall) return; // y+1 박스 && y+2 벽
        else if(map[up2][b-3]==Box || map[up2][b-3]==BoxOnGoal) return; // y+1 박스 && y+2 박스
        else{
            if(map[up2][b-3]==Goal) { // y+1 박스 && y+2 골
                mvwprintw(game_map,a-2,b,"*");
                map[up2][b-3]=BoxOnGoal; // 5는 골 자리에 상자가 올라가있는 경우
                map[up][b-3]=Space;
            }
            else { // y+1 박스 && y+2 공간
                mvwprintw(game_map,a-2,b,"*");
                map[up2][b-3]=Box;
                map[up][b-3]=Space;
            }
        }
    }
    else if(map[up][b-3]==BoxOnGoal) {
        if(map[up2][b-3]==Wall) return; // y+1 박스 && y+2 벽
        else if(map[up2][b-3]==Box || map[up2][b-3]==BoxOnGoal) return; // y+1 박스 && y+2 박스
        else {
            if(map[up2][b-3]==Goal) { // y+1 박스 && y+2 골
                mvwprintw(game_map,a-2,b,"*");
                map[up2][b-3]=BoxOnGoal; // 5는 골 자리에 상자가 올라가있는 경우
                map[up][b-3]=Goal;
            }

            else { // y+1 박스 && y+2 공간
                mvwprintw(game_map,a-2,b,"*");
                map[up2][b-3]=Box;
                map[up][b-3]=Goal;
            }
        }

    }
    if(map[a-1][b-3]==Goal) mvwprintw(game_map,a,b,"@");
    else if(map[a-1][b-3]==Space) mvwprintw(game_map,a,b," ");
    a--;
    mvwprintw(game_map,a,b,"O");
    wrefresh(game_map);
}
void PushBoxGame::moveDOWN(int map[][10]){
    int down=a; // y+1 좌표
    int down2=a+1; // y+2 좌표
    if(map[down][b-3]==Wall) return; // y+1 벽
    else if(map[down][b-3]==Box){ // y+1 박스
        if(map[down2][b-3]==Wall) return; // y+1 박스 && y+2 벽
        else if(map[down2][b-3]==Box || map[down2][b-3]==BoxOnGoal) return; // y+1 박스 && y+2 박스
        else{
            if(map[down2][b-3]==Goal) { // y+1 박스 && y+2 골
                mvwprintw(game_map,a+2,b,"*");
                map[down2][b-3]=BoxOnGoal; // 5는 골 자리에 상자가 올라가있는 경우
                map[down][b-3]=Space;
            }
            else { // y+1 박스 && y+2 공간
                mvwprintw(game_map,a+2,b,"*");
                map[down2][b-3]=Box;
                map[down][b-3]=Space;
            }
        }
    }
    else if(map[down][b-3]==BoxOnGoal) {
        if(map[down2][b-3]==Wall) return; // y+1 박스 && y+2 벽
        else if(map[down2][b-3]==Box || map[down2][b-3]==BoxOnGoal) return; // y+1 박스 && y+2 박스
        else {
            if(map[down2][b-3]==Goal) { // y+1 박스 && y+2 골
                mvwprintw(game_map,a+2,b,"*");
                map[down2][b-3]=BoxOnGoal; // 5는 골 자리에 상자가 올라가있는 경우
                map[down][b-3]=Goal;
            }
            else { // y+1 박스 && y+2 공간
                mvwprintw(game_map,a+2,b,"*");
                map[down2][b-3]=Box;
                map[down][b-3]=Goal;
            }
        }

    }

    if(map[a-1][b-3]==Goal) mvwprintw(game_map,a,b,"@");
    else if(map[a-1][b-3]==Space) mvwprintw(game_map,a,b," ");
    a++;
    mvwprintw(game_map,a,b,"O");
    wrefresh(game_map);
}

void PushBoxGame::moveLEFT(int map[][10]){
    int left=b-4; // y+1 좌표
    int left2=b-5; // y+2 좌표
    if(map[a-1][left]==Wall) return; // y+1 벽
    else if(map[a-1][left]==Box){ // y+1 박스
        if(map[a-1][left2]==Wall) return; // y+1 박스 && y+2 벽
        else if(map[a-1][left2]==Box || map[a-1][left2]==BoxOnGoal) return; // y+1 박스 && y+2 박스
        else{
            if(map[a-1][left2]==Goal) { // y+1 박스 && y+2 골
                mvwprintw(game_map,a,b-2,"*");
                map[a-1][left2]=BoxOnGoal; // 5는 골 자리에 상자가 올라가있는 경우
                map[a-1][left]=Space;
            }
            else { // y+1 박스 && y+2 공간
                mvwprintw(game_map,a,b-2,"*");
                map[a-1][left2]=Box;
                map[a-1][left]=Space;
            }
        }
    }
    else if(map[a-1][left]==BoxOnGoal) {
        if(map[a-1][left2]==Wall) return; // y+1 박스 && y+2 벽
        else if(map[a-1][left2]==Box || map[a-1][left2]==BoxOnGoal) return; // y+1 박스 && y+2 박스
        else {
            if(map[a-1][left2]==Goal) { // y+1 박스 && y+2 골
                mvwprintw(game_map,a,b-2,"*");
                map[a-1][left2]=BoxOnGoal; // 5는 골 자리에 상자가 올라가있는 경우
                map[a-1][left]=Goal;
            }

            else { // y+1 박스 && y+2 공간
                mvwprintw(game_map,a,b-2,"*");
                map[a-1][left2]=Box;
                map[a-1][left]=Goal;
            }
        }

    }
    if(map[a-1][b-3]==Goal) mvwprintw(game_map,a,b,"@");
    else if(map[a-1][b-3]==Space) mvwprintw(game_map,a,b," ");
    b--;
    mvwprintw(game_map,a,b,"O");
    wrefresh(game_map);
}

void PushBoxGame::moveRIGHT(int map[][10]){
    int right=b-2; // y+1 좌표
    int right2=b-1; // y+2 좌표
    if(map[a-1][right]==Wall) return; // y+1 벽
    else if(map[a-1][right]==Box){ // y+1 박스
        if(map[a-1][right2]==Wall) return; // y+1 박스 && y+2 벽
        else if(map[a-1][right2]==Box || map[a-1][right2]==BoxOnGoal) return; // y+1 박스 && y+2 박스
        else{
            if(map[a-1][right2]==Goal) { // y+1 박스 && y+2 골
                mvwprintw(game_map,a,b+2,"*");
                map[a-1][right2]=BoxOnGoal; // 5는 골 자리에 상자가 올라가있는 경우
                map[a-1][right]=Space;
            }
            else { // y+1 박스 && y+2 공간
                mvwprintw(game_map,a,b+2,"*");
                map[a-1][right2]=Box;
                map[a-1][right]=Space;
            }
        }
    }
    else if(map[a-1][right]==BoxOnGoal) {
        if(map[a-1][right2]==Wall) return; // y+1 박스 && y+2 벽
        else if(map[a-1][right2]==Box || map[a-1][right2]==BoxOnGoal) return; // y+1 박스 && y+2 박스
        else {
            if(map[a-1][right2]==Goal) { // y+1 박스 && y+2 골
                mvwprintw(game_map,a,b+2,"*");
                map[a-1][right2]=BoxOnGoal; // 5는 골 자리에 상자가 올라가있는 경우
                map[a-1][right]=Goal;
            }

            else { // y+1 박스 && y+2 공간
                mvwprintw(game_map,a,b+2,"*");
                map[a-1][right2]=Box;
                map[a-1][right]=Goal;
            }
        }

    }
    if(map[a-1][b-3]==Goal) mvwprintw(game_map,a,b,"@");
    else if(map[a-1][b-3]==Space) mvwprintw(game_map,a,b," ");
    b++;
    mvwprintw(game_map,a,b,"O");
    wrefresh(game_map);
}

bool PushBoxGame::finishGame(){
    int cnt=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(map_arr[i][j]) cnt++;
        }
    }
    if(goalCount==cnt) return true;
    else return false;
}


