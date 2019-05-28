#include <fstream>
#include <iostream>
#include "map.h"
using namespace std;
// class mapArray{
// public:
//     void set_map(int map_arr[][10],int level,int &a,int &b,int &goalCount);    
// };

void mapArray::set_map(int map_arr[][10],int level,int &a,int &b,int &goalCount){
    ifstream input;
    if(level==1){
        input.open("./mapFile/level1.txt");
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                input>>map_arr[i][j];
            }
        }
        input>>goalCount>>a>>b;
        
    }
    else if(level==2){
        input.open("./mapFile/level2.txt");
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                input>>map_arr[i][j];
            }
        }
        input>>goalCount>>a>>b;
    }
    else if(level==3){
        input.open("./mapFile/level3.txt");
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                input>>map_arr[i][j];
            }
        }
        input>>goalCount>>a>>b;
    }
    if(level==4){
        input.open("./mapFile/level4.txt");
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                input>>map_arr[i][j];
            }
        }
        input>>goalCount>>a>>b;
    }
    if(level==5){
        input.open("./mapFile/level5.txt");
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                input>>map_arr[i][j];
            }
        }
        input>>goalCount>>a>>b;
    }
}

