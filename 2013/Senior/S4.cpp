#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
int n, m;

bool bfs(int x, int y){
    bool visited[n+1];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(t==y) return true;
        if(visited[t]) continue;
        visited[t] = 1;
        for(auto z:adj[t]){
            if(!visited[z]){
                q.push(z);
            }
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for(int i=0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    int p, q;
    cin >> p >> q;
    if(bfs(p, q))cout << "yes" << endl;
    else if(bfs(q, p)) cout << "no" << endl;
    else cout << "unknown" << endl;
    return 0;
}
