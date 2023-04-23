#include <bits/stdc++.h>

using namespace std;

int main()
{
    int g[2][2] = {{1, 2}, {3, 4}};
    string s;
    getline(cin, s);
    int h = 0, v = 0;
    for(char c: s){
        if(c == 'H'){
            h++;
        }
        else{
            v++;
        }
    }
    h%=2;
    v%=2;
    for(int i = 0; i < h; i++){
        swap(g[0][0], g[1][0]);
        swap(g[0][1], g[1][1]);
    }
    for(int i = 0; i < v; i++){
        swap(g[0][0], g[0][1]);
        swap(g[1][0], g[1][1]);
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
