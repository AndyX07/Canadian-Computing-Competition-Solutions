#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;
    vector<int> v(k+1);
    for(int i = 1; i <= k; i++){
        v[i] = i;
    }
    int m;
    cin >> m;
    while(m--){
        int a;
        cin >> a;
        vector<int> v1;
        v1.push_back(0);
        for(int i = 1; i < v.size(); i++){
            if(i % a != 0){
                v1.push_back(v[i]);
            }
        }
        v = v1;
    }
    for(int i = 1; i < v.size(); i++){
        cout << v[i] << endl;
    }
    return 0;
}
