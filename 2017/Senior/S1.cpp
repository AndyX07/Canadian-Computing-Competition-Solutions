#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for(int i=0; i < n; i++){
        int t;
        cin >> t;
        if(i==0){
            a[i]=t;
        }
        else{
            a[i]=a[i-1]+t;
        }
    }
    for(int i=0; i < n; i++){
        int t;
        cin >> t;
        if(i==0){
            b[i]=t;
        }
        else{
            b[i]=b[i-1]+t;
        }
    }
    for(int i = n-1; i>=0; i--){
        if(a[i]==b[i]){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
