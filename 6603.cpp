#include <stdio.h>
int n;
int data[50];
bool flag[50];
void getSix(int x, int count){
  if(count>=6){
    for(int i=1; i<=50; i++){
      if(flag[i]==true){
        printf("%d ", data[i]);
      }
    }
    printf("\n");
  }
  else{
    for(int i=x; i<=n; i++){
      if(flag[i]==false){
        flag[i]=true;
        getSix(i, count+1);
        flag[i]=false;
      }  
    }
    
  }
}
int main() {

  //Please Enter Your Code Here
  
  while(1){
    scanf("%d", &n);
    if(n==0) break;
    for(int i=0; i<50; i++){
      flag[i]=false;
    }
    for(int i=1; i<=n; i++){
      scanf("%d", &data[i]);
    }
    getSix(1, 0);
    
    
    printf("\n");
  }

  return 0;
}