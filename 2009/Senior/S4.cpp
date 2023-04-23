#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> adj;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int best[5001];

int dis(int d){
    while(!pq.empty()){
        int w = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if(x==d) return w;
        for(auto a : adj[x]){
            if(best[a.first]==-1||w+a.second<best[a.first]){
                best[a.first]=w+a.second;
                pq.push({w+a.second, a.first});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n >> t;
    adj.resize(n+1);
    memset(best, -1, sizeof(best));
    for(int i = 0; i < t; i++){
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x,w});
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int z, p;
        cin >> z >> p;
        pq.push({p, z});
        best[z]=p;
    }
    int d;
    cin >> d;
    cout << dis(d) << endl;
    return 0;
}
