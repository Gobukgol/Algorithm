//
//  B1012.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 1. 1..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <iostream>
#include <queue>

typedef struct baechu{
    int x;
    int y;
} Baechu;

int T,M,N,K;
int **grand;
int x[4] = {-1,1,0,0};
int y[4] = {0,0,-1,1};
std::queue<Baechu> q;
int main(int argc, const char *argv[]){
    std::cin>>T;
    
    for(int t=0;t<T;t++){
        int count = 0;
        std::cin>>M>>N>>K;
        
        grand = new int*[M+2];
        for(int i=0;i<M+2;i++)
            grand[i] = new int[N+2];
        
        //초기화
        for(int i=0;i<M+2;i++){
            for(int j=0;j<N+2;j++){
                grand[i][j] = 0;
            }
        }
        
        for(int k=0;k<K;k++){
            int i,j;
            std::cin>>i>>j;
            grand[i+1][j+1] = 1;
        }
        for(int i=1;i<=M;i++){
            for(int j=1;j<=N;j++){
                if(grand[i][j] == 1){
                    Baechu bae;
                    bae.x = i; bae.y = j;
                    q.push(bae);
                    grand[i][j] = 0;
                    
                    while(!q.empty()){
                        Baechu temp = q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nextX = temp.x+x[k];
                            int nextY = temp.y+y[k];
                            
                            if(grand[nextX][nextY] == 1){
                                Baechu next;
                                next.x = nextX; next.y = nextY;
                                q.push(next);
                                grand[nextX][nextY] = 0;
                            }
                        }
                    }
                
                    count++;
                }
            }
        }
        std::cout<<count<<std::endl;
        
    }
    
    
    return 0;
}
