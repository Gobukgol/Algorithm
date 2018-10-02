//
//  main.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2018. 10. 2..
//  Copyright © 2018년 Minhyoung. All rights reserved.
//

#include <iostream>
#include <queue>

void dfs(int verNum);
void bfs();
int vertex, line, verNum;
int** matrix;
int* visit;
std::queue <int>q;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin >> vertex>>line>>verNum;
    
    matrix = new int*[vertex+1];
    visit = new int[vertex+1];
    
    int i;
    for(i=0;i<vertex+1;i++){
        matrix[i] = new int[vertex+1];
    }
    
    for(i=0;i<vertex+1;i++){
        visit[i] = 0;
        for(int j=0;j<vertex+1;j++){
            matrix[i][j] = 0;
        }
    }
    for(i=0;i<line;i++){
        int ver1,ver2;
        std::cin >> ver1>>ver2;
        matrix[ver1][ver2] = 1;
        matrix[ver2][ver1] = 1;
    }
    q.push(verNum);
    visit[verNum] = 1;
    dfs(verNum);
    while(!q.empty()){
        visit[q.front()] = 0;
        std::cout << q.front();
        q.pop();
        if(!q.empty()){
            std::cout << " ";
        }
    }
    
    std::cout<< std::endl;
    
    q.push(verNum);
    visit[verNum] = 1;
    bfs();
    
    return 0;
}

void dfs(int verNum){
    int currNum = verNum;
    for(int i=1;i<=vertex;i++){
        if(i == currNum){
            continue;
        } else {
            if(matrix[currNum][i] == 1 && visit[i] == 0){
                q.push(i);
                visit[i] = 1;
                if(q.size() == vertex){
                    return;
                } else {
                    dfs(i);
                }
            }
        }
    }
}

void bfs(){
    int currNum;
    while(!q.empty()){
        currNum = q.front();
        q.pop();
        for(int i=1;i<=vertex;i++){
            if(i == currNum){
                continue;
            } else {
                if(matrix[currNum][i] == 1 && visit[i] == 0){
                    q.push(i);
                    visit[i] = 1;
                }
            }
        }
        std::cout << currNum;
        if(!q.empty()){
            std::cout<<" ";
        }
    }
}
