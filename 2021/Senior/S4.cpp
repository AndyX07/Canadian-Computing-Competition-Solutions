#include <bits/stdc++.h>

using namespace std;

vector<int> adj[200001];
vector<int> dis;
vector<int> station;

int n, w, d;

void bfs(){
    queue<int> q;
    q.push(n);
    dis[n]=0;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(auto x: adj[t]){
            if(dis[t]+1<dis[x]||dis[x]==-1){
                dis[x]=dis[t]+1;
                q.push(x);
            }
        }
    }
}

int main(){
    cin >> n >> w >> d;
    dis=vector<int>(n+1, -1);
    station=vector<int>(n+1);
    for(int i = 0; i < w; i++){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    for(int i = 1; i<=n; i++){
        int a;
        cin >> a;
        station[i]=a;
    }
    multiset<int> m;
    bfs();
    for(int i = 1; i <= n; i++){
        if(dis[station[i]]!=-1){
            m.insert(i+dis[station[i]]-1);
        }
    }
    /*
    for(auto x : m){
        cout << x << " ";
    }
    cout << endl;
    */
    for(int i = 0; i < d; i++){
        int a, b;
        cin >> a >> b;
        if(dis[station[a]]!=-1){
            m.erase(m.find(a+dis[station[a]]-1));
            m.insert(b+dis[station[a]]-1);
            //cout << ">" << a+dis[station[a]]-1 << " " << b+dis[station[a]]-1 << endl;
        }
        if(dis[station[b]]!=-1){
            m.erase(m.find(b+dis[station[b]]-1));
            m.insert(a+dis[station[b]]-1);
            //cout << ">" << b+dis[station[b]]-1 << " " << a+dis[station[b]]-1 << endl;
        }
        /*
        cout << ">" << *(m.begin()) << " "<< b+dis[station[a]]-1 << " " << a+dis[station[b]]-1 << endl;
        cout << ">";
        */
        swap(station[a], station[b]);
        int t =*(m.begin());
        cout << t << endl;
    }
    /*
    for(int i = 1; i<=n; i++){
        cout << dis[i] << " ";
    }
    cout << endl;
    */
    //cout << dis[3] << endl;
    return 0;
}
