#include "game.cpp"
int main(){
    PushBoxGame g;
    int level=2;
    while(1){
        g.setMap(level);
        g.newGame(g.getMap());
        while(true){
            int inputKey=getch();
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
}
