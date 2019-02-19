//
//  B1057.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 2. 19..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <cstdio>
#include <iostream>
using namespace std;
int main(int argc,const char* argv[]){
    int N,x,y;
    int count = 1;
    scanf("%d %d %d",&N,&x,&y);
    x--; y--;
    
    while(1){
        if(min(x,y) % 2 == 0 && abs(x - y) == 1){
            printf("%d",count);
            return 0;
        }
        x /= 2; y /= 2;
        count++;
    }
    
    return 0;
}
