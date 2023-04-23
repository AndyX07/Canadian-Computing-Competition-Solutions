#include <bits/stdc++.h>

using namespace std;

bool pho[100001];
vector<int> adj[100001];
bool visited[100001];
int t=0;
int diam=0, node;

void dfs(int cur, int prev){
    for(auto x : adj[cur]){
        if(x!=prev){
            dfs(x, cur);
            if(pho[x]){
                pho[cur]=1;
            }
        }
    }
}

void dfsdiam(int cur, int d){
    if(d>diam){
        diam=d;
        node=cur;
    }
    visited[cur]=1;
    for(auto x : adj[cur]){
        //cout << x << " "<< visited[x] << " " << pho[x] << endl;
        if(!visited[x]&&pho[x]){
            //cout << x << endl;
            dfsdiam(x, d+1);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    memset(pho, 0, sizeof(pho));
    int c;
    for(int i=0; i<m; i++){
        cin >> c;
        pho[c]=1;
    }
    for(int i=0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(c, -1);
    for(int i=0; i<n; i++){
        if(pho[i]){
            t++;
        }
    }
    memset(visited, 0, sizeof(visited));
    dfsdiam(c, 0);
    //cout << "!" << endl;
    memset(visited, 0, sizeof(visited));
    dfsdiam(node, 0);
    cout << 2*(t-1)-diam << endl;
    return 0;
}
