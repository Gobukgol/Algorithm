//
//  B9095.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 1. 31..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

int value[3] = {1,2,3};
int result[11] = {1,2,4,0,};
int main(int argc,const char *argv[]){
    int T,n;
    
    for(int i=4;i<=11;i++){
        for(int j=1;j<=3;j++){
            result[i-1] += result[i-j-1];
        }
    }
    
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&n);
        
        printf("%d\n",result[n-1]);
    }
    
    return 0;
}
