#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, answer=987987987, tmp, myTrue=0, myFalse=0;
int map[22][22];
bool visited[22];

void getSum(){
  myTrue =0;
  myFalse=0;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(!visited[i] and !visited[j]) myTrue += map[i][j];
      if(visited[i] and visited[j]) myFalse += map[i][j];
    }
  }
}

void dfs(int x, int cnt){
  if(cnt>=n/2){
    getSum();
    tmp = myTrue - myFalse;
    if(tmp<0) tmp = -tmp;
    answer = min(answer,tmp);
    return;
  }
  for(int i=x+1; i<=n; i++){
    visited[i]=true;
    dfs(i, cnt+1);
    visited[i]=false;
  }
  
}

int main() {

  //Please Enter Your Code Here
  scanf("%d", &n);
  
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      scanf("%d", &map[i][j]);
    }
  }
  visited[1]=true;
  dfs(1, 1);
  printf("%d", answer);

  return 0;
}