//
//  B1966.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2018. 10. 23..
//  Copyright © 2018년 Minhyoung. All rights reserved.
//

#include <iostream>
#include <queue>

struct Data{
    int number;
    int priority;
};
int main(int argc, char *argv[]){
    int T;
    
    std::cin >> T;
    
    for(int i=0;i<T;i++){
        int N, M;
        std::priority_queue<int> pq;
        std::queue<Data> q;
        std::cin >> N >> M;
        for(int j=0;j<N;j++){
            int priority;
            std::cin >> priority;
            Data d;
            d.number = j;
            d.priority = priority;
            q.push(d);
            pq.push(priority);
        }
        int count = 1;
        while(1){
            Data tmp = q.front();
            q.pop();
            if(pq.top() == tmp.priority){
                if(tmp.number == M){
                    std::cout << count << std::endl;
                    break;
                } else{
                    pq.pop();
                    count++;
                }
            } else {
                q.push(tmp);
            }
        }
    }
    return 0;
}
