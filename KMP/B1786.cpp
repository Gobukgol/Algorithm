//
//  B1786.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 2. 8..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> getPi(string str){
    int length = str.size(), j = 0;
    vector<int> pi(length,0);
    for(int i=1;i<length;i++){
        while(str[i] != str[j] && j>0){
            j = pi[j-1];
        }
        if(str[i] == str[j]){
            pi[i] = ++j;
        }
    }
    
    return pi;
}

vector<int> kmp(string T,string P){
    vector<int> answer;
    auto pi = getPi(P);
    int n = T.size(); int m = P.size(); int j = 0;
    
    for(int i=0;i<n;i++){
        while(j>0 && T[i] != P[j]){
            j = pi[j-1];
        }
        if(T[i] == P[j]){
            if(j == m - 1){
                answer.push_back(i-m+1);
                j=pi[j];
            } else {
                j++;
            }
        }
    }
    
    return answer;
}

int main(int argc,const char* argv[]){
    string T,P;
    getline(cin,T);
    getline(cin,P);
    auto answer = kmp(T,P);
    
    printf("%d\n",answer.size());
    
    for(auto i : answer){
        printf("%d ",i+1);
    }
    return 0;
}
