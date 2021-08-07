#include <stdio.h>
long long int n, ans=0;
int main() {

  //Please Enter Your Code Here
  scanf("%lld", &n);
  for(long long int i=1; i*i<=n; i++){
    ans++;
  }
  printf("%lld", ans);

  return 0;
}