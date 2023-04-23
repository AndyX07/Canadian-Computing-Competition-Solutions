#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long gr = 0;
    long long gc = 0;
    int m, n;
    cin >> m >> n;
    bool R[m+1];
    bool C[n+1];
    memset(R, 0, sizeof(R));
    memset(C, 0, sizeof(C));
    int t;
    cin >> t;
    while(t--){
        char c;
        int a;
        cin >> c >> a;
        //cout << gr << " " << gc << endl;
        if(c == 'R'){
            if(R[a]){
                gr--;
                R[a] = false;
            }
            else{
                gr++;
                R[a] = true;
            }
        }
        else{
            if(C[a]){
                gc--;
                C[a] = false;
            }
            else{
                gc++;
                C[a] = true;
            }
        }
    }
    //cout << gr << " " << gc << endl;
    cout << gr*n + gc*m - gc*gr*2 << endl;
    return 0;
}
