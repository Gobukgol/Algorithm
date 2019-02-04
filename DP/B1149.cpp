//
//  B1149.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 2. 4..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int m[1000][1000] = {0,};
int main(int argc,const char* argv[]){
    int N;
    
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int R,G,B;
        scanf("%d %d %d",&R,&G,&B);
        if(i == 0){
            m[i][0] = R;
            m[i][1] = G;
            m[i][2] = B;
        } else {
            m[i][0] = min(m[i-1][1], m[i-1][2]) + R;
            m[i][1] = min(m[i-1][0], m[i-1][2]) + G;
            m[i][2] = min(m[i-1][0], m[i-1][1]) + B;
        }
    }
    printf("%d",min(min(m[N-1][0],m[N-1][1]),m[N-1][2]));
    return 0;
}
