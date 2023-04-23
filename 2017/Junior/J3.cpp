#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y, x1, y1, n;
    cin >> x >> y >> x1 >> y1 >> n;
    int total = abs(x - x1) + abs(y - y1);
    if(n < total){
        cout << "N" << endl;
    }
    else if((total - n)%2 ==0){
        cout << "Y" << endl;
    }
    else{
        cout << "N" << endl;
    }
    return 0;
}
