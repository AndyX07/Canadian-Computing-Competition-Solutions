#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[i]={a*b*c, a, b, c};
        sort(v[i].begin()+1, v[i].end());
    }
    sort(v.begin(), v.end());
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        vector<int> t(3);
        for(auto &x:t){
            cin >> x;
        }
        sort(t.begin(), t.end());
        bool b=0;
        for(auto x : v){
            if(x[1]>=t[0]&&x[2]>=t[1]&&x[3]>=t[2]){
                cout << x[0] << endl;
                b=1;
                break;
            }
        }
        if(!b) cout << "Item does not fit." << endl;
    }
    return 0;
}
