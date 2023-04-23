#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> adj(1000001);
int g[1001][1001];
bool visited[1001][1001];

void dfs(int x, int y){
    if(visited[x][y])return;
    visited[x][y]=1;
    for(auto z : adj[g[x][y]]){
        if(!visited[z.first][z.second]){
            dfs(z.first, z.second);
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i<=m; i++){
        for(int j = 1; j <= n; j++){
            adj[i*j].push_back({i, j});
            int a;
            cin >> a;
            g[i][j]=a;
        }
    }
    dfs(1, 1);
    if(visited[m][n]){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
    return 0;
}
