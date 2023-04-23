#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> mul[1000001];
int grid[1001][1001];
int m, n;

bool bfs(){
    queue<pair<int, int>> q;
    bool visited[1001][1001];
    memset(visited, 0, sizeof(visited));
    q.push({1, 1});
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if(visited[a][b]) continue;
        visited[a][b] = 1;
        if(a == n && b == m) return true;
        for(auto x : mul[grid[a][b]]){
            q.push({x.first, x.second});
        }
    }
    return false;
}

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            int a;
            cin >> a;
            mul[i*j].push_back({j, i});
            grid[j][i] = a;
        }
    }
    if(bfs()){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
    return 0;
}
