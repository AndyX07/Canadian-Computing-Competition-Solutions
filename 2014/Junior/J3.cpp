#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a = 100, b = 100;
    int t;
    cin >> t;
    while(t--){
        int t1, t2;
        cin >> t1 >> t2;
        if(t1 > t2) b-=t1;
        else if(t2 > t1) a-=t2;
    }
    cout << a << endl;
    cout << b << endl;
    return 0;
}
