#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r,c;
    cin >> r >> c;
    int g[r][c];
    memset(g, -1, sizeof(g));
    int k;
    cin >> k;
    for(int i=0;i<k; i++){
        int x, y;
        cin >> x >> y;
        g[x-1][y-1]=0;
    }
    for(int i = 0; i < c; i++){
        if(g[0][i]==0)break;
        g[0][i]=1;
    }
    for(int i = 0; i<r; i++){
        if(g[i][0]==0)break;
        g[i][0]=1;
    }
    for(int i=1;i<r;i++){
        for(int j=1; j<c; j++){
            if(g[i][j]==-1){
                g[i][j]=((g[i-1][j]==-1)?0:g[i-1][j])+((g[i][j-1]==-1)?0:g[i][j-1]);
            }
        }
    }
    cout<<g[r-1][c-1] << endl;
    return 0;
}
