#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
int dp[200001][3];
string p = "A";
int c[200001];
int n;

int dfs(int x, int y){
    if(dp[x][y]!=-1)return dp[x][y];

}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    adj.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    string s;
    cin >> s;
    p+=s;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    cout << dfs(1, 0) << endl;
    return 0;
}
