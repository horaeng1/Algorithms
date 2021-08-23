#include <stdio.h>
using namespace std;

int main() {
    long n,sum=0, mod = 1000000000;
    long dp[110][10];
    scanf("%ld", &n);
    for(int i=1; i<10; i++){
        dp[1][i] = 1;
    }
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            if(j==0){
                dp[i][j] = dp[i-1][1] % mod;
            }
            else if(j==9){
                dp[i][j] = dp[i-1][8] % mod;
            }
            else{
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % mod;
            }
        }
    }
    
    for(int i=0; i<10; i++){
        sum += dp[n][i];
        sum = sum % mod;
    }
    printf("%ld", sum);
    return 0;
}