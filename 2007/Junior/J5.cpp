#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<long long> v = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    int a, b, c;
    cin >> a >> b >> c;
    for(int i = 0; i < c; i++){
        long long m;
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(), v.end());
    long long dp[14+c];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < 14+c; i++){
        if(i < 14+c-1){
            for(int j = i+1; j < 14+c; j++){
                if(b >= v[j]-v[i] && a <= v[j]-v[i]){
                    dp[j]+=dp[i];
                }
            }
        }
    }
    cout << dp[14+c-1] << endl;
    return 0;
}
