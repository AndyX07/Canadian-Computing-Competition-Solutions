#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> a[i][j];
        }
    }
    int t = a[0][0] + a[0][1]+a[0][2]+a[0][3];
    for(int i = 0; i < 4; i++){
        int t1 = 0;
        int t2 = 0;
        for(int j = 0; j < 4; j++){
            t1+=a[i][j];
            t2+=a[j][i];
        }
        if(t != t1){
            cout << "not magic" << endl;
            return 0;
        }
        if(t != t2){
            cout << "not magic" << endl;
            return 0;
        }
    }
    cout << "magic" << endl;
    return 0;
}
