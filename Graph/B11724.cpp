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
bool visited[1001] = {false,};
void dfs(int point){
    for(int i=1;i<=N;i++){
        if(matrix[point][i] == 1 && !visited[i]){
            visited[i] = true;
            dfs(i);
        }
    }
}
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
        if(!visited[i]){
            visited[i] = true;
            dfs(i);
            count++;
        }
    }
    
    printf("%d",count);
    return 0;
}

