//
//  B2583.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 1. 22..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

typedef struct point{
    int x;
    int y;
} Point;

int M,N,K;
int count=0;
int sector[102][102] = {0,};
int x[4] = {-1,1,0,0};
int y[4] = {0,0,-1,1};
std::queue<Point> q;
int main(int argc, const char *argv[]){
    int *result;
    scanf("%d %d %d",&M,&N,&K);
    result = new int[K];
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            sector[i][j] = 1;
        }
    }
    
    for(int i=0;i<K;i++){
        int leftR,leftC;
        int rightR,rightC;
        
        scanf("%d %d %d %d",&leftR,&leftC,&rightR,&rightC);
        leftR++;leftC++; rightR++;rightC++;
        
        for(int j=leftR;j<rightR;j++){
            for(int k=leftC;k<rightC;k++){
                sector[j][k] = 0;
            }
        }
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(sector[i][j] == 1){
                int sum = 0;
                Point p;
                p.x = i;
                p.y = j;
                q.push(p);
                sector[i][j] = 0;
                while (!q.empty()) {
                    Point curr;
                    curr = q.front();
                    q.pop();
                    sum++;
                    for(int k=0;k<4;k++){
                        if(sector[curr.x+x[k]][curr.y+y[k]] == 1){
                            Point tmp;
                            tmp.x=curr.x+x[k];
                            tmp.y=curr.y+y[k];
                            q.push(tmp);
                            sector[curr.x+x[k]][curr.y+y[k]] = 0;
                        }
                    }
                }
                result[count] = sum;
                count++;

            }
        }
    
    }
    std::sort(result, result+count);
    
    printf("%d\n",count);
    for(int i=0;i<count;i++){
        printf("%d ",result[i]);
    }
    
    return 0;
}
