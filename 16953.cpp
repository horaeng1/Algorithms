#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct Point{
    long long int num;
    long long int cnt;
};
Point p;

int main() {
    queue <Point> q;
    long long a,b,x,cnt;

    scanf("%lld %lld", &a, &b);
    p.num = a;
    p.cnt = 1;
    q.push(p);
    int result=-1;

    while(!q.empty()){
        x = q.front().num;
        cnt = q.front().cnt;
        q.pop();
        
        if(x==b){
            result = cnt;
            break;
        }
        long long int n1 = x*2;
        long long int n2 = x*10+1;
        
        if(n1 <= b){
            p.num = n1;
            p.cnt = cnt+1;
            q.push(p);
        }
        if(n2 <= b){
            p.num = n2;
            p.cnt = cnt+1;
            q.push(p);
        }
        
    }
    printf("%d", result);
    
    return 0;
}