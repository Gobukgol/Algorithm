//
//  B11052.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 2. 7..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc,const char* argv[]){
    int m[1001];
    int r[1001];
    int n;
    
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&m[i]);
        r[i] = m[i];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            r[i] = max(r[i],r[i-j]+r[j]);
        }
    }
    
    printf("%d",r[n]);
    return 0;
}
