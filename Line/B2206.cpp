//
//  B2206.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 2. 11..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int route[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int N,M;
vector<vector<int>> map;
vector<vector<vector<bool>>> visit;

vector<vector<int>> visitMody;
queue<vector<int>> q;

int bfs(){
    int min = 1000001;
    vector<int> first;
    first.push_back(0);
    first.push_back(0);
    if(map[0][0] == 1){
        visit[0][0][1] = true;
        first.push_back(1);
    } else {
        visit[0][0][0] = true;
        first.push_back(0);
    }
    first.push_back(1);
    q.push(first);
    while (!q.empty()) {
        vector<int> current = q.front();
        q.pop();
        int row = current[0];
        int col = current[1];
        int breakCount = current[2];
        int length = current[3];
        if(row == N-1 && col == M-1){
            if(min > length){
                min = length;
            }
        } else {
            if(breakCount == 0){
                for(int i=0;i<4;i++){
                    int nextRow = row+route[i][0];
                    int nextCol = col+route[i][1];
                    if(nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M){
                        continue;
                    }
                    if(map[nextRow][nextCol] == 0 && !visit[nextRow][nextCol][0] ){
                        vector<int> state;
                        state.push_back(nextRow);
                        state.push_back(nextCol);
                        state.push_back(breakCount);
                        state.push_back(length+1);
                        q.push(state);
                        visit[nextRow][nextCol][0] = true;
                    }
                    else if(map[nextRow][nextCol] == 1 && breakCount == 0 && !visit[nextRow][nextCol][0]){
                        vector<int> state;
                        state.push_back(nextRow);
                        state.push_back(nextCol);
                        state.push_back(breakCount+1);
                        state.push_back(length+1);
                        q.push(state);
                        visit[nextRow][nextCol][1] = true;
                    }
                }
            } else {
                visit[row][col][1] = true;
                for(int i=0;i<4;i++){
                    int nextRow = row+route[i][0];
                    int nextCol = col+route[i][1];
                    if(nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M){
                        continue;
                    }
                    if(map[nextRow][nextCol] == 0 && !visit[nextRow][nextCol][1] ){
                        vector<int> state;
                        state.push_back(nextRow);
                        state.push_back(nextCol);
                        state.push_back(breakCount);
                        state.push_back(length+1);
                        q.push(state);
                        visit[nextRow][nextCol][1] = true;
                    }
                    else if(map[nextRow][nextCol] == 1 && breakCount == 0 && !visit[nextRow][nextCol][1]){
                        vector<int> state;
                        state.push_back(nextRow);
                        state.push_back(nextCol);
                        state.push_back(breakCount+1);
                        state.push_back(length+1);
                        q.push(state);
                        visit[nextRow][nextCol][1] = true;
                    }
                }
            }
        }
    }
    
    return min;
}

int bfsModi(){
    int min = 1000001;
    
    
    
    return min;
}
int main(int argc,const char* argv[]){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        vector<int> temp(M,0);
        vector<bool> breakVisit (2,false);
        vector<vector<bool>> visitTemp(M,breakVisit);
        for(int j=0;j<M;j++){
            scanf("%1d",&temp[j]);
        }
        visit.push_back(visitTemp);
        map.push_back(temp);
    }
    int min = bfs();
    if(min != 1000001){
        printf("%d",min);
        return 0;
    }
    printf("%d",-1);
    return 0;
}
