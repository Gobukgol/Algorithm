//
//  B10828.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2018. 10. 9..
//  Copyright © 2018년 Minhyoung. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

class stack{
private:
    int maxSize;
    int arraySize;
    int *array;
    
public:
    stack(int max){
        array = new int[max];
        arraySize = 0;
        maxSize = max;
    }
    
    int size(){
        return arraySize;
    }
    
    bool empty(){
        if(arraySize == 0){
            return true;
        } else {
            return false;
        }
    }
    
    int top(){
        if(empty() == true){
            
        } else {
            
        }
        return array[arraySize-1];
    }
    
    void pop(){
        if(empty() == true){
            std::cout << -1 <<std::endl;
        } else {
            std::cout << array[arraySize-1]<<std::endl;
            array[arraySize-1] = NULL;
            arraySize -= 1;
        }
    }
    
    void push(int data){
        if(arraySize == maxSize){
            //배열 2배로 늘리기
            maxSize *= 2;
            int *temp = new int[maxSize];
            for(int i=0;i<arraySize;i++){
                temp[i] = array[i];
            }
            array = temp;
        }
        array[arraySize] = data;
        arraySize += 1;
    }
};

int main(int argc, char* argv[]){
    int N;
    std::cin >> N;
    std::cin.get();
    stack s(N);
    for(int i=0;i<N;i++){
        std::string a;
        getline(std::cin, a, '\n');
        
        if (a.find("push") != std::string::npos) {
            std::istringstream split(a);
            std::string tmp;
            split >> tmp;
            split >> tmp;
            s.push(std::stoi(tmp));
        } else if(a.find("pop") != std::string::npos){
            if(s.empty()){
                std::cout<<-1<<std::endl;
            } else {
                s.pop();
            }
        } else if(a.find("size") != std::string::npos){
            std::cout<<s.size()<<std::endl;
        } else if(a.find("empty") != std::string::npos){
            if(s.empty()){
                std::cout<<"1"<<std::endl;
            } else {
                std::cout<<"0"<<std::endl;
            }
        } else if(a.find("top") != std::string::npos){
            if(s.empty()){
                std::cout<<-1<<std::endl;
            } else {
                std::cout<<s.top()<<std::endl;
            }
        }
    }
    
    return 0;
}

