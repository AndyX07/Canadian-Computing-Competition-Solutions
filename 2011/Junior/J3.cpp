#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t1, t2;
    cin >> t1 >> t2;
    int counter = 2;
    while(t2 <= t1){
        int t = t1 - t2;
        t1 = t2;
        t2 = t;
        counter++;
    }
    cout << counter << endl;
    return 0;
}
