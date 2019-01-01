//
//  B2667.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2018. 12. 4..
//  Copyright © 2018년 Minhyoung. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>



typedef struct HOME{
    int x;
    int y;
} Home;
std::queue<HOME> q;

char **group;
int *result;
int N;
int x[4] = {-1,1,0,0};
int y[4] = {0,0,-1,1};
int whole = 0;
int main(int argc, const char *argv[]){
    
    //데이터 입력
    std::cin >> N;
    
    result = new int[N*N];
    
    group = new char*[N+2];
    for(int i=0;i<N+2;i++){
        group[i] = new char[N+2];
    }
    
    for(int i=0;i<N+2;i++){
        for(int j=0;j<N+2;j++){
            group[i][j] = '0';
        }
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            std::cin >> group[i][j];
        }
    }

    //문제 풀이
    int count = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(group[i][j] == '1'){
                Home home;
                home.x = i;
                home.y = j;
                
                q.push(home);
                count++;
                group[i][j] = '0';

                while (!q.empty()) {
                    Home temp = q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        if(group[temp.x+x[k]][temp.y+y[k]] == '1'){
                            Home after;
                            after.x = temp.x+x[k];
                            after.y = temp.y+y[k];
                            q.push(after);
                            group[temp.x+x[k]][temp.y+y[k]] = '0';
                            count++;
                        }
                    }
                }
                result[whole] = count;
                whole++;
                count = 0;
            }
        }
    }
    std::sort(result, result+whole);
    
    std::cout<<whole<<std::endl;
    for(int i=0;i<whole;i++){
        std::cout<<result[i]<<std::endl;
    }
    return 0;
}
