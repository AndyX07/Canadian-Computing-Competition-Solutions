#include <bits/stdc++.h>

using namespace std;

int main()
{
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<char, pair<int, int>> mp;
    for(int i = 0; i < 26; i++){
        int t = i % 6;
        mp.insert(pair<char, pair<int, int>>(alphabet[i], pair<int , int>(t, i/6)));
    }
    mp.insert(pair<char, pair<int, int>>(' ', pair<int , int>(2, 4)));
    mp.insert(pair<char, pair<int, int>>('-', pair<int , int>(3, 4)));
    mp.insert(pair<char, pair<int, int>>('.', pair<int , int>(4, 4)));
    string s;
    getline(cin, s);
    int x = 0, y = 0;
    int total = 0;
    for(int i = 0; i < s.size(); i++){
        int t1 = mp[s[i]].first;
        int t2 = mp[s[i]].second;
        total += (abs(t1 - x) + abs(t2 - y));
        x = t1;
        y = t2;
    }
    total += abs(5 - x) + abs(4 - y);
    cout << total << endl;
    return 0;
}
