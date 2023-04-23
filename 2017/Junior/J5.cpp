#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> s;
    map<int, int> mp;
    map<int, int> mp1;
    map<int, int> p;
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        s.insert(l);
        if(mp.find(l) == mp.end()){
            mp[l] = 1;
        }
        else{
            mp[l]++;
        }
    }
    vector<int> v;
    for(auto x : s){
        //cout << x << endl;
        v.push_back(x);
    }
    int m = INT_MIN;
    set<int> s1;
    for(int i = 0; i < v.size(); i++){
        for(int j = i; j < v.size(); j++){
            if(i == j){
                if(mp1.find(v[i]+v[j]) == mp1.end()){
                    mp1[v[i]+v[j]] = mp[v[i]]/2;
                }
                else{
                    mp1[v[i]+v[j]] += mp[v[i]]/2;
                }
            }
            else{
                if(mp1.find(v[i]+v[j]) == mp1.end()){
                    mp1[v[i]+v[j]] = min(mp[v[i]], mp[v[j]]);
                }
                else{
                    mp1[v[i]+v[j]] += min(mp[v[i]], mp[v[j]]);
                }
            }
            if(m < mp1[v[i]+v[j]]){
                m = mp1[v[i]+v[j]];
                //cout << i << " " << j << endl;
            }
            s1.insert(v[i]+v[j]);
        }
    }
    int counter = 0;
    for(auto x : s1){
        if(mp1[x] == m){
            counter++;
        }
    }
    cout << m << " " << counter << endl;
    return 0;
}
