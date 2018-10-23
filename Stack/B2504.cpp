//
//  B2504.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2018. 10. 17..
//  Copyright © 2018년 Minhyoung. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

int main(int argc, char *argv[]){
    std::stack<int> s;
    std::string a;
    std::cin >> a;
    
    for(int i=0;i<a.length();i++){
        switch (a.at(i)) {
            case '(':
                s.push(a.at(i) * -1);
                break;
            case '[':
                s.push(a.at(i) * -1);
                break;
                
            case ')':
            {
                int tmp = 0;
                
                if(s.empty()){
                    std::cout << 0;
                    return 0;
                }
                
                while(!s.empty() && s.top() != ('(' * -1) && s.top() != ('[' *-1)){
                    tmp += s.top();
                    s.pop();
                }
                
                if(s.empty()){
                    std::cout<<0;
                    return 0;
                }
                
                
                if(s.top() == '[' *-1 ) {
                    std::cout << 0;
                    return 0;
                }
                if(tmp == 0){
                    s.pop();
                    s.push(2);
                } else {
                    s.pop();
                    s.push(tmp * 2);
                }
                break;
            }
            case ']':
                int tmp = 0;
                
                if(s.empty()){
                    std::cout << 0;
                    return 0;
                }
                
                while(!s.empty() && s.top() != ('(' * -1) && s.top() != ('[' *-1)){
                    tmp += s.top();
                    s.pop();
                }
                
                if(s.empty()){
                    std::cout<<0;
                    return 0;
                }
                
                if(s.top() == '(' *-1 ) {
                    std::cout << 0;
                    return 0;
                }
                if(tmp == 0){
                    s.pop();
                    s.push(3);
                } else {
                    s.pop();
                    s.push(tmp * 3);
                }
                break;
        }
    }
    
    if(s.size() > 0){
        int result = 0;
        while(!s.empty()){
            switch (s.top()) {
                case ('('*-1):
                case (')'*-1):
                case ('['*-1):
                case (']'*-1):
                    std::cout << 0;
                    return 0;
                    break;
                default:
                    result += s.top();
                    s.pop();
                    break;
            }
        }
        std::cout << result;
    } 
    return 0;
}

