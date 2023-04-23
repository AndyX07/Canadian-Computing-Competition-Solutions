#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, h, w1, h1, t;
    cin >> w >> h >> w1 >> h1 >> t;
    int r[w][h];
    for(int i = 0; i < w1; i++){
        for(int j = 0; j < h1; j++){
            r[i][j] = -1;
        }
    }
    for(int i = w - w1; i < w; i++){
        for(int j = 0; j < h1; j++){
            r[i][j] = -1;
        }
    }
    for(int i = 0; i < w1; i++){
        for(int j = h - h1; j < h; j++){
            r[i][j] = -1;
        }
    }
    for(int i = w - w1; i < w; i++){
        for(int j = h - h1; j < h; j++){
            r[i][j] = -1;
        }
    }
    int x = w1;
    int y = h1;
    bool d1 = true, d2 = false, d3 = false, d4 = false;

    return 0;
}
