#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v(5);
    v[0] = 0;
    for(int i = 1; i < 5; i++){
        int a;
        cin >> a;
        v[i] = v[i-1]+a;
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << abs(v[i] - v[j]);
            if(j != 4){
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
