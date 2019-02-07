//
//  B11726.cpp
//  23rdSoptAlgo
//
//  Created by Minhyoung on 2019. 2. 7..
//  Copyright © 2019년 Minhyoung. All rights reserved.
//

#include <cstdio>
int main(int argc,const char* argv[]){
    int dp[1001];
    int n;
    scanf("%d",&n);
    dp[1] = 1; dp[2] = 2;
    
    for(int i=3;i<=n;i++)
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    
    printf("%d",dp[n]);
    
    return 0;
}
