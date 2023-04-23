#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, n, t=0;
    cin >> w >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0; i<min(4,n); i++){
        t+=v[i];
        if(t>w){
            cout << i << endl;
            return 0;
        }
    }
    for(int i=4;i<n;i++){
        t+=v[i];
        t-=v[i-4];
        if(t>w){
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}
