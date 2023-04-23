#include <bits/stdc++.h>

using namespace std;

bool prime(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i < t; i++){
        int n;
        cin >> n;
        n*=2;
        for(int i=3; i <=n; i++){
            if(prime(i)&&prime(n-i)){
                cout << i << " " << n-i << endl;
                break;
            }
        }
    }
    return 0;
}
