#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Point{
    int x;
    int y;
};
int dxdy[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1}};
queue <Point> q;
Point p;
int visited[1005][1005] = {-1};
int map[1005][1005] = {-1};

int run(){
    int dx, dy, x, y, cnt=0, qsize;
    while(!q.empty()){
        qsize = q.size();
        cnt++;
        for(int i=0; i<qsize; i++){
            x = q.front().x;
            y = q.front().y;
            q.pop();
            for(int i=0; i<4; i++){
                dx = x + dxdy[i][0];
                dy = y + dxdy[i][1];
                if(map[dx][dy]==0){
                    map[dx][dy] = 1;
                    p.x = dx;
                    p.y = dy;
                    q.push(p);
                }
            }
            
        }

    }
    return cnt;
}


void mapReset(int n, int m){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            map[i][j]=-1;
            visited[i][j]=0;
        }
    }
}

int main() {
    int n,m, cnt, k;
    bool flag = false;
    scanf("%d %d\n", &m, &n);
    mapReset(n+2,m+2);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &k);
            map[i][j] = k;
            if(k==1){
                p.x = i;
                p.y = j;
                q.push(p);
                visited[i][j]=1;
            }
        }
    }

    cnt = run();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j]==0){
                flag=true;
            }
        }
    }
    if(flag){
        printf("-1");
    }
    else if(cnt==1){
        printf("0");
    }
    else{
        printf("%d\n", cnt-1);
    }
    

    return 0;
}