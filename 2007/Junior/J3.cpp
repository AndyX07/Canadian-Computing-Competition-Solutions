#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    int v[11] = {0, 100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};
    cin >> a;
    int n = 10;
    for(int i = 0; i < a; i++){
        int b;
        cin >> b;
        v[b] = 0;
        n--;
    }
    double t = 0;
    for(auto x : v){
        t += x;
    }
    t/=n;
    int s;
    cin >> s;
    cout << ((s > t)? "deal" : "no deal") << endl;
    return 0;
}
