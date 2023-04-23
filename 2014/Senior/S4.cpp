#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, t;
    cin >> n >> t;
    vector<vector<long long>> v;
    set<long long> y;
    for(long long i = 0; i < n; i++){
        long long x1, x2, y1, y2, t1;
        cin>>x1>>y1>>x2>>y2>>t1;
        v.push_back({x1, y1, x2, y2, t1});
        v.push_back({x2, y2, x1, y1, t1*(-1)});
        y.insert(y1);
        y.insert(y2);
    }
    sort(v.begin(), v.end());
    vector<long long> ly(y.size());
    map<long long, long long> pos;
    for(long long i = 0; i <  y.size(); i++){
        auto it=y.begin();
        advance(it, i);
        long long temp = *it;
        ly[i]=temp;
        pos[temp]=i;
    }
    long long ans=0;
    vector<long long> tint(y.size(), 0);
    //cout << "!" << endl;
    for(long long i = 0; i < v.size(); i++){
        long long x1=v[i][0], y1=v[i][1], x2=v[i][2], y2=v[i][3], t1=v[i][4];
        //cout << x1 << " " << y1 << " " << x1 << " " << y2 << " " << t1 << endl;
        for(long long j = 0; j < y.size(); j++){
            if(tint[j]>=t){
                ans+=(x1-v[i-1][0])*(ly[j+1]-ly[j]);
                //cout << (x1-v[i-1][0]) << " " << (ly[j+1]-ly[j]) << endl;
            }
        }
        if(y1>y2)swap(y1, y2);
        for(long long j=pos[y1]; j < pos[y2]; j++){
            tint[j]+=t1;
        }
        /*
        for(long long j= 0; j < y.size(); j++){
            cout << tlong long[j] << " ";
        }
        cout << endl;
        */
    }
    cout << ans << endl;
    return 0;
}
