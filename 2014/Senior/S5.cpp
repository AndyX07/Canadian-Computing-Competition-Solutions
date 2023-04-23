#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> p;
    p.push_back({0, 0});
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        p.push_back({a, b});
    }
    vector<vector<int>> d(((n+1)*n)/2);
    int t = 0;
    for(int i = 0; i < n+1; i++){
        for(int j = i+1; j < n+1; j++){
            int x1=p[i].first, y1=p[i].second, x2=p[j].first, y2=p[j].second;
            d[t]={abs(x1-x2)*abs(x1-x2)+abs(y1-y2)*abs(y1-y2), i, j};
            t++;
        }
    }
    sort(d.begin(), d.end());
    vector<int> best(n+1, 0);
    vector<int> mem(n+1, 0);
    vector<int> dis(n+1, 0);
    for(auto a : d){
        int x = 0, y = 0;
        int i = a[1], j=a[2];
        if(a[0]>dis[i]){
            dis[i]=a[0];
            mem[i]=best[i];
        }
        if(a[0]>dis[j]){
            dis[j]=a[0];
            mem[j]=best[j];
        }
        if(i==0){
            best[i]=max(best[i], mem[j]);
        }
        else{
            best[i]=max(best[i], mem[j]+1);
            best[j]=max(mem[i]+1, best[j]);
        }
    }
    cout << best[0]+1 << endl;
    return 0;
}
