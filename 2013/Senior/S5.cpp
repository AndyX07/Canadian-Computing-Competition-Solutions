#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int cost=0;
    while(n!=1){
        bool prime = 1;
        for(int i = 2; i <= sqrt(n); i++){
            if(n%i==0){
                n-=(n/i);
                cost+=i-1;
                prime=0;
                break;
            }
        }
        if(prime){
            cost+=n-1;
            n--;
        }
    }
    cout << cost << endl;
    return 0;
}
