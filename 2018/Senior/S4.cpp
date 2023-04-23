#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, long long> dp;

long long recursion(long long n){
    if(dp.find(n)!=dp.end()) return dp[n];
    for(int i = 2; i <= n;){
        int t=n/i;
        int j=n/t+1;
        dp[n]+=(j-i)*recursion(t);
        i=j;
    }
    return dp[n];
}

/*
long long recursion(long long n){
    if(dp.find(n)!=dp.end()) return dp[n];
    long long ans=0;
    for(int i=2; i<=n; i++){
        int t=n/i;
        ans+=recursion(t);
    }
    dp[n]=ans;
    return dp[n]
}
*/
int main()
{
    long long n;
    cin >> n;
    dp[1]=1;
    cout << recursion(n) << endl;
    return 0;
}
