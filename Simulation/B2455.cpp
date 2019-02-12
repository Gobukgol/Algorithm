//
//  B2455.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 2. 12..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <cstdio>
#include <iostream>
using namespace std;
int main(int argc,const char* argv[]){
    int train = 0;
    int max = 0;
    int off = 0;
    int on = 0;
    for(int i=0;i<4;i++){
        cin >> off >> on;
        train = train + on - off;
        if(max < train)
            max = train;
    }
    cout << max;
    return 0;
}
