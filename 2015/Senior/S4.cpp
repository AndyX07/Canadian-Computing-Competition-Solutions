#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, pair<int, int>>>> adj(2001);
vector<pair<int, int>> d(2001, {INT_MAX, INT_MAX});

int bfs(int a, int b, int k){
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {a, k}});
    int best = INT_MAX;
    while(!q.empty()){
        int w = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        //cout << x << " " << y << endl;
        q.pop();
        if(d[x].first <= w && d[x].second >= y){
            continue;
        }
        if(w > best){
            continue;
        }
        else if(w < d[x].first){
            d[x].first = w;
            d[x].second = y;
        }
        if(x == b){
            best = min(best, w);
            continue;
        }
        for(int i = 0; i < adj[x].size(); i++){
            int n = adj[x][i].first;
            int t = adj[x][i].second.first;
            int h = adj[x][i].second.second;
            if(y > h && w+t < best){
                //cout << x << " " << n << " " << w+t << " " << y-h << endl;
                q.push({w+t, {n, y-h}});
            }
        }
    }
    if(best == INT_MAX){
        return -1;
    }
    else{
        return best;
    }
}

/*
10 4 7
1 2 4 4
1 3 7 2
3 1 8 1
3 2 2 2
4 2 1 6
3 4 1 1
1 4 6 12
1 4
*/

int main()
{
    int k, n, m;
    cin >> k >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        adj[a].push_back({b, {t, h}});
        adj[b].push_back({a, {t, h}});
    }
    int a, b;
    cin >> a >> b;
    cout << bfs(a, b, k) << endl;
    return 0;
}
