#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a = 0, b = 0;
    int x, y, z;
    cin >> x >> y >> z;
    a += x*3 + y*2 + z;
    cin >> x >> y >> z;
    b += x*3 + y*2 + z;
    if(a == b){
        cout << "T" << endl;
    }
    else{
        cout << ((a > b)?"A" : "B") << endl;
    }
    return 0;
}
