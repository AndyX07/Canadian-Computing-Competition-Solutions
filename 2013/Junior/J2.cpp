#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for(char c : s){
        if(c == 'I' || c == 'O' || c == 'S' || c=='H'||c=='Z'||c=='X'||c=='N') continue;
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}
