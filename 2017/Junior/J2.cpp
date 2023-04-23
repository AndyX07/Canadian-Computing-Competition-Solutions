#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int t = n;
    for(int i = 0; i < k; i++){
        n*=10;
        t+=n;
    }
    cout << t << endl;
    return 0;
}
