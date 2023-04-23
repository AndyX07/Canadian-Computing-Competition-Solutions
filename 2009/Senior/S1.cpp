#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> s;
    map<int,int> cube;
    s.insert(1);
    for(int i = 2; i <= 1001; i++){
        cube[pow(i, 3)]=1;
    }
    for(int i = 2; i <= 10001; i++){
        int sq = pow(i, 2);
        if(cube.find(sq)!=cube.end()){
            s.insert(sq);
        }
    }
    vector<int> v;
    for(auto x : s){
        v.push_back(x);
        //cout << x << endl;
    }
    int a, b;
    cin >> a >> b;
    int it1 = lower_bound(v.begin(), v.end(), a)-v.begin();
    int it2 = upper_bound(v.begin(), v.end(), b)-v.begin();
    //cout << it1 << " " << v[it1] << " " << it2 << " " << v[it2] << endl;
    int t=it2-it1;
    if(v[it2]==b){
        t++;
    }
    cout << it2-it1 << endl;
    return 0;
}
