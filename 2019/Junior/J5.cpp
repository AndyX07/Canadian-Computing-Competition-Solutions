#include <bits/stdc++.h>

using namespace std;

void bfs(int t, string s, string e, vector<pair<string, string>> rules){
    map<string, pair<pair<int, int>, string>> mp;
    mp[s] = {{0, 0}, "start"};
    map<string, bool> visited;
    priority_queue<pair<int, string>> q;
    map<string, int> d;
    d[s] = 0;
    q.push({0, s});
    vector<pair<pair<int, int>, string>> v;
    while(!q.empty()){
        string b = q.top().second;
        //cout << a << " " << b << endl;
        q.pop();
        if(visited.find(b) != visited.end()) continue;
        visited[b] = 1;
        if(d[b] == t){
            if(b == e){
                //cout << b << " " << e << endl;
                string cpy = b;
                while(mp[cpy].second != "start"){
                    int x = mp[cpy].first.first;
                    int y = mp[cpy].first.second;
                    v.push_back({{x, y}, cpy});
                    cpy = mp[cpy].second;
                }
                reverse(v.begin(), v.end());
                for(auto x : v){
                    cout << x.first.first << " " << x.first.second << " " << x.second << endl;
                }
                return;
            }
        }
        else{
            for(int i = 0; i < b.size(); i++){
                for(int j = 0; j < 3; j++){
                    if(rules[j].first.size()+i > b.size()){
                        continue;
                    }
                    else{
                        if(b.substr(i, rules[j].first.size()) == rules[j].first){
                            string temp = b;
                            temp.erase(i, rules[j].first.size());
                            temp.insert(i, rules[j].second);
                            if(d.find(temp) == d.end()){
                                mp[temp] = {{j+1, i+1}, b};
                                d[temp] = d[b]+1;
                                q.push({-d[temp], temp});
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    vector<pair<string, string>> rules;
    for(int i = 0; i < 3; i++){
        string s, s1;
        cin >> s >> s1;
        rules.push_back({s, s1});
    }
    int t;
    string st, e;
    cin >> t >> st >> e;
    bfs(t, st, e, rules);
    return 0;
}
