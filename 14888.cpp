#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int sym[4];
int n, k;
long long int x=1000000001, y=-1000000001;
vector <int> arr;

void run(int cnt, long long int sum, int a, int b, int c, int d){
    // printf("%d %d %d %d %d %d\n", cnt, sum, a, b, c, d);
    if(cnt==n){
        x = min(x,sum);
        y = max(y,sum);
        return;
    }
    if(a>0){
        run(cnt+1, sum+arr[cnt], a-1, b, c, d);
    }
    if(b>0){
        run(cnt+1, sum-arr[cnt], a, b-1, c, d);
    }
    if(c>0){
        run(cnt+1, sum*arr[cnt], a, b, c-1, d);
    }
    if(d>0){
        run(cnt+1, sum/arr[cnt], a, b, c, d-1);
    }
    
}

int main() {

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &k);
        arr.push_back(k);
    }
    for(int i=0; i<4; i++){
        scanf("%d", &k);
        sym[i] = k;
    }
    // printf("%d %d %d %d %d %d\n", 1, arr[0], sym[0], sym[1], sym[2], sym[3]);
    run(1, arr[0], sym[0], sym[1], sym[2], sym[3]);

    printf("%lld\n%lld", y,x);
    return 0;
}