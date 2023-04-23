#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h, m;
    cin >> h >> m;
    for(int i = 1; i <= m; i++){
        int t = (-6*pow(i, 4)) + (h*pow(i, 3)) + (2*pow(i, 2)) + i;
        if(t <= 0){
            cout << "The balloon first touches ground at hour:" << endl;
            cout << i << endl;
            return 0;
        }
    }
    cout << "The balloon does not touch ground in the given time." << endl;
    return 0;
}
