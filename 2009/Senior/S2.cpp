#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r, l;
    cin >> r >> l;
    int g[r];
    memset(g, 0, sizeof(g));
    vector<set<int>> v(r);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < l; j++){
            bool b;
            cin >> b;
            if(g[i]==0&&b)g[i]=1;
            else{
                g[i]<<=1;
                g[i]|=b;
            }
        }
        v[i].insert(g[i]);
        //cout << g[i] << endl;
    }
    for(int i = 1; i < r; i++){
        for(auto x : v[i-1]){
            v[i].insert(x^g[i]);
        }
    }
    cout << v[r-1].size() << endl;
    return 0;
}
