#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    cin >> a;
    map<string, string> mp;
    vector<string> l(a);
    for(int i = 0; i < a; i++){
        string s;
        cin >> s;
        l[i] = s;
        mp.insert(make_pair(s, ""));
    }
    for(int i = 0; i < a; i++){
        string s;
        cin >> s;
        mp[l[i]] = s;
    }
    for(int i = 0; i < a; i++){
        /*
        cout << l[i] << " " << mp[l[i]] << endl;
        cout << mp[mp[l[i]]] << endl;
        */
        if(strcmp(l[i].c_str(), mp[mp[l[i]]].c_str()) != 0 || strcmp(mp[l[i]].c_str(), l[i].c_str()) == 0){
            cout << "bad" << endl;
            return 0;
        }
    }
    cout << "good" << endl;
    return 0;
}
