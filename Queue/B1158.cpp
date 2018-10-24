//
//  B1158.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2018. 10. 24..
//  Copyright © 2018년 Minhyoung. All rights reserved.
//

#include <iostream>
#include <queue>

int main(int argc, char *argv[]){
    std::queue<int> q;
    int N, M;
    std::cin >> N >> M;
    
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    std::cout <<"<";
    int count = 0;
    while(1){
        if(N == 1){
            std::cout<<q.front()<<">";
            return 0;
        }
        if(q.size() == 2){
            if(M%2 == 1){
                std::cout<<q.front()<<", ";
                std::cout<<q.back()<<">";
            } else {
                std::cout<<q.back()<<", ";
                std::cout<<q.front()<<">";
            }
            return 0;
        }
        count++;
        if(M == count){
            count = 0;
            std::cout<<q.front()<<", ";
            q.pop();
        } else {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
    }
    return 0;
}
