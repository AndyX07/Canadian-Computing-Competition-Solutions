#include <bits/stdc++.h>

using namespace std;

long long n;

vector<vector<long long>> v(200000);

long long t(long long pos){
    long long total = 0;
    for(int i = 0; i < n; i++){
        long long temp = abs(v[i][0] - pos);
        temp-=v[i][2];
        if(temp > 0){
            total += temp*v[i][1];
        }
    }
    //cout << pos << " " << total << endl;
    return total;
}

long long s(long long l, long long h){
    while(l <= h){
        long long m = (h+l)/2;
        long long ms = t(m);
        long long le = t(m-1), r = t(m+1);
        if(ms < le && ms < r){
            return ms;
        }
        if(ms == le || ms == r){
            return ms;
        }
        if(ms < r){
            h = m-1;
        }
        if(ms < le){
            l = m+1;
        }
    }
}

int main()
{
    cin >> n;
    long long m = LONG_MIN;
    long long m1 = LONG_MAX;
    for(int i = 0; i < n; i++){
        long long p, w, d;
        cin >> p >> w >> d;
        m = max(m, p);
        m1 = min(m1, p);
        v[i] = {p, w , d};
    }
    //cout << m << " " << m1 << endl;
    cout << s(m1, m) << endl;
    return 0;
}
