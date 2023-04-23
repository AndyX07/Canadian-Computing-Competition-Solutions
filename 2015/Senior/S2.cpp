#include <bits/stdc++.h>

using namespace std;

int main()
{
    int j, a;
    cin >> j >> a;
    vector<char> v;
    int ctr = 0;
    for(int i=0; i < j; i++){
        char t;
        cin >> t;
        v.push_back(t);
    }
    for(int i = 0; i < a; i++){
        char c;
        int t;
        cin >> c >> t;
        t--;
        if(c>=v[t]){
            ctr++;
            v[t]='Z';
        }
    }
    cout << ctr << endl;
    return 0;
}
