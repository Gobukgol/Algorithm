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

typedef struct tomato{
    int x;
    int y;
    int day;
} Tomato;

std::queue<Tomato>q;

int main(int argc, const char *argv[]){
    
    std::cin >> M >> N;

    box = new int*[N+2];
    
    for(int i=0;i<N+2;i++){
        box[i] = new int[M+2];
        memset(box[i],-1,sizeof(int)*(M+2));
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
    
//    for(int i=0;i<N+2;i++){
//        for(int j=0;j<M+2;j++){
//            std::cout << box[i][j];
//        }
//        std::cout<<std::endl;
//    }
//
//    box = {0,};
    
    return 0;
}

void getDay(){
    while(!q.empty()){
        
    }
}
