#include <bits/stdc++.h>

using namespace std;

vector<int> adj[8];
bool visited[8];
vector<int> t;

void dfs(int n){
    if(visited[n]){
        return;
    }
    visited[n] = true;
    for(auto x : adj[n]){
        dfs(x);
    }
    t.push_back(n);
}

bool cycle1(bool visited1[], bool visited2[], int n){
    visited1[n] = true;
    visited2[n] = true;
    for(auto x : adj[n]){
        if(!visited1[x]){
            if(cycle1(visited1, visited2, x)){
                return true;
            }
        }
        else if(visited2[x]){
            return true;
        }
    }
    visited2[n] = false;
    return false;
}

bool cycle(){
    bool visited1[8];
    bool visited2[8];
    memset(visited1, 0, sizeof(visited1));
    memset(visited2, 0, sizeof(visited2));
    for(int i = 1; i < 8; i++){
        if(!visited[i] && cycle1(visited1, visited2, i)){
            return true;
        }
    }
    return false;
}

int main()
{
    int a, b;
    memset(visited, 0, sizeof(visited));
    adj[1].push_back(7);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[3].push_back(4);
    adj[3].push_back(5);
    while(cin >> a && cin >> b && a != 0 && b != 0){
        adj[a].push_back(b);
    }
    if(cycle()){
        cout << "Cannot complete these tasks. Going to bed." << endl;
        return 0;
    }
    else{
        for(int i = 7; i >= 1; i--){
            if(!visited[i]){
                dfs(i);
            }
        }
        reverse(t.begin(), t.end());
        for(auto x : t){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
