#include <stdio.h>
int gear[10][10], leftIdx[10], rightIdx[10];
int k;

void doLeft(int num, int ns, int direction){
  int next_num =num-1;
  int next_ns = gear[next_num][rightIdx[next_num]];
  if(next_num>=1){
    if(ns != next_ns){
      doLeft(next_num, gear[next_num][leftIdx[next_num]], -direction);
      leftIdx[next_num] += direction;
      rightIdx[next_num] += direction;
    }
  }
}

void doRight(int num, int ns, int direction){
  int next_num =num+1;
  int next_ns = gear[next_num][leftIdx[next_num]];
  if(next_num<=4){
    if(ns != next_ns){
      doRight(next_num, gear[next_num][rightIdx[next_num]], -direction);
      leftIdx[next_num] += direction;
      rightIdx[next_num] += direction;
    }
  }
}

int main() {

  //Please Enter Your Code Here
  char tmp[10];
  for(int i=1; i<=4; i++){
    scanf("%s", &tmp);
    for(int j=0; j<8; j++){
      gear[i][j] = tmp[j]-48;
    }
    leftIdx[i] = 6;
    rightIdx[i] = 2;
  }
  scanf("%d", &k);
  
  int num,dir;
  for(int i=0; i<k; i++){
    
    scanf("%d %d", &num, &dir);
    doRight(num, gear[num][rightIdx[num]] ,dir);
    doLeft(num, gear[num][leftIdx[num]], dir);
    leftIdx[num] -= dir;
    rightIdx[num] -=dir;
    for(int j=1; j<=4; j++){
      leftIdx[j] += 8;
      rightIdx[j] += 8;
      leftIdx[j] %= 8;
      rightIdx[j] %= 8;
    }
  }
  int ans=0, sum=1;
  for(int i=1; i<=4; i++){
    if(gear[i][(rightIdx[i]+6)%8]) ans += sum;
    sum *=2;
  }
  
  printf("%d", ans);

  return 0;
}