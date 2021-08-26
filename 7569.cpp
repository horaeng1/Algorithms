#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int box[102][102][102];
bool flag[102][102][102]={false};
bool nonZero = true;
bool zero = false;
int result=0;
int n, m, h;
queue <int> qx;
queue <int> qy;
queue <int> qz;
void infect(int x, int y, int z){
  if(!flag[x-1][y][z] and x>1 and box[x-1][y][z]!=-1){
    if(box[x-1][y][z]==0) box[x-1][y][z]=box[x][y][z]+1;
    else box[x-1][y][z]=min(box[x-1][y][z], box[x][y][z]+1);
    flag[x-1][y][z]=true;
    qx.push(x-1);
    qy.push(y);
    qz.push(z);
  } 
  if(!flag[x][y-1][z] and y>1 and box[x][y-1][z]!=-1){
    if(box[x][y-1][z]==0) box[x][y-1][z]=box[x][y][z]+1;
    else box[x][y-1][z]=min(box[x][y-1][z], box[x][y][z]+1);
    flag[x][y-1][z]=true;
    qx.push(x);
    qy.push(y-1);
    qz.push(z);
  } 
  if(!flag[x][y][z-1] and z>1 and box[x][y][z-1]!=-1){
    if(box[x][y][z-1]==0) box[x][y][z-1]=box[x][y][z]+1;
    else box[x][y][z-1]=min(box[x][y][z-1], box[x][y][z]+1);
    flag[x][y][z-1]=true;
    qx.push(x);
    qy.push(y);
    qz.push(z-1);
  }
    
  if(!flag[x+1][y][z] and x<n and box[x+1][y][z]!=-1){
    if(box[x+1][y][z]==0) box[x+1][y][z]=box[x][y][z]+1;
    else box[x+1][y][z]=min(box[x+1][y][z], box[x][y][z]+1);
    flag[x+1][y][z]=true;
    qx.push(x+1);
    qy.push(y);
    qz.push(z);
  } 
  if(!flag[x][y+1][z] and y<m and box[x][y+1][z]!=-1){
    if(box[x][y+1][z]==0) box[x][y+1][z]=box[x][y][z]+1;
    else box[x][y+1][z]=min(box[x][y+1][z], box[x][y][z]+1);
    flag[x][y+1][z]=true;
    qx.push(x);
    qy.push(y+1);
    qz.push(z);
  } 
  if(!flag[x][y][z+1] and z<h and box[x][y][z+1]!=-1){
    if(box[x][y][z+1]==0) box[x][y][z+1]=box[x][y][z]+1;
    else box[x][y][z+1]=min(box[x][y][z+1], box[x][y][z]+1);
    flag[x][y][z+1]=true;
    qx.push(x);
    qy.push(y);
    qz.push(z+1);
  } 
}


int main() {

  //Please Enter Your Code Here
  scanf("%d %d %d", &n, &m, &h);
  int tmp;
  for(int i=1; i<=h; i++){
    for(int j=1; j<=m; j++){
      for(int k=1; k<=n; k++){
        scanf("%d", &box[k][j][i]);
        if(box[k][j][i]==1){
          qx.push(k);
          qy.push(j);
          qz.push(i);
          flag[k][j][i]=true;
        }
        else if(box[k][j][i]==0) nonZero=false;
      }
    }
  }
  int x,y,z;
  while(!qx.empty()){
    x=qx.front();
    qx.pop();
    y=qy.front();
    qy.pop();
    z=qz.front();
    qz.pop();
    infect(x,y,z);
  }
  
  for(int i=1; i<=h; i++){
    for(int j=1; j<=m; j++){
      for(int k=1; k<=n; k++){
        if(box[k][j][i]==0) zero=true;
        if(result<box[k][j][i]) result=box[k][j][i];
        // printf("%d ", box[k][j][i]);
      }
      // printf("     y=%d z=%d\n" ,j,i);
    }
  }
  if(nonZero) printf("0");
  else if(zero) printf("-1");
  else{
    printf("%d", result-1);
  }

  return 0;
}