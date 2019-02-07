//
//  B1912.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 2. 7..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int main(int argc,const char* argv[]){
    int n;
    int sum;
    int max = -10000;
    vector<int> arr;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        arr.push_back(tmp);
        if(max < tmp){
            max = tmp;
        }
    }
    
    sum = arr[0];
    for(int i=1;i<n;i++){
        sum = sum+arr[i] > arr[i] ? sum+arr[i] : arr[i];
        
        if(max < sum){
            max = sum;
        }
    }
    if(max < sum){
        max = sum;
    }
    
    printf("%d",max);
    return 0;
}
