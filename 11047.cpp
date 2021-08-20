#include <stdio.h>
#include <stack>
using namespace std;
int main() {
    long n, k, coin, count=0, sum=0, curCoin;
    stack <long> coinList;
    scanf("%ld %ld", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%ld", &coin);
        coinList.push(coin);
    }
    while(k!=sum){
        curCoin = coinList.top();
        coinList.pop();
        //printf("%ld\n", curCoin);
        while((sum+curCoin)<=k){
            sum += curCoin;
            count++;
        }
    }
    printf("%ld", count);

    return 0;
}