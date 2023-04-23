#include <bits/stdc++.h>

using namespace std;

int adj[10000];

int d(int x, int y){
    bool visited[10000];
    memset(visited, 0, sizeof(visited));
    int t = 0;
    while(!visited[x]){
        visited[x]=1;
        x=adj[x];
        if(x==y){
            return t;
        }
        t++;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        adj[x]=y;
    }
    int x, y;
    while(cin >> x >> y && x!=0&&y!=0){
        int t=d(x, y);
        if(t==-1){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << " " << t << endl;
        }
    }
    return 0;
}
