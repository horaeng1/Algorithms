#include <stdio.h>

int n, m, k, x=1, y=1, count=0, sum = 0;

void getRoute(int sx, int sy, int ex, int ey){
  if(sx==ex and sy==ey){
    count++;
    return;
  }
  if(sx <ex){
    getRoute(sx+1, sy, ex, ey);
  }
  if(sy < ey){
    getRoute(sx, sy+1, ex, ey);
  }
}

int main() {

  //Please Enter Your Code Here
  scanf("%d %d %d", &n, &m, &k);
  
  if(k>0){
    if(k<=m) x=1;
    else if(k%m==0) x = k / m;
    else x = k / m + 1;
    y = k % m;
    if(y==0) y=m;
    getRoute(1, 1, x, y);
    sum = count;
    count = 0;
  }
  getRoute(x, y, n, m);
  if(count==0) printf("%d", sum);
  else if(sum == 0) printf("%d", count);
  else printf("%d", sum*count);

  return 0;
}