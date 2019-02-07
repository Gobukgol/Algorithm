//
//  B1520.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 2. 7..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <cstdio>
#include <iostream>

int m[502][502];
int dp[502][502];
int x[4] = {-1,1,0,0};
int y[4] = {0,0,-1,1};
int M,N;

int find(int row,int col){
    int count = 0;
    if(row == M && col == N){
        return 1;
    }
    if(dp[row][col] != -1){
        return dp[row][col];
    }
    for(int i=0;i<4;i++){
        if(m[row][col] > m[row+x[i]][col+y[i]]){
            count += find(row+x[i],col+y[i]);
        }
    }
    dp[row][col] = count;
    return count;
}
int main(int argc,const char* argv[]){
    for(int i=0;i<502;i++)
        for(int j=0;j<502;j++){
            m[i][j] = 10001;
            dp[i][j] = -1;
        }
    scanf("%d %d",&M,&N);
    
    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++)
            scanf("%d",&m[i][j]);
    
    printf("%d",find(1,1));
    
    return 0;
}
