//
//  B1094.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 2. 19..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <cstdio>
#include <iostream>

int stick[7] = {1,2,4,8,16,32,64};
int main(int argc, const char* argv[]){
    int X;
    int count = 0;
    scanf("%d",&X);
    
    while(X != 0){
        for(int i = 6 ; i >= 0 ; i--) {
            if(X >= stick[i]){
                X -= stick[i];
                count ++;
            }
        }
    }
    
    printf("%d",count);
    
    return 0;
}
