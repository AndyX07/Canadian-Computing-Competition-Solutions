#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10001];
vector<int> d(10001, INT_MAX);

int shortest_path(vector<int> e, int n){
    bool visited[n+1];
    memset(visited, 0, sizeof(visited));
    d[1] = 1;
    priority_queue<pair<int, int>> q;
    q.push({d[1], 1});
    while(!q.empty()){
        int a = q.top().second;
        q.pop();
        if(visited[a]) continue;
        visited[a] = 1;
        for(auto x : adj[a]){
            if(d[x] > d[a] + 1){
                d[x] = d[a]+1;
                q.push({-d[x], x});
            }
        }
    }
    bool b = false;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cout << "N" << endl;
            b = true;
            break;
        }
    }
    if(!b){
        cout << "Y" << endl;
    }
    int shortest = INT_MAX;
    for(auto x : e){
        shortest = min(shortest, d[x]);
    }
    return shortest;
}

int main()
{
    int n;
    cin >> n;
    vector<int> e;
    for(int i = 1; i <= n; i++){
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
            int a;
            cin >> a;
            adj[i].push_back(a);
        }
        if(m==0){
            e.push_back(i);
        }
    }
    cout << shortest_path(e, n) << endl;
    return 0;
}
