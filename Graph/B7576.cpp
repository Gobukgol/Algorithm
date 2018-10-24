//
//  B7576.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2018. 10. 4..
//  Copyright © 2018년 Minhyoung. All rights reserved.
//

#include <iostream>
#include <queue>

int **box;
int M,N;
int boxSum = 0;
int resultSum = 0;

typedef struct tomato{
    int x;
    int y;
    int day;
}Tomato;
std::queue<Tomato>q;
int getDay();
int main(int argc, const char *argv[]){
    
    std::cin >> M >> N;

    box = new int*[N+2];
    
    for(int i=0;i<N+2;i++){
        box[i] = new int[M+2];
        //memset(box[i],-1,sizeof(int)*(M+2));
    }
    
    //백준의 경우 memset 초기화가 안돼서(왜인지모름) 일일이 초기화해줘야함
    for(int i=0;i<N+2;i++){
        for(int j=0;j<M+2;j++){
            box[i][j] = -1;
        }
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            std::cin >> box[i][j];
            if(box[i][j] == 1){
                Tomato toma;
                toma.x = i;
                toma.y = j;
                toma.day = 0;
                q.push(toma);
            }
            if(box[i][j] == 0){
                boxSum += 1;
            } else {
                boxSum+= box[i][j];
            }
        }
    }
    int result = getDay();
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            resultSum+=box[i][j];
        }
    }
    
    if(boxSum == resultSum){
        std::cout << result;
    } else {
        std::cout <<-1;
    }
    
    return 0;
}
int getDay(){
    int day;
    while(!q.empty()){
        Tomato tmpToma = q.front();
        q.pop();
        Tomato nextToma;
        day = tmpToma.day;
        //위
        if(box[tmpToma.x-1][tmpToma.y] == 0){
            box[tmpToma.x-1][tmpToma.y] = 1;
            nextToma.x = tmpToma.x-1;
            nextToma.y = tmpToma.y;
            nextToma.day = tmpToma.day + 1;
            q.push(nextToma);
        }
        //아래
        if(box[tmpToma.x+1][tmpToma.y] == 0){
            box[tmpToma.x+1][tmpToma.y] = 1;
            nextToma.x = tmpToma.x+1;
            nextToma.y = tmpToma.y;
            nextToma.day = tmpToma.day + 1;
            q.push(nextToma);
        }
        //왼쪽
        if(box[tmpToma.x][tmpToma.y-1] == 0){
            box[tmpToma.x][tmpToma.y-1] = 1;
            nextToma.x = tmpToma.x;
            nextToma.y = tmpToma.y-1;
            nextToma.day = tmpToma.day + 1;
            q.push(nextToma);
        }
        //오른쪽
        if(box[tmpToma.x][tmpToma.y+1] == 0){
            box[tmpToma.x][tmpToma.y+1] = 1;
            nextToma.x = tmpToma.x;
            nextToma.y = tmpToma.y+1;
            nextToma.day = tmpToma.day + 1;
            q.push(nextToma);
        }
    }
    
    return day;
}

