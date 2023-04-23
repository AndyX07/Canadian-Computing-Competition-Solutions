#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k, w;
        cin >> n >> k >> w;
        vector<int> v(n);
        vector<int> psum(n+1, 0);
        for(int i = 0; i < n; i++){
            cin >> v[i];
            psum[i+1]=psum[i]+v[i];
        }
        int dp[n][k+1];
        memset(dp, 0, sizeof(dp));
        for(int j = 1; j <=k; j++){
            for(int i=0; i<n; i++){
                if(i+1<=w){
                    dp[i][j]=psum[i+1];
                }
                else{
                    dp[i][j]=max(dp[i-w][j-1]+psum[i+1]-psum[i-w+1], dp[i-1][j]);
                }
            }
        }
        cout << dp[n-1][k] << endl;
    }
    return 0;
}
