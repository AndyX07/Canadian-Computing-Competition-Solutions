#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s, m, l;
    cin >> s >> m >> l;
    int t = s*1 + m*2 + l*3;
    cout << ((t >= 10)? "happy" : "sad") << endl;
    return 0;
}
