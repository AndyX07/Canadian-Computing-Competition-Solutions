#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    long long dp[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> dp[i][j];
        }
    }
    long long t = 0;
    vector<int> v;
    int temp=k;
    if(k>2){
        v.push_back(k);
        while(k>2){
            k=(2*k+2)/3;
            v.push_back(k);
        }
        v.push_back(2);
        v.push_back(1);
    }
    else{
        v={2, 1};
    }
    k=temp;
    reverse(v.begin(), v.end());
    for(int i = 1; i < v.size()&&v[i]<=k; i++){
        for(int j = 0; j <= n-v[i]; j++){
            for(int l = 0; l <= j; l++){
                int m = v[i]-v[i-1];
                dp[j][l]=max(max(dp[j][l], dp[j+m][l]), dp[j+m][l+m]);
            }
        }
    }
    for(int i = 0; i <= n-k; i++){
        for(int j = 0; j <= i; j++){
            t+=dp[i][j];
        }
    }
    cout << t << endl;
    return 0;
}
