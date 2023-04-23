#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double m = -1;
    vector<pair<double, double>> v(n);
    for(int i = 0; i < n; i++){
        double t, x;
        cin >> t>> x;
        v[i]={t, x};
    }
    sort(v.begin(), v.end());
    for(int i = 1; i <n; i++){
        m=max(m, abs(v[i].second-v[i-1].second)/abs(v[i].first-v[i-1].first));
    }
    cout << m << endl;
    return 0;
}
