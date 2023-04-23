#include <bits/stdc++.h>

using namespace std;

int main()
{
    double m=INT_MAX;
    int n;
    cin >> n;
    vector<double> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        int j=i+2;
        if(j<n){
            m=min(m, (v[j]+v[j-1])/2-(v[j-1]+v[i])/2);
        }
    }
    cout << fixed << setprecision(1) << m << endl;
    return 0;
}
