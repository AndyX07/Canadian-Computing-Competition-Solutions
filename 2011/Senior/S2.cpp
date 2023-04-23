#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<char> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int t = 0;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        if(c == v[i]){
            t++;
        }
    }
    cout << t << endl;
    return 0;
}
