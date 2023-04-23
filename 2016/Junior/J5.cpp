#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    cin >> a;
    int n;
    cin >> n;
    vector<int> d(n);
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    if(a == 1){
        sort(d.begin(), d.end());
        sort(p.begin(), p.end());
        int t = 0;
        for(int i = 0; i < n; i++){
            t += max(d[i], p[i]);
        }
        cout << t << endl;
    }
    else{
        int t = 0, t1 = 0;
        sort(d.begin(), d.end());
        sort(p.begin(), p.end(), greater<int>());
        for(int i = 0; i < n; i++){
            t+=max(d[i], p[i]);
        }
        sort(d.begin(), d.end(), greater<int>());
        sort(p.begin(), p.end());
        for(int i = 0; i < n; i++){
            t1+=max(d[i], p[i]);
        }
        cout << max(t, t1) << endl;
    }
    return 0;
}
