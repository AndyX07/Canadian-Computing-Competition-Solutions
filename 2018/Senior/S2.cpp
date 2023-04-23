#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m=INT_MAX;
    cin >> n;
    int g[n][n];
    int x, y;
    for(int i = 0; i < n; i++){
        for(int j=0; j<n; j++){
            int a;
            cin >> a;
            if(a<m){
                m=a;
                x=i;
                y=j;
            }
            g[i][j]=a;
        }
    }
    if(x==0 &&y==0){
        for(int i= 0; i<n; i++){
            for(int j=0; j < n; j++){
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if(x==0&&y==n-1){
        for(int j=n-1; j>=0; j--){
            for(int i=0; i<n; i++){
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if(x==n-1&&y==n-1){
        for(int i=n-1; i >= 0; i--){
            for(int j=n-1; j>=0; j--){
                cout << g[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        for(int j=0; j < n; j++){
            for(int i=n-1; i>=0; i--){
                cout<< g[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
