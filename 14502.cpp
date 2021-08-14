#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
struct Point{
  int x;
  int y;
};

queue <Point> virus;
vector <Point> wall;
int staticMap[10][10];
int map[10][10];
int n,m, answer=0;
Point p;
int dxdy[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

void setWall(int a, int b, int c){
  map[wall[a].x][wall[a].y]=1;
  map[wall[b].x][wall[b].y]=1;
  map[wall[c].x][wall[c].y]=1;
}

void mapReset(){
  for(int i=0; i<=n+1; i++){
    for(int j=0; j<=m+1; j++){
      map[i][j]= staticMap[i][j];
      if(map[i][j]==2){
        p.x=i;
        p.y=j;
        virus.push(p);
      }
    }
  }
}

int compareMax(){
  int cnt=0;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      if(map[i][j]==0) cnt++;
    }
  }
  if(cnt>answer) return cnt;
  else return answer;
}

void spreadVirus(){
  int x,y, dx, dy;
  x=virus.front().x;
  y=virus.front().y;
  
  while(!virus.empty()){
    x=virus.front().x;
    y=virus.front().y;
    virus.pop();
    for(int i=0; i<4; i++){
      dx = x + dxdy[i][0];
      dy = y + dxdy[i][1];
      if(map[dx][dy] == 0){
        map[dx][dy] = 2;
        p.x = dx;
        p.y = dy;
        virus.push(p);
      }
    }
  }
}

int main() {

  //Please Enter Your Code Here
  scanf("%d %d", &n, &m);
  for(int i=0; i<=n+1; i++){
    for(int j=0; j<=m+1; j++){
      staticMap[i][j]=1;
    }
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      scanf("%d", &staticMap[i][j]);
      if(staticMap[i][j]==0){
        p.x = i;
        p.y = j;
        wall.push_back(p);
      }
    }
  }
  // ~~초기값 세팅
  mapReset();
  for(int i=0; i<wall.size()-2; i++){
    for(int j=i+1; j<wall.size()-1; j++){
      for(int k=j+1; k<wall.size(); k++){
        mapReset();
        setWall(i, j, k);
        spreadVirus();
        answer = compareMax();
      }
    }
  }
  printf("%d", answer);

  return 0;
}