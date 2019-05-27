#include "game.cpp"

int main(){
    PushBoxGame g;
    g.setMap(5);
    g.newGame(g.getMap());
    while(true){
        int inputKey=getch();
        if(inputKey==KEY_UP){
            g.moveUP(g.getMap());
        }
        else if(inputKey==KEY_DOWN){
            g.moveDOWN(g.getMap());
        }
        else if(inputKey==KEY_RIGHT){
            g.moveRIGHT(g.getMap());
        }
        else if(inputKey==KEY_LEFT){
            g.moveLEFT(g.getMap());
        }
    }
}
