#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int c[n][n];
    int m = INT_MAX;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;
            m = min(m, a);
            c[j][i] = a;
        }
    }
    if(c[0][0] == m){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << c[j][i] << " ";
            }
            cout << endl;
        }
    }
    else if(c[n-1][0] == m){
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if(c[n-1][n-1] == m){
        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                cout << c[j][i] << " ";
            }
            cout << endl;
        }
    }
    else{
        for(int i = 0; i < n; i++){
            for(int j = n-1; j >= 0; j--){
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
