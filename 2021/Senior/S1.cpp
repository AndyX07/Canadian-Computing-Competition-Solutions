#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double prev, n1;
    cin >> prev;
    vector<pair<double, double>> v;
    for(int i = 1; i < n+1; i++){
        if(i == 1){
            cin >> n1;
            v.push_back({prev, n1});
            //cout << prev << " " << n1 << endl;
        }
        else{
            prev = n1;
            cin >> n1;
            v.push_back({prev, n1});
        }
    }
    double total = 0;
    for(int i = 0; i < n; i++){
        double w;
        cin >> w;
        //cout << v[i].first << " " << v[i].second << endl;
        total += ((v[i].first + v[i].second)/2)*w;
    }
    cout << fixed << total << endl;
    return 0;
}
