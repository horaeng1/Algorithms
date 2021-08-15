#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int,int>> vec;
int n, myMax = 0;

void bf(int x, int sum){
  if(x+vec[x].first>n){
    return;
  }
  else{
    sum += vec[x].second;
    myMax = max(myMax, sum);
    for(int i=x+vec[x].first; i<vec.size(); i++){
      bf(i, sum);
    }
  }
}
int main() {

  //Please Enter Your Code Here
  scanf("%d", &n);
  int a, b;
  
  
  for(int i=0; i<n; i++){
    scanf("%d %d", &a, &b);
    vec.push_back(make_pair(a,b));
  }
  
  for(int i=0; i<n; i++){
    bf(i, 0);
  }
  printf("%d", myMax);

  return 0;
}