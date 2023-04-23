#include <bits/stdc++.h>

using namespace std;

bool g[1000][1000];

int main()
{
    memset(g, 0, sizeof(g));
    int x = 201;
    int y = 5;
    g[0][1] = true;
    g[0][2] = true;
    g[0][3] = true;
    g[1][3] = true;
    g[2][3] = true;
    g[3][3] = true;
    g[3][4] = true;
    g[3][5] = true;
    g[4][5] = true;
    g[5][5] = true;
    g[5][4] = true;
    g[5][3] = true;
    g[6][3] = true;
    g[7][3] = true;
    g[7][4] = true;
    g[7][5] = true;
    g[7][6] = true;
    g[7][7] = true;
    g[6][7] = true;
    g[5][7] = true;
    g[4][7] = true;
    g[3][7] = true;
    g[2][7] = true;
    g[1][7] = true;
    g[0][7] = true;
    g[201][7] = true;
    g[201][6] = true;
    g[201][5] = true;
    int t;
    char c;
    bool b = true, b1 = false;
    while(cin >> c && cin >> t && c != 'q'){
        if(c == 'l'){
            for(int i = 0; i < t; i++){
                if(b){
                    x++;
                }
                else{
                    x--;
                    if(x < 0){
                        x = x*-1 + 200;
                        b = true;
                    }
                }
                if(g[x][y]){
                    b1 = true;
                }
                g[x][y] = true;
            }
        }
        else if(c == 'r'){
            for(int i = 0; i < t; i++){
                if(!b){
                    x++;
                }
                else{
                    x--;
                    if(x < 201){
                        x = 0;
                        b = false;
                    }
                }
                if(g[x][y]){
                    b1 = true;
                }
                g[x][y] = true;
            }
        }
        else if(c == 'u'){
            for(int i = 0; i < t; i++){
                y--;
                if(g[x][y]){
                    b1 = true;
                }
                g[x][y] = true;
            }
        }
        else{
            for(int i = 0; i < t; i++){
                y++;
                if(g[x][y]){
                    b1 = true;
                }
                g[x][y] = true;
            }
        }
        if(b1){
            if(b){
                cout << (x-200)*-1 << " " << y*-1 << " DANGER" << endl;
                return 0;
            }
            else{
                cout << x << " " << y*-1 << " DANGER" << endl;
                return 0;
            }
        }
        if(b){
            cout << (x-200)*-1 << " " << y*-1 << " safe" << endl;
        }
        else{
            cout << x << " " << y*-1 << " safe" << endl;
        }
    }
    return 0;
}
