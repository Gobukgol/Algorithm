//
//  B11724.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 1. 24..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <queue>

int N,M;
int matrix[1001][1001] = {0,};
int visited[1001] = {0,};
std::queue<int> q;
int main(int argc, const char *argv[]){
    int count=0;
    scanf("%d %d",&N,&M);
    
    for(int i =0;i<M;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
    
    for(int i=1;i<=N;i++){
        if(visited[i] == 0){
            visited[i] = 1;
            for(int j=1;j<=N;j++){
                if(matrix[i][j] == 1){
                    q.push(j);
                    visited[j] = 1;
                }
            }
            while (!q.empty()) {
                int tmp = q.front();
                q.pop();
                for(int j=1;j<=N;j++){
                    if(matrix[tmp][j] == 1 && visited[j] == 0){
                        visited[j] = 1;
                        q.push(j);
                    }
                }
            }
            count++;
        }
    }
    
    printf("%d",count);
    return 0;
}
