//
//  B1463.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 2. 4..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;

int result[1000001] = {-1,};

void setMinValue(int n){
    int minValue = -1;
    
    if(n%2 == 0 && n%3 == 0){
        if(result[n/2] == -1){
            setMinValue(n/2);
        }
        if(result[n/3] == -1){
            setMinValue(n/3);
        }
        if(result[n-1] == -1){
            setMinValue(n-1);
        }
        minValue = min(min(result[n/2], result[n/3]),result[n-1]);
    } else if(n%2==0){
        if(result[n/2] == -1){
            setMinValue(n/2);
        }
        if(result[n-1] == -1){
            setMinValue(n-1);
        }
        minValue = min(result[n/2],result[n-1]);
    } else if(n%3==0){
        if(result[n/3] == -1){
            setMinValue(n/3);
        }
        if(result[n-1] == -1){
            setMinValue(n-1);
        }
        minValue = min(result[n/3],result[n-1]);
    } else {
        if(result[n-1] == -1){
            setMinValue(n-1);
        }
        minValue = result[n-1];
    }
    result[n] = minValue+1;
}
int main(int argc,const char* argv[]){
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        result[i] = -1;
    }
    result[1] = 0; result[2] = 1; result[3] = 1;
    if(result[n] == -1){
        setMinValue(n);
    }
    printf("%d",result[n]);
    return 0;
}
