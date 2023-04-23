#include <bits/stdc++.h>

using namespace std;

struct vector_sort{
    bool operator()(const pair<int, string> a, const pair<int, string> b){
        return a.first > b.first;
    }
};

int main()
{
    int n;
    vector<pair<int, string>> v;
    cin >> n;
    string s;
    int a;
    while(n--){
        cin >> s >> a;
        v.push_back({a, s});
    }
    sort(v.begin(), v.end(), vector_sort());
    cout << v[0].second << endl;
    return 0;
}
