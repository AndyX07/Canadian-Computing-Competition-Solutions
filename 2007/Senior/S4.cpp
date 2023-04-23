#include <bits/stdc++.h>

using namespace std;

vector<int> dp(10000, 0);
vector<int> adj[10000];

int g(int x){
    if(dp[x]!=0){
        return dp[x];
    }
    for(auto y : adj[x]){
        dp[x]+=g(y);
    }
    return dp[x];
}

int main()
{
    int n;
    cin >> n;
    dp[1]=1;
    int x, y;
    while(cin >> x >> y && x!=0 && y !=0){
        adj[y].push_back(x);
    }
    cout << g(n) << endl;
    return 0;
}
