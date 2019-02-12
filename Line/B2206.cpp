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
#include <tuple>
using namespace std;
int route[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int N,M;
vector<vector<int>> map;
vector<vector<int>> visitModi;
queue<tuple<int,int,int,int>> qModi;

int bfsModi(){
    int row,col,breakCount,length;
    
    visitModi[0][0] = 1;
    qModi.push(make_tuple(0,0,1,1));
    
    while (!qModi.empty()) {
        tie(row,col,breakCount,length) = qModi.front();
        qModi.pop();
        
        if(row == N-1 && col == M-1){
            return length;
        }
        for(int i = 0;i<4;i++){
            int nextRow = row+route[i][0];
            int nextCol = col+route[i][1];
            if(nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M){
                continue;
            }
            if(map[nextRow][nextCol] == 0 && visitModi[nextRow][nextCol] < breakCount){
                qModi.push(make_tuple(nextRow,nextCol,breakCount,length+1));
                visitModi[nextRow][nextCol] = breakCount;
            } else if(map[nextRow][nextCol] == 1 && breakCount == 1){
                qModi.push(make_tuple(nextRow,nextCol,breakCount-1,length+1));
                visitModi[nextRow][nextCol] = breakCount-1;
            }
        }
        
    }
    
    return -1;
}
int main(int argc,const char* argv[]){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        vector<int> temp(M,0);
        vector<int> visitemp(M,-1);
        for(int j=0;j<M;j++){
            scanf("%1d",&temp[j]);
        }
        visitModi.push_back(visitemp);
        map.push_back(temp);
    }
    
    int min = bfsModi();
    printf("%d",min);
    return 0;
}
