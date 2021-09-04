#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int l,p,v,result=0;

int main() {
    int cnt=0;
    while(1){
        result =0;
        cnt++;
        scanf("%d %d %d", &l, &p, &v);
        if(l==0 and p==0 and v==0){
            break;
        }
        result += ((v/p)*l) + min(v%p, l);
        
        printf("Case %d: %d\n", cnt, result);
    }
    return 0;
}