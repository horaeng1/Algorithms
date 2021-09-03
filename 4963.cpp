#include <stdio.h>
//#include <iostream>
#include <queue>
using namespace std;
int dxdy[8][2] = { {-1, -1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };
struct Point{
    /* data */
    int x;
    int y;
};

queue <Point> q;
Point p;
int map[100][100];
bool visited[100][100];

void run(){
    int dx, dy, x, y;
    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        q.pop();
        //printf("Queue : %d %d\n", x,y);
        for(int i=0; i<8; i++){
            dx = x + dxdy[i][0];
            dy = y + dxdy[i][1];
            if(map[dx][dy]==1){
                if(!visited[dx][dy]){
                    visited[dx][dy] = 1;
                    p.x = dx;
                    p.y = dy;
                    q.push(p);
                }
            }
        }
    }
}
void mapReset(int n, int m){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            map[i][j]=0;
            visited[i][j]=0;
        }
    }
}
int main() {
    int n,m, count;
    while(1){
        count = 0;
        scanf("%d %d", &m, &n);
        if(n==0 and m==0){
            break;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                scanf("%d", &map[i][j]);
                visited[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if(map[i][j] and !visited[i][j]){
                    //printf("point %d %d\n", i,j);
                    count++;
                    p.x = i;
                    p.y = j;
                    q.push(p);
                    visited[i][j] = 1;
                    run();
                }
            }
        }
        printf("%d\n",count);
        mapReset(n,m);
    }
    



    return 0;
}