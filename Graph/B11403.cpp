//
//  B11403.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 1. 2..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <iostream>
#include <queue>

typedef struct point{
    int x;
    int y;
    int from;
} Point;

int N;
int **matrix;
int **result;
std::queue<Point> q;
int main(int argc, const char *argv[]){
    std::cin>>N;
    matrix = new int*[N];
    result = new int*[N];
    for(int i=0;i<N;i++){
        matrix[i] = new int[N];
        result[i] = new int[N];
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            std::cin>>matrix[i][j];
            if(matrix[i][j] == 1){
                Point point;
                point.x = i;
                point.y = j;
                point.from = i;
                q.push(point);
            }
            result[i][j] = 0;
        }
    }
    
    while(!q.empty()){
        Point temp = q.front();
        q.pop();
        if(result[temp.from][temp.y] != 1){
            result[temp.from][temp.y] = 1;
            
            for(int i=0;i<N;i++){
                if(matrix[temp.y][i] == 1){
                    Point point;
                    point.x = temp.y;
                    point.y = i;
                    point.from = temp.from;
                    q.push(point);
                }
            }
        }
    }
    
    
    //출력
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            std::cout<<result[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    
    return 0;
}
