//
//  B1987.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 1. 24..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>


typedef struct point{
    int x;
    int y;
    int count;
} Point;


int R,C;
int x[4] = {-1,1,0,0};
int y[4] = {0,0,-1,1};
char board[22][22];
int alpha[26] = {0,};
int count=0;
int max=0;
std::queue<Point> q;

void dfs(int nextX,int nextY){
    count++;
    alpha[board[nextX][nextY] - 'A'] = 1;
    if(max < count){
        max = count;
    }
    for(int i=0;i<4;i++){
        char check = board[nextX+x[i]][nextY+y[i]];
        if(check != '@' && alpha[check-'A'] == 0){
            dfs(nextX+x[i], nextY+y[i]);
            alpha[check-'A'] = 0;
            count--;
        }
    }
}

int main(int argc,const char* argv[]){
    std::ios_base :: sync_with_stdio(false);
    std::cin.tie(NULL);

    for(int i=0;i<22;i++){
        for(int j=0;j<22;j++){
            board[i][j] = '@';
        }
    }
    
    std::cin >> R >> C;
    
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            std::cin >> board[i][j];
        }
    }
    
    dfs(1,1);
    std::cout<<max;
    return 0;
}


