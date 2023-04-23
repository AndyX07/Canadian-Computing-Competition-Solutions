#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int v[n];
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v, v+n);
    int m=(n+1)/2;
    vector<int> v1;
    for(int i=m-1; i>=0; i--){
        v1.push_back(v[i]);
    }
    for(int i=0; i<m; i++){
        int j=m+i;
        cout << v1[i] << " ";
        if(j<n) cout << v[j] << " ";
    }
    cout << endl;
    return 0;
}
