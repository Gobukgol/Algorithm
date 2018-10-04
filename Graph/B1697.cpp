//
//  B1697.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2018. 10. 3..
//  Copyright © 2018년 Minhyoung. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cmath>

typedef struct find{
    int current;
    int currentTime;
} FIND;

std::queue <FIND>nq;
int N,K;
int path2();
int main(int argc, const char * argv[]){

    std::cin >>N >> K;
    
    FIND subin;
    
    subin.current = N;
    subin.currentTime = 0;
    nq.push(subin);
    std::cout << path2();
    
    return 0;
}

int path2(){
    int min = 100001;
    int current = 0;
    int currentTime = 0;
    int visit[100001] = {0,};
    visit[N] = 1;
    while(!nq.empty()){
        FIND cur = nq.front();
        current = cur.current;
        currentTime = cur.currentTime;
        visit[current] = 1;
        nq.pop();
        if(current != K){
            if(current*2<=100000 && visit[current*2] == 0){
                FIND p;
                p.current = current*2;
                p.currentTime = currentTime+1;
                nq.push(p);
                visit[current*2] = 1;
            }
            if(current<100000 && visit[current+1] == 0){
                FIND p;
                p.current = current+1;
                p.currentTime = currentTime+1;
                nq.push(p);
                visit[current+1] = 1;
            }
            
            if(current>=1 && visit[current-1] == 0){
                FIND p;
                p.current = current-1;
                p.currentTime = currentTime+1;
                nq.push(p);
                visit[current-1] = 1;
            }
        } else {
            return currentTime;
        }
    }
    return min;
}
