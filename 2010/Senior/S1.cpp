#include <bits/stdc++.h>

using namespace std;

struct vector_sort{
    bool operator()(pair<int, string> p1, pair<int,string> p2){
        if(p1.first>p2.first) return true;
        else if(p1.first==p2.first){
            return p1.second<p2.second;
        }
        else return false;
    }
};

int main()
{
    vector<pair<int, string>> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        int a, b, c;
        cin >> s >> a >> b >> c;
        int t=2*a+3*b+c;
        v.push_back({t, s});
    }
    sort(v.begin(), v.end(), vector_sort());
    for(int i = 0; i < ((n<2)?n:2); i++){
        cout << v[i].second << endl;
    }
    return 0;
}
