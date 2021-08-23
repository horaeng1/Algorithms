#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;


int main() {
    int dp[10010];
    int arr[10010];
    int n, k;
    scanf("%d", &n);
    
    dp[0]=0;
    dp[1]=1;
    
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    
    printf("%d", dp[n]);
    return 0;
}