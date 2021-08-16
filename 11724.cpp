#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
queue <int> q;
int visited[1005] = {0};
int map[1005][1005] = {0};

void run(int t){
    int x;
    while(!q.empty()){
        x = q.front();
        q.pop();
        //printf("Queue : %d %d\n", x,y);
        for(int i=1; i<=t; i++){
            if(map[x][i]==1 and visited[i]==0){
                q.push(i);
                visited[i]=1;
            }
            
        }
    }
}

void mapReset(int n, int m){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            map[i][j]=0;
        }
        visited[i]=0;
    }
}

int main() {
    int n,m,u,v,result=0;
    scanf("%d %d", &n, &m);
    mapReset(n+2,m+2);
    for(int i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        map[u][v]=1;
        map[v][u]=1;
    }
    for(int i=1; i<=n; i++){
        if(visited[i]==0){
            result++;
            visited[i]=1;
            q.push(i);
            run(n);
        }
    }
    printf("%d", result);
    return 0;
}