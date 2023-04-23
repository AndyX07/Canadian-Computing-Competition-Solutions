#include <bits/stdc++.h>

using namespace std;

int dp[31][31][31][31];

bool g(int a, int b, int c, int d, bool turn){
    if(dp[a][b][c][d]!=-1){
        if(turn){
            return dp[a][b][c][d];
        }
        else{
            return !dp[a][b][c][d];
        }
    }
    bool m=0;
    bool win=1;
    //cout << a << " " << b << " " << c << " " << d << " " << turn << endl;
    if(turn==1){
        if(a>=2&&b>=1&&d>=2){
            if(g(a-2, b-1, c, d-2, !turn)){
                dp[a][b][c][d]=1;
                return 1;
            }
            m=1;
        }
        if(a>=1&&b>=1&&c>=1&&d>=1){
            if(g(a-1, b-1, c-1, d-1, !turn)){
                dp[a][b][c][d]=1;
                return 1;
            }
            m=1;
        }
        if(c>=2&&d>=1){
            if(g(a, b, c-2, d-1, !turn)){
                dp[a][b][c][d]=1;
                return 1;
            }
            m=1;
        }
        if(b>=3){
            if(g(a, b-3, c, d, !turn)){
                dp[a][b][c][d]=1;
                return 1;
            }
            m=1;
        }
        if(a>=1&&d>=1){
            if(g(a-1, b, c, d-1, !turn)){
                dp[a][b][c][d]=1;
                return 1;
            }
            m=1;
        }
        dp[a][b][c][d]=0;
        return dp[a][b][c][d];
    }
    else{
        if(a>=2&&b>=1&&d>=2){
            win=win&&g(a-2, b-1, c, d-2, !turn);
            m=1;
        }
        if(a>=1&&b>=1&&c>=1&&d>=1){
            win=win&&g(a-1, b-1, c-1, d-1, !turn);
            m=1;
        }
        if(c>=2&&d>=1){
            win=win&&g(a, b, c-2, d-1, !turn);
            m=1;
        }
        if(b>=3){
            win=win&&g(a, b-3, c, d, !turn);
            m=1;
        }
        if(a>=1&&d>=1){
            win=win&&g(a-1, b, c, d-1, !turn);
            m=1;
        }
        if(win){
            dp[a][b][c][d]=0;
        }
        else{
            dp[a][b][c][d]=1;
        }
        return !dp[a][b][c][d];
    }
}

int main()
{
    memset(dp, -1, sizeof(dp));
    dp[2][1][0][2]=1;
    dp[1][1][1][1]=1;
    dp[0][0][2][1]=1;
    dp[0][3][0][0]=1;
    dp[1][0][0][1]=1;
    int n;
    cin >> n;
    while(n--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(g(a, b, c, d, 1)){
            cout << "Patrick" << endl;
        }
        else{
            cout << "Roland" << endl;
        }
    }
    return 0;
}
