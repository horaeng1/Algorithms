#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n, m, num;
    
    cin >> n >> m;

    int dp[1030][1030];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> num;
            dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] + num - dp[i][j];
        }
    }
    for(int i=0; i<m; i++){
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << dp[y2][x2] - dp[y1-1][x2] - dp[y2][x1-1] + dp[y1-1][x1-1] << "\n";
    }
    
    return 0;
}