#include <fstream>
#include <iostream>
using namespace std;
class mapArray{
public:
    void set_map(int map_arr[][10],int level);    
};

void mapArray::set_map(int map_arr[][10],int level){
    ifstream input;
    if(level==1){
        input.open("level1.txt");
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                input>>map_arr[i][j];
            }
        }
    }
    else if(level==2){
        input.open("level2.txt");
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                input>>map_arr[i][j];
            }
        }
    }
    else if(level==3){
        input.open("level3.txt");
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                input>>map_arr[i][j];
            }
        }
    }
    if(level==4){
        input.open("level4.txt");
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                input>>map_arr[i][j];
            }
        }
    }
    if(level==5){
        input.open("level5.txt");
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                input>>map_arr[i][j];
            }
        }
    }
}

