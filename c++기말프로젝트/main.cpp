#include "PushBoxGame.h"

int main(){
    PushBoxGame g;
    int level=1;
    while(1){
        if(level==10){
            g.ending();
            getch();
            endwin();
            break;
        }
        g.setMap(level++);
        g.newGame(g.getMap());
        while(true){
            int inputKey=getch();
            if(inputKey==KEY_F(1)){
                g.setMap(--level);
                g.newGame(g.getMap());
                break;
            }
            if(inputKey==KEY_UP){
                g.moveUP(g.getMap());
                if(g.finishGame()) break;
            }
            else if(inputKey==KEY_DOWN){
                g.moveDOWN(g.getMap());
                if(g.finishGame()) break;
            }
            else if(inputKey==KEY_RIGHT){
                g.moveRIGHT(g.getMap());
                if(g.finishGame()) break;
            }
            else if(inputKey==KEY_LEFT){
                g.moveLEFT(g.getMap());
                if(g.finishGame()) break;
            }
        }
    }
    return 0;
}
