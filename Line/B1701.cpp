//
//  B1701.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 2. 8..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <string>
#include <iostream>
#include <vector>
using namespace std;
string str;
int getPi(string str){
    int max = 0;
    int length = str.size(), j = 0;
    vector<int> pi(length,0);
    for(int i=1;i<length;i++){
        while (j>0 && str[i] != str[j]) {
            j = pi[j-1];
        }
        if(str[i] == str[j]){
            pi[i] = ++j;
            
            if(max < pi[i]){
                max = pi[i];
            }
        }
    }
    return max;
}
int main(int argc,const char* argv[]){
    getline(cin, str,'\n');
    int max = 0;
    for(int i=0;i<str.size();i++){
        int tmp = getPi(str.substr(i));
        if(max < tmp)
            max = tmp;
    }

    printf("%d",max);
    return 0;
}
