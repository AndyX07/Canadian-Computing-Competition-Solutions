#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, pair<int, int>> mp;
vector<vector<int>> edges;
vector<int> link(101);
vector<int> sizes(101);

struct vector_sort{
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        return mp[{p1.first, p1.second}].first < mp[{p2.first, p2.second}].first;
    }
};

int findx(int x){
    while(x != link[x]){
        x = link[x];
    }
    return x;
}

int kruskal(int n){
    int total = 0;
    for(int i = 0; i < n; i++){
        int w = edges[i][0];
        int a = edges[i][1];
        int b = edges[i][2];
        //cout << w << " " << a << " " << b << endl;
        if(findx(a) != findx(b)){
            //cout << w << " " << a << " " << b << endl;
            a  = findx(a);
            b = findx(b);
            if(sizes[a] < sizes[b]) swap(a, b);
            sizes[a]+=sizes[b];
            link[b] = a;
            total+=w;
        }
    }
    //cout << total << endl;
    return total;
}

int main()
{
    //outside is m
    int m;
    cin >> m;
    set<pair<int, int>> all;
    for(int i = 0; i < m; i++){
        int e;
        cin >> e;
        int start, prev, cur;
        vector<vector<int>> l;
        vector<pair<int, int>> p;
        for(int j = 0; j < e; j++){
            if(j == 0){
                cin >> start;
                prev = start;
                cur = start;
            }
            else if(j == e-1){
                prev = cur;
                cin >> cur;
                //cout << prev << " " << cur << endl;
                //cout << start << " " << cur << endl;
                p.push_back({min(prev, cur), max(prev, cur)});
                all.insert({min(prev, cur), max(prev, cur)});
                p.push_back({min(start, cur), max(start, cur)});
                all.insert({min(start, cur), max(start, cur)});
            }
            else{
                prev = cur;
                cin >> cur;
                //cout << prev << " " << cur << endl;
                p.push_back({min(prev, cur), max(prev, cur)});
                all.insert({min(prev, cur), max(prev, cur)});
            }
        }
        for(int j = 0; j < e; j++){
            int w;
            cin >> w;
            if(mp.find(p[j]) == mp.end()){
                mp[p[j]] = {w, i};
            }
            else{
                edges.push_back({w, mp[p[j]].second, i});
                all.erase(all.find(p[j]));
            }
        }
    }
    for(int i = 0; i < 101; i++){
        link[i] = i;
        sizes[i] = 1;
    }
    sort(edges.begin(), edges.end());
    int m1 = kruskal(edges.size());
    //cout << m1 << endl;
    /*
    for(auto x : edges){
        cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }
    */
    //cout << "//////" << endl;
    for(int i = 0; i < 101; i++){
        link[i] = i;
        sizes[i] = 1;
    }
    vector<pair<int, int>> v;
    bool visited[101];
    memset(visited, 0, sizeof(visited));
    for(auto x : all){
        v.push_back(x);
    }
    int counter = 0;
    sort(v.begin(), v.end(), vector_sort());
    for(auto x : v){
        //cout << x.first << " " << x.second << " " << mp[{x.first, x.second}].first << endl;
        int t1 = x.first;
        int t2 = x.second;
        if(visited[mp[{t1, t2}].second]) continue;
        visited[mp[{t1, t2}].second] = 1;
        counter++;
        edges.push_back({mp[{t1, t2}].first, mp[{t1, t2}].second, m});
    }
    sort(edges.begin(), edges.end());
    //cout << kruskal(m) << endl;
    m1 = min(m1, kruskal(edges.size()));
    cout << m1 << endl;
    return 0;
}
