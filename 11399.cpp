#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int map[1005] = {0};

int run(int n){
    int result=0, stk=0;
    for(int i=0; i<n; i++){
        stk += map[i];
        result += stk;
    }
    return result;
}

void mapReset(int n){
    for(int i=0; i<n; i++){
        map[i]=0;
    }
}

int main() {
    int n,k,result=0;
    scanf("%d", &n);
    mapReset(n);
    for(int i=0; i<n; i++){
        scanf("%d", &k);
        map[i] = k;
    }
    sort(map, map+n);
    result = run(n);
        
    printf("%d", result);
    return 0;
}