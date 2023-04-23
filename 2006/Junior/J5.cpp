#include <bits/stdc++.h>

using namespace std;

bool W[9][9];
bool B[9][9];
vector<vector<int>> v = {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};

bool isValid(int a, int b){
    if(a > 0 && b > 0 && a <= 8 && b <= 8){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    memset(W, 0, sizeof(W));
    memset(B, 0, sizeof(B));
    char c;
    cin >> c;
    int w, b;
    if(c == 'a'){
        W[4][4] = 1;
        W[5][5] = 1;
        B[4][5] = 1;
        B[5][4] = 1;
        w = 2;
        b = 2;
    }
    else if(c == 'b'){
        int t = 8;
        for(int i = 1; i <= 8; i++){
            B[i][i] = 1;
            W[t][i] = 1;
            t--;
        }
        w = 8;
        b = 8;
    }
    else{
        for(int i = 1; i <= 8; i++){
            W[5][i] = 1;
            W[6][i] = 1;
            B[3][i] = 1;
            B[4][i] = 1;
        }
        w = 16;
        b = 16;
    }
    int n;
    cin >> n;
    int counter = 0;
    int total = 0;
    for(int i = 0; i < n; i++){
        counter++;
        int x, y;
        cin >> y >> x;
        bool l = false;
        for(int j = 0; j < 8; j++){
            int a = v[j][0];
            int b1 = v[j][1];
            if(counter % 2){
                //black
                if(isValid(x+a, y+b1) && W[x+a][y+b1]){
                    l = true;
                }
            }
            else{
                //white
                if(isValid(x+a, y+b1) && B[x+a][y+b1]){
                    l = true;
                }
            }
        }
        if(l){
            for(int j = 0; j < 8; j++){
                int a = v[j][0];
                int b1 = v[j][1];
                if(counter % 2){
                    //black
                    if(isValid(x+a, y+b1) && W[x+a][y+b1]){
                        w--;
                        b++;
                        W[x+a][y+b1] = 0;
                        B[x+a][y+b1] = 1;
                    }
                }
                else{
                    //white
                    if(isValid(x+a, y+b1) && B[x+a][y+b1]){
                        b--;
                        w++;
                        B[x+a][y+b] = 0;
                        W[x+a][y+b] = 1;
                    }
                }
            }
            if(counter % 2){
                B[x][y] = 1;
                b++;
            }
            else{
                W[x][y] = 1;
                w++;
            }
            cout << x << " " << y << endl;
            cout << b << " " << w << endl;
            for(int i = 1; i <= 8; i++){
                for(int j = 1; j <= 8; j++){
                    cout << B[j][i] << " ";
                }
                cout << endl;
            }
            cout << endl;
            for(int i = 1; i <= 8; i++){
                for(int j = 1; j <= 8; j++){
                    cout << W[j][i] << " ";
                }
                cout << endl;
            }
            cout << endl;
            }
    }
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            cout << B[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            cout << W[j][i] << " ";
        }
        cout << endl;
    }
    cout << b << " " << w << endl;
    return 0;
}
