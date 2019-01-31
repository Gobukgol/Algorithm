//
//  B6603.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 1. 30..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <cstdio>
#include <queue>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
int main(int argc,const char *argv[]){
    
    while(1){
        printf("\n");
        int K;
        vector<int> lotto;
        vector<vector<int>> answer;
        scanf("%d",&K);
        if(K != 0){
            for(int i=0;i<K;i++){
                int data;
                scanf("%d",&data);
                lotto.push_back(data);
            }
            
            int num = 6;
            int i=0;
            for(int i=0;i<=K-6;i++){
                //vector<int> temp;
                for(int j=i+1;j<=K-5;j++){
                    
                    for(int k=j+1;k<=K-4;k++){
                        
                        for(int l=k+1;l<=K-3;l++){
                            
                            for(int o=l+1;o<=K-2;o++){
                                
                                for(int p=o+1;p<=K-1;p++){
                                    printf("%d %d %d %d %d %d\n",lotto[i],lotto[j],lotto[k],lotto[l],lotto[o],lotto[p]);
                                }
                            }
                        }
                    }
                }
            }
            
        } else {
            break;
        }
    }
    
    return 0;
}
