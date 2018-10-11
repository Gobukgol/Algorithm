//
//  B1874.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2018. 10. 10..
//  Copyright © 2018년 Minhyoung. All rights reserved.
//

#include <iostream>
#include <stack>

std::stack<int> s1;
std::stack<int> s2;
int *suyeol;
char result[1000001];
int main(int argc, char *argv[]){
    int chk = 0;
    int N;
    int num = 1;
    bool check = false;
    
    std::cin.tie(NULL);
    std::cin >> N;
    suyeol = new int[N];
    for(int i=0;i<N;i++){
        std::cin >> suyeol[i];
    }
    
    for(int i=0;i<N;i++){
        if(suyeol[i] < num){
            check = false;
            while(!s2.empty()){
                if(s2.top() == suyeol[i]){
                    s2.pop();
                    result[chk++] = '-';
                    check = true;
                    break;
                } else {
                    s2.pop();
                    result[chk++] = '-';
                }
            }
            if(!check){
                std::cout << "NO" << std::endl;
                return 0;
            }
        } else {
            for(;num<=suyeol[i];num++){
                s2.push(num);
                result[chk++] = '+';
            }
            s2.pop();
            result[chk++] = '-';
        }
    }
    for(int i=0;i<chk;i++){
        std::cout<<result[i] << '\n';
    }
    
    return 0;
}
