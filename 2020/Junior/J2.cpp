#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p, n, r;
    cin >> p >> n >> r;
    int t = 0;
    int total = n;
    while(total<=p){
        n*=r;
        total += n;
        t++;
    }
    cout << t << endl;
    return 0;
}
