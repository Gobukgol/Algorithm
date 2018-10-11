//
//  B9012.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2018. 10. 9..
//  Copyright © 2018년 Minhyoung. All rights reserved.
//

#include <iostream>
#include <stack>

void vps(){
    std::stack<char>s;
    std::string a;
    std::cin >> a;
    for(int i=0;i<a.size();i++){
        if(a.at(i) == '('){
            s.push(a.at(i));
        } else {
            if(s.empty()){
                std::cout << "NO" << std::endl;
                return;
            } else {
                s.pop();
            }
        }
    }
    if(s.empty()){
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main(int argc, const char *argv[]){
    int N;
    std::cin >> N;
    
    for(int i=0;i<N;i++){
        vps();
    }
    return 0;
}

