//
//  B1003.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 2. 4..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int result[40][2];
int main(int argc,const char* argv[]){
    int T;
    int current = 2;
    result[0][0] = 1;
    result[0][1] = 0;
    result[1][0] = 0;
    result[1][1] = 1;
    
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        if(n >= current){
            for(;current<=n;current++){
                result[current][0] = result[current-2][0] + result[current-1][0];
                result[current][1] = result[current-2][1] + result[current-1][1];
            }
        }
        printf("%d %d\n",result[n][0],result[n][1]);
    }
    
    return 0;
}
