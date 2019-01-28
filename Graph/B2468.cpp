//
//  B2468.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 1. 28..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <cstdio>
#include <queue>
#include <iostream>

typedef struct point{
    int x;
    int y;
} Point;
int x[4] = {-1,1,0,0};
int y[4] = {0,0,-1,1};
int matrix[102][102] = {0,};
int visited[102][102] = {0,};
int N;
int max = 1;
int count = 0;
int maxRain = 0,minRain = 100;
std::queue<Point> q;
int main(int argc,const char *argv[]){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            scanf("%d",&matrix[i][j]);
            if(matrix[i][j] > maxRain){
                maxRain = matrix[i][j];
            }
            if(matrix[i][j] < minRain){
                minRain = matrix[i][j];
            }
        }
    }
    
    for(int rain=minRain;rain<maxRain;rain++){
        count = 0;
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                visited[i][j] = 0;
            }
        }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(matrix[i][j] > rain && visited[i][j] == 0){
                    Point first;
                    first.x = i; first.y = j;
                    q.push(first);
                    visited[i][j] = 1;
                    
                    while (!q.empty()) {
                        Point current = q.front();
                        q.pop();
                        
                        for(int k=0;k<4;k++){
                            if(matrix[current.x+x[k]][current.y+y[k]] > rain && visited[current.x+x[k]][current.y+y[k]] == 0){
                                Point next;
                                next.x = current.x+x[k];
                                next.y = current.y+y[k];
                                visited[next.x][next.y] = 1;
                                q.push(next);
                            }
                        }
                    }
                    count++;
                }
            }
        }
        if(max < count){
            max = count;
        }
    }
    
    printf("%d",max);

    return 0;
}
