#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char c[n];
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    int t = 0;
    for(int i = 0; i < n; i++){
        char ch;
        cin >> ch;
        if(ch == 'C' && c[i] == 'C'){
            t++;
        }
    }
    cout << t << endl;
    return 0;
}
