//
//  B10845.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2018. 10. 23..
//  Copyright © 2018년 Minhyoung. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

class queue{
private:
    int maxSize;
    int arraySize;
    int frontIndex;
    int backIndex;
    int *array;
    
public:
    queue(int max){
        array = new int[max];
        maxSize = max;
        arraySize = 0;
        frontIndex = 0;
        backIndex = 0;
    }
    
    void push(int data){
        array[backIndex++] = data;
        arraySize++;
    }
    
    void pop(){
        std::cout<<array[frontIndex++] << std::endl;
        arraySize--;
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
    
    int front(){
        return array[frontIndex];
    }
    
    int back(){
        return array[backIndex-1];
    }
    
};

int main(int argc, char *argv[]){
    int N;
    std::cin >> N;
    std::cin.get();
    
    queue q(N);
    
    for(int i=0;i<N;i++){
        std::string a;
        getline(std::cin, a, '\n');
        
        if (a.find("push") != std::string::npos) {
            std::istringstream split(a);
            std::string tmp;
            split >> tmp;
            split >> tmp;
            q.push(std::stoi(tmp));
        } else if(a.find("pop") != std::string::npos){
            if(q.empty()){
                std::cout<<-1<<std::endl;
            } else {
                q.pop();
            }
        } else if(a.find("size") != std::string::npos){
            std::cout<<q.size()<<std::endl;
        } else if(a.find("empty") != std::string::npos){
            if(q.empty()){
                std::cout<<"1"<<std::endl;
            } else {
                std::cout<<"0"<<std::endl;
            }
        } else if(a.find("front") != std::string::npos){
            if(q.empty()){
                std::cout<<-1<<std::endl;
            } else {
                std::cout<<q.front()<<std::endl;
            }
        } else if(a.find("back") != std::string::npos){
            if(q.empty()){
                std::cout<<-1<<std::endl;
            } else {
                std::cout<<q.back()<<std::endl;
            }
        }
        
    }
    return 0;
}
