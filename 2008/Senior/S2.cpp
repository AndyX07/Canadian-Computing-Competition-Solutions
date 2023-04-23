#include <bits/stdc++.h>

using namespace std;

int calc(int r){
    int t = 0;
    for(int i = 1; i <= r; i++){
        int n = sqrt(r*r-i*i);
        t+=n*2+1;
    }
    t*=2;
    t+=r*2+1;
    return t;
}

int main()
{
    int r;
    while(cin >> r && r!=0){
        cout << calc(r) << endl;
    }
    return 0;
}
