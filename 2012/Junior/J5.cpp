#include <bits/stdc++.h>

using namespace std;

bool isEqual(vector<vector<int>> v, vector<vector<int>> v1){
    for(int i = 0; i < v.size(); i++){
        if(v[i] != v1[i]){
            return false;
        }
    }
    return true;
}

int possible(vector<vector<int>> v, vector<vector<int>> solution, int n){
    map<vector<vector<int>>, int> d;
    map<vector<vector<int>>, bool> mp;
    priority_queue<pair<int, vector<vector<int>>>> q;
    d[v] = 0;
    q.push(pair<int, vector<vector<int>>>(d[v], v));
    while(!q.empty()){
        vector<vector<int>> t = q.top().second;
        q.pop();
        if(mp.find(t) != mp.end()) continue;
        /*
        for(auto x : t){
            for(auto y : x){
                cout << y << " ";
            }
            cout << "/";
        }
        cout << endl;
        cout << d[t] << endl;
        */
        if(isEqual(t, solution)){
            return d[t];
        }
        mp[t] = 1;
        for(int i = 0; i < n; i++){
            int x = i-1;
            int y = i+1;
            if(t[i].size() == 0){
                continue;
            }
            vector<vector<int>> cpy = t;
            int temp = cpy[i][0];
            cpy[i].erase(cpy[i].begin());
            if(x >= 0){
                if(cpy[x].size() == 0){
                    cpy[x].push_back(temp);
                }
                else if(cpy[x][0] > temp){
                    cpy[x].insert(cpy[x].begin(), temp);
                }
                if(d.find(cpy) == d.end()){
                    d[cpy] = d[t]+1;
                    q.push({-d[cpy], cpy});
                }
            }
            cpy = t;
            temp = cpy[i][0];
            cpy[i].erase(cpy[i].begin());
            if(y < n){
                if(cpy[y].size() == 0){
                    cpy[y].push_back(temp);
                }
                else if(cpy[y][0] > temp){
                    cpy[y].insert(cpy[y].begin(), temp);
                }
                if(d.find(cpy) == d.end()){
                    d[cpy] = d[t]+1;
                    q.push({-d[cpy], cpy});
                }
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    while(cin >> n && n != 0){
        vector<vector<int>> v(n);
        vector<vector<int>> solution(n);
        for(int i = 1; i <= n; i++){
            solution[i-1].push_back(i);
        }
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            v[i].push_back(a);
        }
        /*
        cout << "solution: ";
        for(auto x : solution){
            for(auto y : x){
                cout << y << " ";
            }
            cout << "/";
        }
        cout << endl;
        */
        int t = possible(v, solution, n);
        if(t != -1){
            cout << t << endl;
        }
        else{
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
