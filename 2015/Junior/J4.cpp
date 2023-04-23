#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int timer = 0;
    map<int, int> mp;
    map<int, int> mp2;
    map<int, int> mp1;
    set<int> s;
    while(t--){
        //cout << timer << endl;
        char c;
        int a;
        cin >> c >> a;
        if(c == 'R'){
            mp2[a] = 0;
            mp[a] = timer;
            timer++;
            s.insert(a);
        }
        else if(c == 'S'){
            if(mp1.find(a)==mp1.end()){
                mp1.insert(pair<int, int>(a, timer-mp[a]));
            }
            else{
                mp1[a]+=(timer-mp[a]);
            }
            mp2[a] = 1;
            timer++;
        }
        else{
            timer+=(a-1);
        }
    }
    for(auto x : s){
        if(mp2.find(x) != mp2.end() && mp2[x] != 0){
            cout << x << " " << mp1[x] << endl;
        }
        else{
            cout << x << " -1" << endl;
        }
    }
    return 0;
}
