#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX =55;
int n,m, x,y,dir, ans=1;
int map[MAX][MAX];
bool visited[MAX][MAX];
bool flag =true;
int dxdy[4][2]= { {-1,0}, {0,1}, {1,0}, {0,-1}};

int main() {

  //Please Enter Your Code Here
  scanf("%d %d", &n, &m);
  scanf("%d %d %d", &x, &y, &dir);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &map[i][j]);
    }
  }
  int dx,dy, tmp;
  visited[x][y]=true;
  while(flag){
    flag=false;
    // 4방향 청소할곳 확인
    for(int i=dir+3; i>=dir; i--){
      tmp = i%4;
      dx = x + dxdy[tmp][0];
      dy = y + dxdy[tmp][1];
      if(dx>=0 and dy>=0 and dx<n and dy<m and map[dx][dy]==0 and !visited[dx][dy]){
        // printf("%d %d %d\n", dx, dy, tmp);
        x = dx;
        y = dy;
        dir = tmp;
        flag=true;
        ans++;
        visited[dx][dy]=true;
        break;
      }
    }
    // 빠꾸
    if(!flag){
      dx = x - dxdy[dir][0];
      dy = y - dxdy[dir][1];
      if(dx>=0 and dy>=0 and dx<n and dy<m and map[dx][dy]==0){
        x = dx;
        y = dy;
        flag=true;
      }
    }
    
    
  }
  
  printf("%d", ans);
  return 0;
}