//
//  B2178.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2018. 10. 2..
//  Copyright © 2018년 Minhyoung. All rights reserved.
//

#include <iostream>
#include <queue>

typedef struct location{
    int x;
    int y;
} LOCATION;

char **laby;
int **visit;
int N,M;
std::queue <LOCATION>q;
std::queue <int>count;

int path();
int main(int argc, const char * argv[]){
    std::cin >> N>>M;
    
    laby = new char*[N+2];
    visit = new int*[N+2];
    for(int i=0;i<N+2;i++){
        laby [i] = new char[M+2];
        visit [i] = new int[M+2];
    }
    
    for(int i=0;i<N+2;i++){
        for(int j=0;j<M+2;j++){
            laby[i][j] = '0';
            visit[i][j] = 0;
        }
    }
    
    for(int i=1;i<N+1;i++){
        for(int j=1;j<M+1;j++){
            std::cin >> laby[i][j];
        }
    }
    
    LOCATION start;
    start.x = 1;
    start.y = 1;
    
    q.push(start);
    count.push(1);
    visit[1][1] = 1;
    
    std::cout << path();
    
    return 0;
}

int path(){
    int min=N*M;
    int sum=0;
    
    while(!q.empty() && !count.empty()){
        LOCATION current = q.front();
        LOCATION next;
        
        int currCount;
        q.pop();
        currCount = count.front();
        count.pop();
        if(current.x == N && current.y == M){
            if(min > currCount){
                min = currCount;
            }
        }
        //위
        next.x = current.x-1;
        next.y = current.y;
        if(laby[next.x][next.y] == '1' && visit[next.x][next.y] == 0){
            visit[next.x][next.y] = 1;
            q.push(next);
            count.push(currCount+1);
        }
        //아래
        next.x = current.x+1;
        next.y = current.y;
        if(laby[next.x][next.y] == '1' && visit[next.x][next.y] == 0){
            visit[next.x][next.y] = 1;
            q.push(next);
            count.push(currCount+1);
        }
        //왼쪽
        next.x = current.x;
        next.y = current.y-1;
        if(laby[next.x][next.y] == '1' && visit[next.x][next.y] == 0){
            visit[next.x][next.y] = 1;
            q.push(next);
            count.push(currCount+1);
        }
        //오른쪽
        next.x = current.x;
        next.y = current.y+1;
        if(laby[next.x][next.y] == '1' && visit[next.x][next.y] == 0){
            visit[next.x][next.y] = 1;
            q.push(next);
            count.push(currCount+1);
        }
    }
    
    return min;
}
