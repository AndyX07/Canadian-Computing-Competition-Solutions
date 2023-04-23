#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    t = t*5 - 400;
    cout << t << endl;
    if(t==100){
        cout << "0" << endl;
    }
    else{
        cout << ((t>100)? "-1":"1") << endl;
    }
    return 0;
}
