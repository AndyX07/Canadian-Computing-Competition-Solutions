#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<pair<int, int>>> v(n+1);
    for(int i = 0; i < k; i++){
        int x, y, r, b;
        cin >> x >> y >> r >> b;
        for(int j = max(1, x-r); j <= min(n, x+r); j++){
            int z = sqrt(r*r-(j-x)*(j-x))+y;
            //cout << z << endl;
            int dif = abs(y-z);
            int top = min(m, dif+y);
            int bottom = max(1, y-dif);
            v[j].push_back({bottom, b});
            v[j].push_back({top+1, -b});
            //cout << ">>" << bottom << " " << top << " " << b << " " << dif << " " << x << " " << y << " " << j << endl;
        }
    }
    for(int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }
    int best = 0;
    int total = 0;
    for(int i = 1; i <= n; i++){
        int cur = 0;
        for(int j = 0; j < v[i].size(); j++){
            int x = v[i][j].first;
            int w = v[i][j].second;
            //cout << i << " " << x << " " << w << endl;
            cur+=w;
            if(cur>best){
                best=cur;
                total=v[i][j+1].first-x;
                //cout << "!" << v[i][j+1].first-x<< endl;
            }
            else if(cur==best){
                total+=v[i][j+1].first-x;
            }
            //cout << ">>" << total << endl;
        }
    }
    cout << best << endl;
    cout << total << endl;
    return 0;
}
