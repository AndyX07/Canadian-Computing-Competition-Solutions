#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n+1, 0);
    v[0]=1;
    for(int i= 4; i <=n; i++){
        v[i]+=v[i-4];
    }
    for(int i = 5; i<=n; i++){
        v[i]+=v[i-5];
    }
    cout << v[n] << endl;
    return 0;
}
