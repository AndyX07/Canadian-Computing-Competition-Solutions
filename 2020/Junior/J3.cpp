#include <bits/stdc++.h>

using namespace std;

int main()
{
    int minx = 99999999, miny = 999999999, maxx = -1, maxy = -1;
    int t;
    cin >> t;
    while(t--){
        int x, y;
        char c;
        cin >> x >> c >> y;
        minx = min(x, minx);
        miny = min(y, miny);
        maxx = max(x, maxx);
        maxy = max(y, maxy);
    }
    minx--;
    miny--;
    maxx++;
    maxy++;
    cout << minx << "," << miny << endl;
    cout << maxx << "," << maxy << endl;
    return 0;
}
