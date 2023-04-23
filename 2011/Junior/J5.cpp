#include <bits/stdc++.h>

using namespace std;

vector<int> v[7];
int n;

vector<int> bfs(vector<int> v1){
    bool visited[7];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    for(auto x : v1){
        q.push(x);
    }
    vector<int> v2;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(visited[t]) continue;
        if(t != n){
            v2.push_back(t);
        }
        visited[t] = true;
        for(auto x : v[t]){
            q.push(x);
        }
    }
    sort(v2.begin(), v2.end());
    return v2;
}

int main()
{
    cin >> n;
    set<vector<int>> s;
    vector<int> v2;
    for(int i = 1; i < n; i++){
        int t;
        cin >> t;
        v[t].push_back(i);
    }
    for(int i = 1; i < n; i++){
        v2.push_back(i);
    }
    vector<vector<int>> v1;
    for(int i = 0; i < pow(2, v2.size()); i++){
        vector<int> temp;
        for(int j = 0; j < v2.size(); j++){
            if((i&(1 << j)) != 0){
                temp.push_back(v2[j]);
            }
        }
        sort(temp.begin(), temp.end());
        v1.push_back(temp);
    }
    for(auto x : v1){
        s.insert(bfs(x));
    }
    /*
    for(auto x : s){
        for(auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
    */
    cout << s.size() << endl;
    return 0;
}
