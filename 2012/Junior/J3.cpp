#include <bits/stdc++.h>

using namespace std;

int main()
{
    char g[3][3] = {{'*', 'x', '*'}, {' ', 'x', 'x'}, {'*', ' ', '*'}};
    int t;
    cin >> t;
    for(int i = 0; i < 3; i++){
        for(int k = 0; k < t; k++){
            for(int j = 0; j < 3; j++){
                for(int l = 0; l < t; l++){
                    cout << g[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}
