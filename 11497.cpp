#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;



int main() {
    int t;
    scanf("%d", &t);
    for(int test=0; test<t; test++){
        int n,k,result=0;
        vector <int> arr;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &k);
            arr.push_back(k);
        }
        sort(arr.begin(), arr.end());
        for(int i=0; i<n-2; i++){
            result = max(result, arr[i+2]-arr[i]);
        }
        printf("%d\n", result);
    }

    
    return 0;
}