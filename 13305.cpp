#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

long long gas[100005] = {0};
long long dis[100005] = {0};

int main() {
    long long n,a;
    long long result=0;
    scanf("%lld", &n);
    for(int i=0; i<n-1; i++){
        scanf("%lld", &a);
        dis[i]=a;
    }
    for(int i=0; i<n; i++){
        scanf("%lld", &a);
        gas[i]=a;
    }
    long long now = gas[0];
    long long nowdis = 0;
    
    for(int i=0; i<n-1; i++){
        nowdis += dis[i];
        if(now > gas[i+1]){
            result += (now*nowdis);
            nowdis=0;
            now = gas[i+1];
        }
    }
    if(nowdis!=0){
        result += (now*nowdis);
    }
        
    printf("%lld", result);
    return 0;
}